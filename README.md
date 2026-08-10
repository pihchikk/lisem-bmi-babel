# bmi_lisem

Python/BMI-обёртка над движком OpenLISEM (поверхностный сток, инфильтрация,
эрозия) для физически связанного моделирования (в первую очередь — с
AquaCrop). Полное описание, вся терминология и таблицы переменных — в
[`README.en.rst`](README.en.rst) (на английском); этот файл — только
быстрый старт: как запустить, где взять тестовые данные, как устроен
каталог с данными.

## Установка

Установка в два шага: сначала собирается нативная библиотека
(`openlisem_bmi/`, это C++/Qt/GDAL-код, не Python), потом уже поверх неё
ставится Python-пакет. Одним `pip install` не обойтись — библиотеку `pip`
сам не соберёт.

### Шаг 1. Системные зависимости

На Debian/Ubuntu:

```bash
sudo apt install cmake ninja-build g++ libgdal-dev qt6-base-dev libqwt-qt6-dev
```

- **CMake + ninja/make + компилятор с C++17** — собирают саму библиотеку.
- **GDAL** (`libgdal-dev`) — чтение/запись растров.
- **Qt 6** (`qt6-base-dev`: Core, Gui, Widgets, Network) и **QWT**
  (`libqwt-qt6-dev`) — нужны для сборки движка OpenLISEM как есть (см. ниже
  про headless-сборку, если GUI-часть не нужна). QWT иногда ставится не по
  стандартному пути, тогда сборке нужно явно указать префикс (например,
  `/usr/local/qwt-6.4.0-ma`).

### Шаг 2. Сборка нативной библиотеки

```bash
cd openlisem_bmi
cmake -S . -B build
cmake --build build -j4
# результат: build/libbmilisem.so и build/bmilisem.pc (pkg-config файл)
```

Чтобы Python-пакет на следующем шаге нашёл собранную библиотеку:

```bash
export LD_LIBRARY_PATH="$PWD/build:$LD_LIBRARY_PATH"
export PKG_CONFIG_PATH="$PWD/build:$PKG_CONFIG_PATH"
```

Если Qt/QWT/OpenGL не нужны (сервер, контейнер) — можно собрать движок без
GUI-стека, что сильно сокращает набор зависимостей и итоговый размер:

```bash
cmake -S . -B build -DBMI_HEADLESS=ON
cmake --build build -j4
```

На работу BMI это не влияет — модель всегда запускается в режиме без
интерфейса (`noInterface = true`).

### Шаг 3. Python-пакет

Из корня репозитория (не из `openlisem_bmi/`):

```bash
cd ..
pip install --no-build-isolation .
```

`--no-build-isolation` обязателен (так собирается проект — см.
`docs/BUILDING.md`).

Обычная (не editable) установка — рекомендуемый вариант. При `pip install
--editable .` исходники `bmi_lisem/` перекрывают собранное расширение на
пути импорта, и `from bmi_lisem import Lisem` возьмёт "пустой" Python-класс
вместо скомпилированного. Если editable-установка всё же нужна — запускать
код не из корня репозитория, а из любой другой директории.

Подробности и диагностика — в `docs/BUILDING.md`.

## Быстрый старт: запуск на датасете VNIIMZ_20m

В пакете уже есть один полностью готовый к запуску реальный датасет —
`VNIIMZ_20m`. Собственный runfile для него не нужен, скачивать данные
отдельно тоже не нужно — всё уже лежит внутри пакета. Что это за датасет:

- реальный, измеренный водосбор, растровая сетка 204×89 ячеек, из них 6 821
  ячейка действительно внутри водосбора (остальное — обрамление
  прямоугольной сетки);
- разрешение растров — 20×20 м на ячейку (отсюда и название);
- один реальный ливень (файл `rain.txt`, ~12 часов);
- инфильтрация по схеме Грин—Эмпта/Смит—Парланжа (`Infil Method=3`), 2
  почвенных слоя;
- эрозия включена; эвапотранспирация и перехват осадков растительностью —
  выключены (`Include ET=0`, `Include Interception=0`).

Запуск:

```python
import numpy as np
from bmi_lisem import Lisem
from bmi_lisem.scenarios import default_scenario_runfile

# default_scenario_runfile() сам находит данные VNIIMZ_20m (в установленном
# пакете либо в исходниках — см. ниже), подставляет в шаблон runfile реальные
# абсолютные пути и возвращает путь к готовому runfile.
runfile = default_scenario_runfile()
model = Lisem()
model.initialize(runfile)

# Полный прогон события — от начала до конца, шаг за шагом:
end = model.get_end_time()
while model.get_current_time() < end - 1e-9:
    model.update()

# Пример чтения результата — накопленная инфильтрация (м) по растру:
n = model.get_grid_size(model.get_var_grid("soil_infiltration~amount"))
fcum = np.empty(n, dtype=np.float64)
model.get_value("soil_infiltration~amount", fcum)

model.finalize()
```

`default_scenario_runfile(result_dir=...)` принимает необязательный
аргумент — куда OpenLISEM будет писать собственные отчёты (`totals.csv`,
растры по шагам и т.д.); если не указать, создаётся временная директория.

## Как устроен каталог с данными VNIIMZ_20m

Датасет ставится вместе с пакетом и лежит внутри установленного `bmi_lisem`
по пути `bmi_lisem/data/Lisem/vniimz_20m/` (meson-сборка сохраняет базовое
имя `Lisem`, поэтому путь не сокращается до `bmi_lisem/data/vniimz_20m/`).
При работе из исходников репозитория (не из установленного пакета) те же
файлы лежат в `meta/Lisem/vniimz_20m/`. Содержимое ровно одно и то же,
просто два места, где его ищет `default_scenario_runfile()` — сначала
установленный пакет, потом (если не найдено) исходники.

```
vniimz_20m/
├── maps/                       # 50 растров PCRaster (.map), реальные
│                                # измеренные данные:
│                                #   dem.map, demcorr.map, demadj.map — рельеф
│                                #   ldd.map — направления стока (local drain direction)
│                                #   ID.map, outlet.map, outpoint.map — водосбор/выпуск
│                                #   ksat1.map, ksat2.map — водопроницаемость, 2 слоя
│                                #   thetai1.map, thetai2.map — начальная влажность
│                                #   thetas1.map, thetas2.map — пористость (насыщение)
│                                #   soildep1.map, soilDep2.map — мощность слоёв
│                                #   coh.map, cohadd.map, chancoh.map — сцепление (эрозия)
│                                #   landuse.map, landunit.map, lai.map — землепользование
│                                #   grad.map, rr.map, n.map — уклон, шероховатость
│                                #   ...и другие карты, которые читает именно эта
│                                #   конфигурация (не весь набор, который в принципе
│                                #   умеет читать OpenLISEM)
├── rain.txt                    # таблица осадков — один реальный ливень
├── run_test.run.template       # шаблон runfile (текстовый, ключ=значение),
│                                # с плейсхолдерами {MAP_DIR} / {RAIN_DIR} /
│                                # {RESULT_DIR} вместо трёх абсолютных путей,
│                                # которые требует формат runfile OpenLISEM.
│                                # Использовать напрямую (в initialize())
│                                # нельзя — плейсхолдеры не подставлены;
│                                # только через default_scenario_runfile()
└── README.md                   # происхождение и курация датасета
```

Чтобы прогнать модель на СВОИХ данных вместо `VNIIMZ_20m`, никакой особой
структуры каталогов заводить не нужно — `bmi_lisem` работает с любым
готовым runfile напрямую:

```python
model.initialize("/абс/путь/к/своему.run")
```

Runfile OpenLISEM ссылается на карты по путям — если они не абсолютные, они
разрешаются относительно рабочей директории процесса, а не местоположения
самого runfile (ровно то, что `default_scenario_runfile()` для `VNIIMZ_20m`
делает автоматически).

## Как запускать тесты

```bash
scripts/run_local_tests.sh
```

Этот скрипт сам настраивает всё необходимое: `LD_LIBRARY_PATH` на собранную
`libbmilisem.so`, `LISEM_TEST_RUNFILE` — на встроенный датасет `vniimz_20m`
(если не задан явно), и запускает тесты из копии `bmi_lisem/tests/` вне
репозитория, чтобы `import bmi_lisem` брал установленный пакет со
скомпилированным расширением, а не исходники (подробности — в
`docs/BUILDING.md`, раздел про "shadowing").

Чтобы прогнать тесты на другом датасете — своём или большего масштаба —
достаточно задать `LISEM_TEST_RUNFILE` (у этой переменной всегда приоритет
над встроенным датасетом):

```bash
LISEM_TEST_RUNFILE=/абс/путь/к/своему.run scripts/run_local_tests.sh -v
```

`pcraster` для запуска тестов не нужен — все `.map`-файлы уже собраны и
закоммичены как есть.
