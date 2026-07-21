GNU General Public License v3.0 or later
========================================

Copyright (c) 2026, pihchikk and contributors

This distribution as a whole is licensed under the GNU General Public License,
version 3.0 or (at your option) any later version (GPL-3.0-or-later).

**Why GPL-3.0:** the ``bmi_lisem`` package vendors and statically links the
complete OpenLISEM hydrological model (``openlisem_bmi/``), which is licensed
under the GNU General Public License v3.0 (see ``openlisem_bmi/GPL-v3.0.txt``).
A work that links OpenLISEM is a derivative work, so the combined/distributed
package is covered by the GPL-3.0.

The full license text is in ``openlisem_bmi/GPL-v3.0.txt`` and at
<https://www.gnu.org/licenses/gpl-3.0.txt>.

Original glue code
------------------

The original BMI glue code authored for this repository (the ``BmiLisem``
wrapper, the babelizer configuration, tests, and documentation — i.e. the parts
that are **not** vendored OpenLISEM) may additionally be used by its authors
under the terms of the MIT License; see ``LICENSE-MIT``. However, because the
built and distributed package links OpenLISEM, the package as distributed is
governed by the GPL-3.0.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.
