/*
 *  Copyright (c) 2014 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VP10_ENCODER_AQ_CYCLICREFRESH_H_
#define VP10_ENCODER_AQ_CYCLICREFRESH_H_

#include "vp10/common/blockd.h"

#ifdef __cplusplus
extern "C" {
#endif

// The segment ids used in cyclic refresh: from base (no boost) to increasing
// boost (higher delta-qp).
#define CR_SEGMENT_ID_BASE 0
#define CR_SEGMENT_ID_BOOST1 1
#define CR_SEGMENT_ID_BOOST2 2

// Maximum rate target ratio for setting segment delta-qp.
#define CR_MAX_RATE_TARGET_RATIO 4.0

struct VP10_COMP;

struct CYCLIC_REFRESH;
typedef struct CYCLIC_REFRESH CYCLIC_REFRESH;

CYCLIC_REFRESH *vp10_cyclic_refresh_alloc(int mi_rows, int mi_cols);

void vp10_cyclic_refresh_free(CYCLIC_REFRESH *cr);

// Estimate the bits, incorporating the delta-q from segment 1, after encoding
// the frame.
int vp10_cyclic_refresh_estimate_bits_at_q(const struct VP10_COMP *cpi,
                                           double correction_factor);

// Estimate the bits per mb, for a given q = i and a corresponding delta-q
// (for segment 1), prior to encoding the frame.
int vp10_cyclic_refresh_rc_bits_per_mb(const struct VP10_COMP *cpi, int i,
                                       double correction_factor);

// Prior to coding a given prediction block, of size bsize at (mi_row, mi_col),
// check if we should reset the segment_id, and update the cyclic_refresh map
// and segmentation map.
void vp10_cyclic_refresh_update_segment(struct VP10_COMP *const cpi,
                                        MB_MODE_INFO *const mbmi, int mi_row,
                                        int mi_col, BLOCK_SIZE bsize,
                                        int64_t rate, int64_t dist, int skip);

// Update the segmentation map, and related quantities: cyclic refresh map,
// refresh sb_index, and target number of blocks to be refreshed.
void vp10_cyclic_refresh_update__map(struct VP10_COMP *const cpi);

// Update the actual number of blocks that were applied the segment delta q.
void vp10_cyclic_refresh_postencode(struct VP10_COMP *const cpi);

// Set golden frame update interval, for 1 pass CBR mode.
void vp10_cyclic_refresh_set_golden_update(struct VP10_COMP *const cpi);

// Check if we should not update golden reference, based on past refresh stats.
void vp10_cyclic_refresh_check_golden_update(struct VP10_COMP *const cpi);

// Set/update global/frame level refresh parameters.
void vp10_cyclic_refresh_update_parameters(struct VP10_COMP *const cpi);

// Setup cyclic background refresh: set delta q and segmentation map.
void vp10_cyclic_refresh_setup(struct VP10_COMP *const cpi);

int vp10_cyclic_refresh_get_rdmult(const CYCLIC_REFRESH *cr);

void vp10_cyclic_refresh_reset_resize(struct VP10_COMP *const cpi);

static INLINE int cyclic_refresh_segment_id_boosted(int segment_id) {
  return segment_id == CR_SEGMENT_ID_BOOST1 ||
         segment_id == CR_SEGMENT_ID_BOOST2;
}

static INLINE int cyclic_refresh_segment_id(int segment_id) {
  if (segment_id == CR_SEGMENT_ID_BOOST1)
    return CR_SEGMENT_ID_BOOST1;
  else if (segment_id == CR_SEGMENT_ID_BOOST2)
    return CR_SEGMENT_ID_BOOST2;
  else
    return CR_SEGMENT_ID_BASE;
}

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // VP10_ENCODER_AQ_CYCLICREFRESH_H_
