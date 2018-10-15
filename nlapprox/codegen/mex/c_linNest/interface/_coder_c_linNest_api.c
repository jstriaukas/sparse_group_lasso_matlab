/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_c_linNest_api.c
 *
 * Code generation for function '_coder_c_linNest_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "c_linNest.h"
#include "_coder_c_linNest_api.h"
#include "c_linNest_emxutil.h"
#include "c_linNest_mexutil.h"
#include "c_linNest_data.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_c_linNest_api",              /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[500];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[500];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier))[50];
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[50];
static int32_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_index,
  const char_T *identifier))[10];
static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[10];
static int32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nrow,
  const char_T *identifier);
static int32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *rangeGroupInd, const char_T *identifier))[5];
static int32_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[5];
static int32_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *groupLen, const char_T *identifier))[4];
static int32_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4];
static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[500];
static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[50];
static int32_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10];
static int32_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static int32_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5];
static int32_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];

/* Function Definitions */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier))[500]
{
  real_T (*y)[500];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[500]
{
  real_T (*y)[500];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier))[50]
{
  real_T (*b_y)[50];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_y = f_emlrt_marshallIn(sp, emlrtAlias(y), &thisId);
  emlrtDestroyArray(&y);
  return b_y;
}
  static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m1, u->size, 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[50]
{
  real_T (*y)[50];
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static int32_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_index, const char_T *identifier))[10]
{
  int32_T (*y)[10];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(b_index), &thisId);
  emlrtDestroyArray(&b_index);
  return y;
}

static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[10]
{
  int32_T (*y)[10];
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static int32_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nrow,
  const char_T *identifier)
{
  int32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(nrow), &thisId);
  emlrtDestroyArray(&nrow);
  return y;
}

static int32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *rangeGroupInd, const char_T *identifier))[5]
{
  int32_T (*y)[5];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = l_emlrt_marshallIn(sp, emlrtAlias(rangeGroupInd), &thisId);
  emlrtDestroyArray(&rangeGroupInd);
  return y;
}
  static int32_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[5]
{
  int32_T (*y)[5];
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *groupLen, const char_T *identifier))[4]
{
  int32_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(groupLen), &thisId);
  emlrtDestroyArray(&groupLen);
  return y;
}
  static int32_T (*n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4]
{
  int32_T (*y)[4];
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[500]
{
  real_T (*ret)[500];
  static const int32_T dims[2] = { 50, 10 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[500])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[50]
{
  real_T (*ret)[50];
  static const int32_T dims[1] = { 50 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[50])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[10]
{
  int32_T (*ret)[10];
  static const int32_T dims[1] = { 10 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 1U, dims);
  ret = (int32_T (*)[10])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static int32_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 0U, &dims);
  ret = *(int32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5]
{
  int32_T (*ret)[5];
  static const int32_T dims[1] = { 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 1U, dims);
  ret = (int32_T (*)[5])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static int32_T (*u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  int32_T (*ret)[4];
  static const int32_T dims[1] = { 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 1U, dims);
  ret = (int32_T (*)[4])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void c_linNest_api(const mxArray *prhs[18], const mxArray *plhs[2])
{
  emxArray_real_T *beta;
  emxArray_real_T *betaIsZero;
  real_T (*X)[500];
  real_T (*y)[50];
  int32_T (*b_index)[10];
  int32_T nrow;
  int32_T ncol;
  int32_T numGroup;
  int32_T (*rangeGroupInd)[5];
  int32_T (*groupLen)[4];
  real_T lambda1;
  real_T lambda2;
  int32_T innerIter;
  int32_T outerIter;
  real_T thresh;
  real_T outerThresh;
  real_T (*eta)[50];
  real_T b_gamma;
  real_T step;
  int32_T reset;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &beta, 2, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &betaIsZero, 2, &c_emlrtRTEI, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, -1);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, false, -1);
  prhs[6] = emlrtProtectR2012b(prhs[6], 6, false, -1);
  prhs[7] = emlrtProtectR2012b(prhs[7], 7, false, -1);
  prhs[14] = emlrtProtectR2012b(prhs[14], 14, false, -1);

  /* Marshall function inputs */
  X = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X");
  y = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y");
  b_index = g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "index");
  nrow = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "nrow");
  ncol = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "ncol");
  numGroup = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "numGroup");
  rangeGroupInd = k_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "rangeGroupInd");
  groupLen = m_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "groupLen");
  lambda1 = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "lambda1");
  lambda2 = emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "lambda2");
  innerIter = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "innerIter");
  outerIter = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "outerIter");
  thresh = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "thresh");
  outerThresh = emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "outerThresh");
  eta = e_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "eta");
  b_gamma = emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "gamma");
  step = emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "step");
  reset = i_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "reset");

  /* Invoke the target function */
  c_linNest(&st, *X, *y, *b_index, nrow, ncol, numGroup, *rangeGroupInd,
            *groupLen, lambda1, lambda2, innerIter, outerIter, thresh,
            outerThresh, *eta, b_gamma, step, reset, beta, betaIsZero);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(beta);
  plhs[1] = emlrt_marshallOut(betaIsZero);
  betaIsZero->canFreeData = false;
  emxFree_real_T(&betaIsZero);
  beta->canFreeData = false;
  emxFree_real_T(&beta);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_c_linNest_api.c) */
