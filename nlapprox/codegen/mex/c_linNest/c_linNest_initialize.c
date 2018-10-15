/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * c_linNest_initialize.c
 *
 * Code generation for function 'c_linNest_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "c_linNest.h"
#include "c_linNest_initialize.h"
#include "_coder_c_linNest_mex.h"
#include "c_linNest_data.h"

/* Function Definitions */
void c_linNest_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (c_linNest_initialize.c) */
