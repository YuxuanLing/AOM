/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#include "entropymode.h"

const unsigned int vp9_kf_default_bmode_counts[VP8_BINTRAMODES][VP8_BINTRAMODES][VP8_BINTRAMODES] = {
  {
    /*Above Mode :  0*/
    { 43438,   2195,    470,    316,    615,    171,    217,    412,    124,    160, }, /* left_mode 0 */
    {  5722,   2751,    296,    291,     81,     68,     80,    101,    100,    170, }, /* left_mode 1 */
    {  1629,    201,    307,     25,     47,     16,     34,     72,     19,     28, }, /* left_mode 2 */
    {   332,    266,     36,    500,     20,     65,     23,     14,    154,    106, }, /* left_mode 3 */
    {   450,     97,     10,     24,    117,     10,      2,     12,      8,     71, }, /* left_mode 4 */
    {   384,     49,     29,     44,     12,    162,     51,      5,     87,     42, }, /* left_mode 5 */
    {   495,     53,    157,     27,     14,     57,    180,     17,     17,     34, }, /* left_mode 6 */
    {   695,     64,     62,      9,     27,      5,      3,    147,     10,     26, }, /* left_mode 7 */
    {   230,     54,     20,    124,     16,    125,     29,     12,    283,     37, }, /* left_mode 8 */
    {   260,     87,     21,    120,     32,     16,     33,     16,     33,    203, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  1*/
    {  3934,   2573,    355,    137,    128,     87,    133,    117,     37,     27, }, /* left_mode 0 */
    {  1036,   1929,    278,    135,     27,     37,     48,     55,     41,     91, }, /* left_mode 1 */
    {   223,    256,    253,     15,     13,      9,     28,     64,      3,      3, }, /* left_mode 2 */
    {   120,    129,     17,    316,     15,     11,      9,      4,     53,     74, }, /* left_mode 3 */
    {   129,     58,      6,     11,     38,      2,      0,      5,      2,     67, }, /* left_mode 4 */
    {    53,     22,     11,     16,      8,     26,     14,      3,     19,     12, }, /* left_mode 5 */
    {    59,     26,     61,     11,      4,      9,     35,     13,      8,      8, }, /* left_mode 6 */
    {   101,     52,     40,      8,      5,      2,      8,     59,      2,     20, }, /* left_mode 7 */
    {    48,     34,     10,     52,      8,     15,      6,      6,     63,     20, }, /* left_mode 8 */
    {    96,     48,     22,     63,     11,     14,      5,      8,      9,     96, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  2*/
    {   709,    461,    506,     36,     27,     33,    151,     98,     24,      6, }, /* left_mode 0 */
    {   201,    375,    442,     27,     13,      8,     46,     58,      6,     19, }, /* left_mode 1 */
    {   122,    140,    417,      4,     13,      3,     33,     59,      4,      2, }, /* left_mode 2 */
    {    36,     17,     22,     16,      6,      8,     12,     17,      9,     21, }, /* left_mode 3 */
    {    51,     15,      7,      1,     14,      0,      4,      5,      3,     22, }, /* left_mode 4 */
    {    18,     11,     30,      9,      7,     20,     11,      5,      2,      6, }, /* left_mode 5 */
    {    38,     21,    103,      9,      4,     12,     79,     13,      2,      5, }, /* left_mode 6 */
    {    64,     17,     66,      2,     12,      4,      2,     65,      4,      5, }, /* left_mode 7 */
    {    14,      7,      7,     16,      3,     11,      4,     13,     15,     16, }, /* left_mode 8 */
    {    36,      8,     32,      9,      9,      4,     14,      7,      6,     24, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  3*/
    {  1340,    173,     36,    119,     30,     10,     13,     10,     20,     26, }, /* left_mode 0 */
    {   156,    293,     26,    108,      5,     16,      2,      4,     23,     30, }, /* left_mode 1 */
    {    60,     34,     13,      7,      3,      3,      0,      8,      4,      5, }, /* left_mode 2 */
    {    72,     64,      1,    235,      3,      9,      2,      7,     28,     38, }, /* left_mode 3 */
    {    29,     14,      1,      3,      5,      0,      2,      2,      5,     13, }, /* left_mode 4 */
    {    22,      7,      4,     11,      2,      5,      1,      2,      6,      4, }, /* left_mode 5 */
    {    18,     14,      5,      6,      4,      3,     14,      0,      9,      2, }, /* left_mode 6 */
    {    41,     10,      7,      1,      2,      0,      0,     10,      2,      1, }, /* left_mode 7 */
    {    23,     19,      2,     33,      1,      5,      2,      0,     51,      8, }, /* left_mode 8 */
    {    33,     26,      7,     53,      3,      9,      3,      3,      9,     19, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  4*/
    {   410,    165,     43,     31,     66,     15,     30,     54,      8,     17, }, /* left_mode 0 */
    {   115,     64,     27,     18,     30,      7,     11,     15,      4,     19, }, /* left_mode 1 */
    {    31,     23,     25,      1,      7,      2,      2,     10,      0,      5, }, /* left_mode 2 */
    {    17,      4,      1,      6,      8,      2,      7,      5,      5,     21, }, /* left_mode 3 */
    {   120,     12,      1,      2,     83,      3,      0,      4,      1,     40, }, /* left_mode 4 */
    {     4,      3,      1,      2,      1,      2,      5,      0,      3,      6, }, /* left_mode 5 */
    {    10,      2,     13,      6,      6,      6,      8,      2,      4,      5, }, /* left_mode 6 */
    {    58,     10,      5,      1,     28,      1,      1,     33,      1,      9, }, /* left_mode 7 */
    {     8,      2,      1,      4,      2,      5,      1,      1,      2,     10, }, /* left_mode 8 */
    {    76,      7,      5,      7,     18,      2,      2,      0,      5,     45, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  5*/
    {   444,     46,     47,     20,     14,    110,     60,     14,     60,      7, }, /* left_mode 0 */
    {    59,     57,     25,     18,      3,     17,     21,      6,     14,      6, }, /* left_mode 1 */
    {    24,     17,     20,      6,      4,     13,      7,      2,      3,      2, }, /* left_mode 2 */
    {    13,     11,      5,     14,      4,      9,      2,      4,     15,      7, }, /* left_mode 3 */
    {     8,      5,      2,      1,      4,      0,      1,      1,      2,     12, }, /* left_mode 4 */
    {    19,      5,      5,      7,      4,     40,      6,      3,     10,      4, }, /* left_mode 5 */
    {    16,      5,      9,      1,      1,     16,     26,      2,     10,      4, }, /* left_mode 6 */
    {    11,      4,      8,      1,      1,      4,      4,      5,      4,      1, }, /* left_mode 7 */
    {    15,      1,      3,      7,      3,     21,      7,      1,     34,      5, }, /* left_mode 8 */
    {    18,      5,      1,      3,      4,      3,      7,      1,      2,      9, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  6*/
    {   476,    149,     94,     13,     14,     77,    291,     27,     23,      3, }, /* left_mode 0 */
    {    79,     83,     42,     14,      2,     12,     63,      2,      4,     14, }, /* left_mode 1 */
    {    43,     36,     55,      1,      3,      8,     42,     11,      5,      1, }, /* left_mode 2 */
    {     9,      9,      6,     16,      1,      5,      6,      3,     11,     10, }, /* left_mode 3 */
    {    10,      3,      1,      3,     10,      1,      0,      1,      1,      4, }, /* left_mode 4 */
    {    14,      6,     15,      5,      1,     20,     25,      2,      5,      0, }, /* left_mode 5 */
    {    28,      7,     51,      1,      0,      8,    127,      6,      2,      5, }, /* left_mode 6 */
    {    13,      3,      3,      2,      3,      1,      2,      8,      1,      2, }, /* left_mode 7 */
    {    10,      3,      3,      3,      3,      8,      2,      2,      9,      3, }, /* left_mode 8 */
    {    13,      7,     11,      4,      0,      4,      6,      2,      5,      8, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  7*/
    {   376,    135,    119,      6,     32,      8,     31,    224,      9,      3, }, /* left_mode 0 */
    {    93,     60,     54,      6,     13,      7,      8,     92,      2,     12, }, /* left_mode 1 */
    {    74,     36,     84,      0,      3,      2,      9,     67,      2,      1, }, /* left_mode 2 */
    {    19,      4,      4,      8,      8,      2,      4,      7,      6,     16, }, /* left_mode 3 */
    {    51,      7,      4,      1,     77,      3,      0,     14,      1,     15, }, /* left_mode 4 */
    {     7,      7,      5,      7,      4,      7,      4,      5,      0,      3, }, /* left_mode 5 */
    {    18,      2,     19,      2,      2,      4,     12,     11,      1,      2, }, /* left_mode 6 */
    {   129,      6,     27,      1,     21,      3,      0,    189,      0,      6, }, /* left_mode 7 */
    {     9,      1,      2,      8,      3,      7,      0,      5,      3,      3, }, /* left_mode 8 */
    {    20,      4,      5,     10,      4,      2,      7,     17,      3,     16, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  8*/
    {   617,     68,     34,     79,     11,     27,     25,     14,     75,     13, }, /* left_mode 0 */
    {    51,     82,     21,     26,      6,     12,     13,      1,     26,     16, }, /* left_mode 1 */
    {    29,      9,     12,     11,      3,      7,      1,     10,      2,      2, }, /* left_mode 2 */
    {    17,     19,     11,     74,      4,      3,      2,      0,     58,     13, }, /* left_mode 3 */
    {    10,      1,      1,      3,      4,      1,      0,      2,      1,      8, }, /* left_mode 4 */
    {    14,      4,      5,      5,      1,     13,      2,      0,     27,      8, }, /* left_mode 5 */
    {    10,      3,      5,      4,      1,      7,      6,      4,      5,      1, }, /* left_mode 6 */
    {    10,      2,      6,      2,      1,      1,      1,      4,      2,      1, }, /* left_mode 7 */
    {    14,      8,      5,     23,      2,     12,      6,      2,    117,      5, }, /* left_mode 8 */
    {     9,      6,      2,     19,      1,      6,      3,      2,      9,      9, }, /* left_mode 9 */
  },
  {
    /*Above Mode :  9*/
    {   680,     73,     22,     38,     42,      5,     11,      9,      6,     28, }, /* left_mode 0 */
    {   113,    112,     21,     22,     10,      2,      8,      4,      6,     42, }, /* left_mode 1 */
    {    44,     20,     24,      6,      5,      4,      3,      3,      1,      2, }, /* left_mode 2 */
    {    40,     23,      7,     71,      5,      2,      4,      1,      7,     22, }, /* left_mode 3 */
    {    85,      9,      4,      4,     17,      2,      0,      3,      2,     23, }, /* left_mode 4 */
    {    13,      4,      2,      6,      1,      7,      0,      1,      7,      6, }, /* left_mode 5 */
    {    26,      6,      8,      3,      2,      3,      8,      1,      5,      4, }, /* left_mode 6 */
    {    54,      8,      9,      6,      7,      0,      1,     11,      1,      3, }, /* left_mode 7 */
    {     9,     10,      4,     13,      2,      5,      4,      2,     14,      8, }, /* left_mode 8 */
    {    92,      9,      5,     19,     15,      3,      3,      1,      6,     58, }, /* left_mode 9 */
  },
};
