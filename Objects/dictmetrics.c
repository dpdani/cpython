#include "stdio.h"
#include "errno.h"
#include "time.h"
#include "stdlib.h"
#include "dictmetrics.h"


struct dict_metrics_t
        dict_metrics[] = {
        {"dictresize",                               0, 0, 0, 0, 0},  // 0
        {"dict_iter",                                0, 0, 0, 0, 0},  // 1
        {"_PyDict_ClearFreeList",                    0, 0, 0, 0, 0},  // 2
        {"_PyDict_Fini",                             0, 0, 0, 0, 0},  // 3
        {"unicode_get_hash",                         0, 0, 0, 0, 0},  // 4
        {"_PyDict_DebugMallocStats",                 0, 0, 0, 0, 0},  // 5
        {"free_keys_object",                         0, 0, 0, 0, 0},  // 6
        {"dictkeys_incref",                          0, 0, 0, 0, 0},  // 7
        {"dictkeys_decref",                          0, 0, 0, 0, 0},  // 8
        {"dictkeys_get_index",                       0, 0, 0, 0, 0},  // 9
        {"dictkeys_set_index",                       0, 0, 0, 0, 0},  // 10
        {"calculate_log2_keysize",                   0, 0, 0, 0, 0},  // 11
        {"estimate_log2_keysize",                    0, 0, 0, 0, 0},  // 12
        {"get_index_from_order",                     0, 0, 0, 0, 0},  // 13
        {"_PyDict_CheckConsistency",                 0, 0, 0, 0, 0},  // 14
        {"new_keys_object",                          0, 0, 0, 0, 0},  // 15
        {"new_values",                               0, 0, 0, 0, 0},  // 16
        {"free_values",                              0, 0, 0, 0, 0},  // 17
        {"new_dict",                                 0, 0, 0, 0, 0},  // 18
        {"shared_keys_usable_size",                  0, 0, 0, 0, 0},  // 19
        {"new_dict_with_shared_keys",                0, 0, 0, 0, 0},  // 20
        {"clone_combined_dict_keys",                 0, 0, 0, 0, 0},  // 21
        {"PyDict_New",                               0, 0, 0, 0, 0},  // 22
        {"lookdict_index",                           0, 0, 0, 0, 0},  // 23
        {"unicodekeys_lookup_generic",               0, 0, 0, 0, 0},  // 24
        {"unicodekeys_lookup_unicode",               0, 0, 0, 0, 0},  // 25
        {"dictkeys_generic_lookup",                  0, 0, 0, 0, 0},  // 26
        {"_PyDictKeys_StringLookup",                 0, 0, 0, 0, 0},  // 27
        {"_Py_dict_lookup",                          0, 0, 0, 0, 0},  // 28
        {"_PyDict_HasOnlyStringKeys",                0, 0, 0, 0, 0},  // 29
        {"_PyDict_MaybeUntrack",                     0, 0, 0, 0, 0},  // 30
        {"find_empty_slot",                          0, 0, 0, 0, 0},  // 31
        {"insertion_resize",                         0, 0, 0, 0, 0},  // 32
        {"insert_into_dictkeys",                     0, 0, 0, 0, 0},  // 33
        {"insertdict",                               0, 0, 0, 0, 0},  // 34
        {"insert_to_emptydict",                      0, 0, 0, 0, 0},  // 35
        {"build_indices_generic",                    0, 0, 0, 0, 0},  // 36
        {"build_indices_unicode",                    0, 0, 0, 0, 0},  // 37
        {"dict_new_presized",                        0, 0, 0, 0, 0},  // 38
        {"_PyDict_NewPresized",                      0, 0, 0, 0, 0},  // 39
        {"_PyDict_FromItems",                        0, 0, 0, 0, 0},  // 40
        {"PyDict_GetItem",                           0, 0, 0, 0, 0},  // 41
        {"_PyDict_GetItemHint",                      0, 0, 0, 0, 0},  // 42
        {"_PyDict_GetItem_KnownHash",                0, 0, 0, 0, 0},  // 43
        {"PyDict_GetItemWithError",                  0, 0, 0, 0, 0},  // 44
        {"_PyDict_GetItemWithError",                 0, 0, 0, 0, 0},  // 45
        {"_PyDict_GetItemIdWithError",               0, 0, 0, 0, 0},  // 46
        {"_PyDict_GetItemStringWithError",           0, 0, 0, 0, 0},  // 47
        {"_PyDict_LoadGlobal",                       0, 0, 0, 0, 0},  // 48
        {"_PyDict_SetItem_Take2",                    0, 0, 0, 0, 0},  // 49
        {"PyDict_SetItem",                           0, 0, 0, 0, 0},  // 50
        {"_PyDict_SetItem_KnownHash",                0, 0, 0, 0, 0},  // 51
        {"delete_index_from_values",                 0, 0, 0, 0, 0},  // 52
        {"delitem_common",                           0, 0, 0, 0, 0},  // 53
        {"PyDict_DelItem",                           0, 0, 0, 0, 0},  // 54
        {"_PyDict_DelItem_KnownHash",                0, 0, 0, 0, 0},  // 55
        {"_PyDict_DelItemIf",                        0, 0, 0, 0, 0},  // 56
        {"PyDict_Clear",                             0, 0, 0, 0, 0},  // 57
        {"_PyDict_Next",                             0, 0, 0, 0, 0},  // 58
        {"PyDict_Next",                              0, 0, 0, 0, 0},  // 59
        {"_PyDict_Pop_KnownHash",                    0, 0, 0, 0, 0},  // 60
        {"_PyDict_Pop",                              0, 0, 0, 0, 0},  // 61
        {"_PyDict_FromKeys",                         0, 0, 0, 0, 0},  // 62
        {"dict_dealloc",                             0, 0, 0, 0, 0},  // 63
        {"dict_repr",                                0, 0, 0, 0, 0},  // 64
        {"dict_length",                              0, 0, 0, 0, 0},  // 65
        {"dict_subscript",                           0, 0, 0, 0, 0},  // 66
        {"dict_ass_sub",                             0, 0, 0, 0, 0},  // 67
        {"dict_keys",                                0, 0, 0, 0, 0},  // 68
        {"dict_values",                              0, 0, 0, 0, 0},  // 69
        {"dict_items",                               0, 0, 0, 0, 0},  // 70
        {"dict_fromkeys_impl",                       0, 0, 0, 0, 0},  // 71
        {"dict_update_arg",                          0, 0, 0, 0, 0},  // 72
        {"dict_update_common",                       0, 0, 0, 0, 0},  // 73
        {"dict_update",                              0, 0, 0, 0, 0},  // 74
        {"PyDict_MergeFromSeq2",                     0, 0, 0, 0, 0},  // 75
        {"dict_merge",                               0, 0, 0, 0, 0},  // 76
        {"PyDict_Update",                            0, 0, 0, 0, 0},  // 77
        {"PyDict_Merge",                             0, 0, 0, 0, 0},  // 78
        {"_PyDict_MergeEx",                          0, 0, 0, 0, 0},  // 79
        {"dict_copy",                                0, 0, 0, 0, 0},  // 80
        {"PyDict_Copy",                              0, 0, 0, 0, 0},  // 81
        {"PyDict_Size",                              0, 0, 0, 0, 0},  // 82
        {"PyDict_Keys",                              0, 0, 0, 0, 0},  // 83
        {"PyDict_Values",                            0, 0, 0, 0, 0},  // 84
        {"PyDict_Items",                             0, 0, 0, 0, 0},  // 85
        {"dict_equal",                               0, 0, 0, 0, 0},  // 86
        {"dict_richcompare",                         0, 0, 0, 0, 0},  // 87
        {"dict___contains__",                        0, 0, 0, 0, 0},  // 88
        {"dict_get_impl",                            0, 0, 0, 0, 0},  // 89
        {"PyDict_SetDefault",                        0, 0, 0, 0, 0},  // 90
        {"dict_setdefault_impl",                     0, 0, 0, 0, 0},  // 91
        {"dict_clear",                               0, 0, 0, 0, 0},  // 92
        {"dict_pop_impl",                            0, 0, 0, 0, 0},  // 93
        {"dict_popitem_impl",                        0, 0, 0, 0, 0},  // 94
        {"dict_traverse",                            0, 0, 0, 0, 0},  // 95
        {"dict_tp_clear",                            0, 0, 0, 0, 0},  // 96
        {"_PyDict_SizeOf",                           0, 0, 0, 0, 0},  // 97
        {"_PyDict_KeysSize",                         0, 0, 0, 0, 0},  // 98
        {"dict_sizeof",                              0, 0, 0, 0, 0},  // 99
        {"dict_or",                                  0, 0, 0, 0, 0},  // 100
        {"dict_ior",                                 0, 0, 0, 0, 0},  // 101
        {"PyDict_Contains",                          0, 0, 0, 0, 0},  // 102
        {"_PyDict_Contains_KnownHash",               0, 0, 0, 0, 0},  // 103
        {"_PyDict_ContainsId",                       0, 0, 0, 0, 0},  // 104
        {"dict_new",                                 0, 0, 0, 0, 0},  // 105
        {"dict_init",                                0, 0, 0, 0, 0},  // 106
        {"dict_vectorcall",                          0, 0, 0, 0, 0},  // 107
        {"dictiter_new",                             0, 0, 0, 0, 0},  // 108
        {"dictiter_dealloc",                         0, 0, 0, 0, 0},  // 109
        {"dictiter_traverse",                        0, 0, 0, 0, 0},  // 110
        {"dictiter_len",                             0, 0, 0, 0, 0},  // 111
        {"dictiter_reduce",                          0, 0, 0, 0, 0},  // 112
        {"dictiter_iternextkey",                     0, 0, 0, 0, 0},  // 113
        {"dictiter_iternextvalue",                   0, 0, 0, 0, 0},  // 114
        {"dictiter_iternextitem",                    0, 0, 0, 0, 0},  // 115
        {"dictreviter_iternext",                     0, 0, 0, 0, 0},  // 116
        {"dict___reversed___impl",                   0, 0, 0, 0, 0},  // 117
        {"dictview_dealloc",                         0, 0, 0, 0, 0},  // 118
        {"dictview_traverse",                        0, 0, 0, 0, 0},  // 119
        {"dictview_len",                             0, 0, 0, 0, 0},  // 120
        {"_PyDictView_New",                          0, 0, 0, 0, 0},  // 121
        {"dictview_mapping",                         0, 0, 0, 0, 0},  // 122
        {"all_contained_in",                         0, 0, 0, 0, 0},  // 123
        {"dictview_richcompare",                     0, 0, 0, 0, 0},  // 124
        {"dictview_repr",                            0, 0, 0, 0, 0},  // 125
        {"dictkeys_iter",                            0, 0, 0, 0, 0},  // 126
        {"dictkeys_contains",                        0, 0, 0, 0, 0},  // 127
        {"dictviews_to_set",                         0, 0, 0, 0, 0},  // 128
        {"dictviews_sub",                            0, 0, 0, 0, 0},  // 129
        {"dictitems_contains",                       0, 0, 0, 0, 0},  // 130
        {"_PyDictView_Intersect",                    0, 0, 0, 0, 0},  // 131
        {"dictviews_or",                             0, 0, 0, 0, 0},  // 132
        {"dictitems_xor",                            0, 0, 0, 0, 0},  // 133
        {"dictviews_xor",                            0, 0, 0, 0, 0},  // 134
        {"dictviews_isdisjoint",                     0, 0, 0, 0, 0},  // 135
        {"dictkeys_new",                             0, 0, 0, 0, 0},  // 136
        {"dictkeys_reversed",                        0, 0, 0, 0, 0},  // 137
        {"dictitems_iter",                           0, 0, 0, 0, 0},  // 138
        {"dictitems_new",                            0, 0, 0, 0, 0},  // 139
        {"dictitems_reversed",                       0, 0, 0, 0, 0},  // 140
        {"dictvalues_iter",                          0, 0, 0, 0, 0},  // 141
        {"dictvalues_new",                           0, 0, 0, 0, 0},  // 142
        {"dictvalues_reversed",                      0, 0, 0, 0, 0},  // 143
        {"_PyDict_NewKeysForClass",                  0, 0, 0, 0, 0},  // 144
        {"init_inline_values",                       0, 0, 0, 0, 0},  // 145
        {"_PyObject_InitializeDict",                 0, 0, 0, 0, 0},  // 146
        {"make_dict_from_instance_attributes",       0, 0, 0, 0, 0},  // 147
        {"_PyObject_MakeDictFromInstanceAttributes", 0, 0, 0, 0, 0},  // 148
        {"_PyObject_StoreInstanceAttribute",         0, 0, 0, 0, 0},  // 149
        {"_PyObject_GetInstanceAttribute",           0, 0, 0, 0, 0},  // 150
        {"_PyObject_IsInstanceDictEmpty",            0, 0, 0, 0, 0},  // 151
        {"_PyObject_VisitInstanceAttributes",        0, 0, 0, 0, 0},  // 152
        {"_PyObject_ClearInstanceAttributes",        0, 0, 0, 0, 0},  // 153
        {"_PyObject_FreeInstanceAttributes",         0, 0, 0, 0, 0},  // 154
        {"PyObject_GenericGetDict",                  0, 0, 0, 0, 0},  // 155
        {"_PyObjectDict_SetItem",                    0, 0, 0, 0, 0},  // 156
        {"_PyDictKeys_DecRef",                       0, 0, 0, 0, 0},  // 157
        {"_PyDictKeys_GetVersionForCurrentState",    0, 0, 0, 0, 0},  // 158
        /* For backward compatibility with old dictionary interface */
        {"PyDict_GetItemString",                     0, 0, 0, 0, 0},  // 159
        {"_PyDict_SetItemId",                        0, 0, 0, 0, 0},  // 160
        {"PyDict_SetItemString",                     0, 0, 0, 0, 0},  // 161
        {"_PyDict_DelItemId",                        0, 0, 0, 0, 0},  // 162
        {"PyDict_DelItemString",                     0, 0, 0, 0, 0},  // 163
        {"\0",                                       0, 0, 0, 0, 0}
};

void
print_dict_metrics() {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    char *date = malloc(50);
    char *fname = malloc(100);
    strftime(date, 50, "%Y-%m-%d_%H-%M-%S", gmtime(&ts.tv_sec));
    sprintf(fname, "dict-metrics_%s_%ld.csv", date, ts.tv_nsec);

    FILE *out = fopen(fname, "w");

    if (out == NULL) {
        fprintf(stderr, "out is null! errno: %d", errno);
        return;
    }

    fprintf(out, "method, usage count, total time, extra 1, extra 2, extra 3\n");
    int i = 0;
    do {
        fprintf(out, "%s, %lu, %lu, %lu, %lu, %lu\n",
                dict_metrics[i].name,
                dict_metrics[i].usages,
                dict_metrics[i].total_time,
                dict_metrics[i].extra_1,
                dict_metrics[i].extra_2,
                dict_metrics[i].extra_3);
        i++;
    } while (dict_metrics[i].name[0] != '\0');

    fclose(out);
    free(date);
    free(fname);
}

unsigned long
elapsed(struct timespec start)
{
    struct timespec end;
    timespec_get(&end, TIME_UTC);

    return end.tv_sec * 1000000000UL + end.tv_nsec - start.tv_sec * 1000000000UL - start.tv_nsec;
}
