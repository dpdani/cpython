# Collecting metrics on built-in dictionary usage

This repository contains a modified version of the CPython 3.11.4 interpreter
(see [README_cpython.rst](./README_cpython.rst)).

All the dictionary routines in [dictobject.c](./Objects/dictobject.c) are modified
to keep track of the number of calls and the total running time for each method
inside the `dict_metrics` global table (see [dictmetrics.c](./Objects/dictmetrics.c)).

Several methods also include extra information:

| method                           | extra 1               | extra 2           | extra 3                 |
|----------------------------------|-----------------------|-------------------|-------------------------|
| `dictkeys_get_index`             | successful count      | failing count     |                         |
| `_Py_dict_lookup`                | successful count      | failing count     |                         |
| `unicodekeys_lookup_unicode`     | successful count      | failing count     |                         |
| `PyDict_GetItemWithError`        | successful count      | failing count     |                         |
| `_PyDictKeys_StringLookup`       | successful count      | failing count     |                         |
| `dictkeys_generic_lookup`        | successful count      | failing count     |                         |
| `insertdict`                     | successful count [^1] | update count [^2] | triggered resizes count |
| `_PyObject_GetInstanceAttribute` | successful count      |                   |                         |
| `_PyDict_GetItemHint`            | successful count      | failing count     |                         |
| `PyDict_Contains`                | successful count      | failing count     |                         |
| `_PyDict_GetItem_KnownHash`      | successful count      | failing count     |                         |
| `_PyDict_DelItem_KnownHash`      | successful count      | failing count     |                         |
| `dict_get_impl`                  | successful count      |                   |                         |
| `_PyDict_LoadGlobal`             | successful count      | failing count     |                         |
| `PyDict_GetItem`                 | successful count      | failing count     |                         |
| `_PyDict_KeysSize`               | average size          |                   |                         |
| `PyObject_GenericGetDict`        | successful count      |                   |                         |
| `_PyDict_GetItemStringWithError` | successful count      | failing count     |                         |
| `_PyDict_MaybeUntrack`           | untracked count       |                   |                         |
| `PyDict_Size`                    | average size          |                   |                         |
| `unicodekeys_lookup_generic`     | successful count      | failing count     |                         |
| `shared_keys_usable_size`        | average size          |                   |                         |
| `_PyDict_HasOnlyStringKeys`      | return true           | return false      |                         |
| `estimate_log2_keysize`          | average size          |                   |                         |
| `calculate_log2_keysize`         | average size          |                   |                         |
| `dict_new_presized`              | average pre-size      |                   |                         |
| `_PyDict_SizeOf`                 | average size          |                   |                         |
| `dict_sizeof`                    | average size          |                   |                         |

[^1]: in this context success means non-occurrance of errors during the initial lookup (need to know whether to update
an already existing entry), or during resize. From the data collected, no errors occurred.

[^2]: `insertdict` may either insert a new entry into the hash table, or *update* the value of an existing one.
