=========
bmi_lisem
=========

.. image:: https://img.shields.io/badge/CSDMS-Basic%20Model%20Interface-green.svg
        :target: https://bmi.readthedocs.io/
        :alt: Basic Model Interface

.. image:: https://img.shields.io/badge/standard%20names-ESoil%20%2F%20ЕСОМОД-blue.svg
        :alt: ESoil standard names

BMI 2.0 обёртка для **OpenLISEM** (2D модель поверхностного стока и эрозии),
сгенерированная `babelizer <https://babelizer.readthedocs.io>`_ поверх нативной
C++ реализации ``BmiLisem`` (``libbmilisem.so``). Пакет позволяет управлять
OpenLISEM из Python и связывать его с другими моделями (например, AquaCrop)
через PyMT по стандартным именам переменных.

Часть системы **Цифровой двойник почвы (ЦДП)**: LISEM даёт поверхность,
инфильтрацию и эрозию по клеткам; связанная модель AquaCrop разносит воду по
глубине профиля. Репозиторий устроен единообразно с ``aquacrop-bmi``:
корень репозитория — это сам babelize-проект, нативный код — в подкаталоге
``openlisem_bmi/``.

.. start-intro

.. list-table::
  :header-rows: 1
  :width: 90%
  :widths: auto

  * - Библиотека
    - Компонент
    - PyMT
  * - bmilisem
    - :class:`~bmi_lisem.Lisem`
    -
      .. code-block:: pycon

        >>> from pymt.models import Lisem

.. end-intro

* Лицензия: MIT
* Исходники: https://github.com/pihchikk/lisem-bmi-babel
* Стандартные имена: конвенция ЕСОМОД (``object_property~qualifier``); старые
  CSDMS-имена (``object__property``) принимаются как алиасы (см. раздел
  «Стандартные имена»).


Стандартные имена переменных
============================

.. start-standard-names

``get_output_var_names()`` / ``get_input_var_names()`` возвращают **только
канонические ESoil-имена**. На вход (``get_value``/``set_value``/``get_var_units``
и т.д.) принимаются **и** новые ESoil-имена, **и** старые CSDMS — их разрешает
alias-слой ``resolveVarAlias`` в нативном C++ (``openlisem_bmi/bmi_lisem/BmiLisem.cpp``).
Так что переименование имён не требует регенерации Python-обёртки: имена живут
в скомпилированной ``libbmilisem.so``.

Примеры соответствий (полная таблица — в ``bmi_lisem/docs/STANDARD_NAMES_ALIASES.md``):

.. list-table::
  :header-rows: 1
  :widths: auto

  * - CSDMS (алиас, принимается)
    - ЕСОМОД (каноническое, выдаётся)
  * - ``soil_water__volume_fraction``
    - ``soil_water_actual``
  * - ``land_vegetation__cover_fraction``
    - ``plant_cover~projective``
  * - ``soil_water__volume_fraction_in_layer_1..3``
    - ``soil_water_actual_layer-1..-3``
  * - ``land_surface_water__depth``
    - ``surface-water~depth``
  * - ``soil_water__infiltration_depth``
    - ``soil_infiltration~amount``
  * - ``soil__erosion_mass_per_area``
    - ``soil_erosion~mass-per-area``

Коуплинг-критичные имена (``soil_water_actual``, ``plant_cover~projective``,
``soil_water_actual_layer-N``) совпадают с ``aquacrop-bmi`` — это обеспечивает
автоматическую связку через PyMT-медиатор.

.. end-standard-names


Нативные зависимости
====================

.. start-native-deps

В отличие от типового babelizer-пакета, OpenLISEM тянет тяжёлые нативные
библиотеки. Для сборки из исходников и для запуска нужны:

* **Qt6** (Core, Gui, Widgets, Network)
* **GDAL**
* **QWT** — кастомный форк ``qwt-multiaxes-qt6`` (лежит в истории репозитория)
* **OpenMP**, **GL** (libGL/libGLX/libOpenGL) — GL-либы предоставляет система

Установка системных зависимостей (Ubuntu 22.04/24.04):

.. code:: bash

  sudo apt-get update
  sudo apt-get install -y qt6-base-dev qt6-base-dev-tools libqt6opengl6-dev \
      libgdal-dev gdal-bin gfortran cmake pkg-config make git python3-dev patchelf

**При установке из готового wheel** (PyPI/TestPyPI) большинство ``.so`` уже
забандлены ``auditwheel``, но GL-либы исключены по политике manylinux — их надо
доставить в систему:

.. code:: bash

  sudo apt-get install -y libopengl0 libglx0 libgl1 libegl1

.. end-native-deps


Установка
=========

.. start-quickstart

Из wheel (быстро)
-----------------

.. code:: bash

  pip install bmi_lisem
  # если ставишь из TestPyPI:
  # pip install -i https://test.pypi.org/simple/ --extra-index-url https://pypi.org/simple/ bmi_lisem

Затем доставь GL-либы (см. «Нативные зависимости») и проверь импорт **из другого
каталога**, чтобы исходная папка не затеняла установленное колесо:

.. code:: bash

  cd /tmp
  python -c "import bmi_lisem; from bmi_lisem import Lisem; print('OK:', bmi_lisem.__file__)"

Из исходников
-------------

Сначала собери нативную ``libbmilisem.so`` и создай для неё pkg-config файл
``bmilisem.pc`` (meson находит либу через pkg-config):

.. code:: bash

  # 1) собрать QWT-форк из истории репо
  git checkout <qwt_commit>~1 -- qwt-multiaxes-qt6
  ( cd qwt-multiaxes-qt6 && qmake6 qwt.pro && make -j4 && sudo make install )

  # 2) собрать нативный LISEM (важен флаг против утечки Qt6 genex)
  cmake -S openlisem_bmi -B openlisem_bmi/build \
        -DCMAKE_BUILD_TYPE=Release -DCMAKE_DEPENDS_USE_COMPILER=OFF
  make -C openlisem_bmi/build -j4        # -> libbmilisem.so

  # 3) создать bmilisem.pc и положить на PKG_CONFIG_PATH (Cflags -I на openlisem_bmi/bmi_lisem)

  # 4) поставить пакет NON-editable (editable-loader ребилдит на импорте и падает)
  export PKG_CONFIG_PATH=/path/to/pkgconfig:$PKG_CONFIG_PATH
  pip install . --no-build-isolation

.. warning::

  **Не используй** ``pip install --editable .`` для этого пакета: meson-python
  editable-loader пересобирает расширение при импорте и падает в подпроцессах.
  Ставь non-editable и проверяй импорт из ``/tmp``.

.. end-quickstart


Использование
=============

.. start-usage

Компоненты доступны напрямую через BMI (:class:`~bmi_lisem.Lisem`) или как
PyMT-плагин.

.. code-block:: pycon

  >>> from bmi_lisem import Lisem
  >>> model = Lisem()
  >>> model.initialize("VNIIMZ_20m/maps/probnik_20m.run")
  >>> model.get_output_var_names()   # канонические ESoil-имена
  >>> import numpy as np
  >>> n = model.get_grid_size(model.get_var_grid("soil_water_actual"))
  >>> buf = np.empty(n); model.get_value("soil_water_actual", buf)
  >>> model.finalize()

Через PyMT:

.. code-block:: pycon

  >>> from pymt.models import Lisem
  >>> model = Lisem()
  >>> model.output_var_names

Входные данные
--------------

Пакет содержит только код обёртки — **данных в нём нет**. Для реального прогона
нужен LISEM runfile (``*.run``) и все карты (``*.map``), на которые он ссылается,
плюс ``rain.txt``.

.. warning::

  Пути в runfile (``Map Directory=``, ``Rainfall Directory=``, ``Result Directory=``)
  часто **абсолютные** и указывают на машину, где датасет готовили. На другой
  машине их нужно переписать под фактическое расположение, иначе ``initialize``
  упадёт с «map/rain not found». Простейший способ — переписать три пути на
  абсолютные от каталога с runfile перед вызовом ``initialize``.

.. note::

  Для использования через PyMT сначала установи PyMT:
  ``mamba install pymt -c conda-forge`` или ``conda install pymt -c conda-forge``.

.. end-usage


Обновление (регенерация babelizer)
==================================

.. start-updating

Python-обёртка сгенерирована `babelizer <https://babelizer.readthedocs.io>`_.
Регенерация нужна **только** если меняется C-ABI нативного BMI (набор/сигнатуры
BMI-методов). Изменения стандартных имён/алиасов/coupling-переменных живут в
C++ и **не требуют** регенерации — достаточно пересобрать ``libbmilisem.so``.

.. warning::

  Многие файлы автогенерированы babelizer'ом; ручные правки в них будут потеряны
  после ре-рендера.

.. code:: bash

  babelize update    # или: nox -s update

.. end-updating
