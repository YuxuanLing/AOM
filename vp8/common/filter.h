/*
 *  Copyright (c) 2011 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef FILTER_H
#define FILTER_H

#include "vpx_config.h"
#include "vpx_scale/yv12config.h"

#define BLOCK_HEIGHT_WIDTH 4
#define VP8_FILTER_WEIGHT 128
#define VP8_FILTER_SHIFT  7

#define SUBPEL_SHIFTS 16

extern const short vp9_bilinear_filters[SUBPEL_SHIFTS][2];
extern const short vp9_sub_pel_filters_6[SUBPEL_SHIFTS][6];
extern const short vp9_sub_pel_filters_8[SUBPEL_SHIFTS][8];
extern const short vp9_sub_pel_filters_8s[SUBPEL_SHIFTS][8];

#endif // FILTER_H
