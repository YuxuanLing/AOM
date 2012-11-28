/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef loopfilter_h
#define loopfilter_h

#include "vpx_ports/mem.h"
#include "vpx_config.h"
#include "vp9/common/vp9_blockd.h"

#define MAX_LOOP_FILTER 63

typedef enum {
  NORMAL_LOOPFILTER = 0,
  SIMPLE_LOOPFILTER = 1
} LOOPFILTERTYPE;

#if ARCH_ARM
#define SIMD_WIDTH 1
#else
#define SIMD_WIDTH 16
#endif

/* Need to align this structure so when it is declared and
 * passed it can be loaded into vector registers.
 */
typedef struct {
  DECLARE_ALIGNED(SIMD_WIDTH, unsigned char,
                  mblim[MAX_LOOP_FILTER + 1][SIMD_WIDTH]);
  DECLARE_ALIGNED(SIMD_WIDTH, unsigned char,
                  blim[MAX_LOOP_FILTER + 1][SIMD_WIDTH]);
  DECLARE_ALIGNED(SIMD_WIDTH, unsigned char,
                  lim[MAX_LOOP_FILTER + 1][SIMD_WIDTH]);
  DECLARE_ALIGNED(SIMD_WIDTH, unsigned char,
                  hev_thr[4][SIMD_WIDTH]);
  unsigned char lvl[4][4][4];
  unsigned char hev_thr_lut[2][MAX_LOOP_FILTER + 1];
  unsigned char mode_lf_lut[MB_MODE_COUNT];
} loop_filter_info_n;

struct loop_filter_info {
  const unsigned char *mblim;
  const unsigned char *blim;
  const unsigned char *lim;
  const unsigned char *hev_thr;
};

#define prototype_loopfilter(sym) \
  void sym(unsigned char *src, int pitch, const unsigned char *blimit,\
           const unsigned char *limit, const unsigned char *thresh, int count)

#define prototype_loopfilter_block(sym) \
  void sym(unsigned char *y, unsigned char *u, unsigned char *v, \
           int ystride, int uv_stride, struct loop_filter_info *lfi)

#define prototype_simple_loopfilter(sym) \
  void sym(unsigned char *y, int ystride, const unsigned char *blimit)

#if ARCH_X86 || ARCH_X86_64
#include "x86/vp9_loopfilter_x86.h"
#endif

#if ARCH_ARM
#include "arm/vp9_loopfilter_arm.h"
#endif

typedef void loop_filter_uvfunction(unsigned char *u,   /* source pointer */
                                    int p,              /* pitch */
                                    const unsigned char *blimit,
                                    const unsigned char *limit,
                                    const unsigned char *thresh,
                                    unsigned char *v);

/* assorted loopfilter functions which get used elsewhere */
struct VP9Common;
struct macroblockd;

void vp9_loop_filter_init(struct VP9Common *cm);

void vp9_loop_filter_frame_init(struct VP9Common *cm,
                                struct macroblockd *mbd,
                                int default_filt_lvl);

void vp9_loop_filter_frame(struct VP9Common *cm, struct macroblockd *mbd);

void vp9_loop_filter_partial_frame(struct VP9Common *cm,
                                   struct macroblockd *mbd,
                                   int default_filt_lvl);

void vp9_loop_filter_frame_yonly(struct VP9Common *cm,
                                 struct macroblockd *mbd,
                                 int default_filt_lvl);

void vp9_loop_filter_update_sharpness(loop_filter_info_n *lfi,
                                      int sharpness_lvl);

#endif  // loopfilter_h
