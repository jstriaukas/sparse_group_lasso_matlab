/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * c_linNest_mexutil.h
 *
 * Code generation for function 'c_linNest_mexutil'
 *
 */

#ifndef C_LINNEST_MEXUTIL_H
#define C_LINNEST_MEXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "c_linNest_types.h"

/* Function Declarations */
extern real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);

#ifdef __WATCOMC__

#pragma aux b_emlrt_marshallIn value [8087];

#endif

extern real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_feval,
  const char_T *identifier);

#ifdef __WATCOMC__

#pragma aux emlrt_marshallIn value [8087];

#endif

extern real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

#ifdef __WATCOMC__

#pragma aux o_emlrt_marshallIn value [8087];

#endif
#endif

/* End of code generation (c_linNest_mexutil.h) */
