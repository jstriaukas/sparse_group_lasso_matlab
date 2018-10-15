/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * c_linNest.c
 *
 * Code generation for function 'c_linNest'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "c_linNest.h"
#include "c_linNest_emxutil.h"
#include "c_linNest_mexutil.h"

/* Custom Source Code */
#include "code.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 12,    /* lineNo */
  "c_linNest",                         /* fcnName */
  "C:\\Users\\Z440\\Documents\\GitHub\\midas_lasso_shapre_rest\\nlapprox\\c_linNest.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 36,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 70,    /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  5,                                   /* colNo */
  "c_linNest",                         /* fName */
  "C:\\Users\\Z440\\Documents\\GitHub\\midas_lasso_shapre_rest\\nlapprox\\c_linNest.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 5, /* lineNo */
  5,                                   /* colNo */
  "c_linNest",                         /* fName */
  "C:\\Users\\Z440\\Documents\\GitHub\\midas_lasso_shapre_rest\\nlapprox\\c_linNest.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 4,     /* lineNo */
  21,                                  /* colNo */
  "c_linNest",                         /* fName */
  "C:\\Users\\Z440\\Documents\\GitHub\\midas_lasso_shapre_rest\\nlapprox\\c_linNest.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 4,   /* lineNo */
  5,                                   /* colNo */
  "c_linNest",                         /* fName */
  "C:\\Users\\Z440\\Documents\\GitHub\\midas_lasso_shapre_rest\\nlapprox\\c_linNest.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRSInfo c_emlrtRSI = { 70,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

/* Function Declarations */
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m2;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m2, 3, pArrays, "feval", true, location);
}

void c_linNest(const emlrtStack *sp, real_T X[500], real_T y[50], int32_T
               b_index[10], int32_T nrow, int32_T ncol, int32_T numGroup,
               int32_T rangeGroupInd[5], int32_T groupLen[4], real_T lambda1,
               real_T lambda2, int32_T innerIter, int32_T outerIter, real_T
               thresh, real_T outerThresh, real_T eta[50], real_T b_gamma,
               real_T step, int32_T reset, emxArray_real_T *beta,
               emxArray_real_T *betaIsZero)
{
  int32_T i0;
  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 7 };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *c_y;
  const mxArray *d_y;
  static const int32_T iv1[2] = { 1, 28 };

  static const char_T formatSpec[28] = { 'R', 'u', 'n', 'n', 'i', 'n', 'g', ' ',
    'C', 'u', 's', 't', 'o', 'm', ' ', 'C', ' ', 'C', 'o', 'd', 'e', '.', '.',
    '.', '\\', 'n', '\\', 'n' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  i0 = beta->size[0] * beta->size[1];
  beta->size[0] = 1;
  if (!(ncol >= 0)) {
    emlrtNonNegativeCheckR2012b(ncol, &emlrtDCI, sp);
  }

  beta->size[1] = ncol;
  emxEnsureCapacity(sp, (emxArray__common *)beta, i0, sizeof(real_T), &emlrtRTEI);
  if (!(ncol >= 0)) {
    emlrtNonNegativeCheckR2012b(ncol, &b_emlrtDCI, sp);
  }

  for (i0 = 0; i0 < ncol; i0++) {
    beta->data[i0] = 0.0;
  }

  i0 = betaIsZero->size[0] * betaIsZero->size[1];
  betaIsZero->size[0] = 1;
  betaIsZero->size[1] = ncol;
  emxEnsureCapacity(sp, (emxArray__common *)betaIsZero, i0, sizeof(real_T),
                    &b_emlrtRTEI);
  for (i0 = 0; i0 < ncol; i0++) {
    betaIsZero->data[i0] = 0.0;
  }

  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(&b_st, 7, m0, &u[0]);
  emlrtAssign(&b_y, m0);
  c_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&c_y, m0);
  d_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(&b_st, 28, m0, &formatSpec[0]);
  emlrtAssign(&d_y, m0);
  c_st.site = &c_emlrtRSI;
  emlrt_marshallIn(&c_st, feval(&c_st, b_y, c_y, d_y, &emlrtMCI), "feval");
  linNest(X, y, b_index, &nrow, &ncol, &numGroup, rangeGroupInd, groupLen,
          &lambda1, &lambda2, &beta->data[0], &innerIter, &outerIter, &thresh,
          &outerThresh, eta, &b_gamma, &betaIsZero->data[0], &step, &reset);
}

/* End of code generation (c_linNest.c) */
