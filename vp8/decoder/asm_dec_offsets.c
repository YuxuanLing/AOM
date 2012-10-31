/*
 *  Copyright (c) 2011 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#include "vpx_ports/asm_offsets.h"
#include "onyxd_int.h"

BEGIN

DEFINE(detok_scan,                              offsetof(DETOK, scan));
DEFINE(detok_ptr_block2leftabove,               offsetof(DETOK, ptr_block2leftabove));
DEFINE(detok_coef_tree_ptr,                     offsetof(DETOK, vp9_coef_tree_ptr));
DEFINE(detok_norm_ptr,                          offsetof(DETOK, norm_ptr));
DEFINE(detok_ptr_coef_bands_x,                  offsetof(DETOK, ptr_coef_bands_x));

DEFINE(detok_A,                                 offsetof(DETOK, A));
DEFINE(detok_L,                                 offsetof(DETOK, L));

DEFINE(detok_qcoeff_start_ptr,                  offsetof(DETOK, qcoeff_start_ptr));
DEFINE(detok_coef_probs,                        offsetof(DETOK, coef_probs));
DEFINE(detok_eob,                               offsetof(DETOK, eob));

DEFINE(bool_decoder_user_buffer_end,            offsetof(BOOL_DECODER, user_buffer_end));
DEFINE(bool_decoder_user_buffer,                offsetof(BOOL_DECODER, user_buffer));
DEFINE(bool_decoder_value,                      offsetof(BOOL_DECODER, value));
DEFINE(bool_decoder_count,                      offsetof(BOOL_DECODER, count));
DEFINE(bool_decoder_range,                      offsetof(BOOL_DECODER, range));

END

/* add asserts for any offset that is not supported by assembly code */
/* add asserts for any size that is not supported by assembly code */
