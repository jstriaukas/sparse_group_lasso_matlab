/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * c_linNest.h
 *
 * Code generation for function 'c_linNest'
 *
 */

#ifndef C_LINNEST_H
#define C_LINNEST_H

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
extern void c_linNest(const emlrtStack *sp, real_T X[500], real_T y[50], int32_T
                      b_index[10], int32_T nrow, int32_T ncol, int32_T numGroup,
                      int32_T rangeGroupInd[5], int32_T groupLen[4], real_T
                      lambda1, real_T lambda2, int32_T innerIter, int32_T
                      outerIter, real_T thresh, real_T outerThresh, real_T eta
                      [50], real_T b_gamma, real_T step, int32_T reset,
                      emxArray_real_T *beta, emxArray_real_T *betaIsZero);

#endif

/* End of code generation (c_linNest.h) */
