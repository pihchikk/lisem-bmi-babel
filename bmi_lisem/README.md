# bmi_lisem (planned)

Нативный C++ BMI для OpenLISEM по образцу AquaCrop (C++ bmi::Bmi → Cython → Python).
Будет оборачивать модель из ../openlisem_bmi/model. Слои: bmi_lisem.cxx/.h (реализация
bmi::Bmi поверх refactored TWorld), babelizer-генерируемая Cython+Python обвязка.
Заполняется на фазе 3 (расщепление DoModel → Initialize/Update/Finalize).
