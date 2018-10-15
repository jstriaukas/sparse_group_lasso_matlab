/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_c_linNest_info.c
 *
 * Code generation for function '_coder_c_linNest_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "c_linNest.h"
#include "_coder_c_linNest_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 18);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("c_linNest"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(18.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.2.0.556344 (R2017a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[12] = {
    "789ced5b4d6fe344187697eeb22bb4e03db0da15485408ad162d8ad336bbe972a1cd57936d9a649b342d5da03bb1c7b5b7e371ea8f34e985fe04c4890312676e"
    "9c10c73df203000924247e06479cd86e92d90e7689ebe2d423b5d3c993ccf3faede367de716c66a6b43ec330cc9b8cddfeced8fd4d67cc3afd1566bc91f88cd3",
    "bf418cdd7695991dfb9c8b7febf4bc8a0dd835ec019231ac984a0b6ad60003059e4c23a88a8c01361abd366434a8aba803850122ca0836640596d5914151b606"
    "4a61043a19f4a1fedf5909f2fb75536134491f868b4607cc487e7ea01cffaccffc5428f96109fc59fef3ecc7dca60e359ddb49a5925c4ee54d056243e75665a3",
    "68b638451680be8b80aeabbbba04da1adcb51262701881765b53bb1cbf6be5b162bd945086f13fa7c477cd67fc64efb61bccf591d1fd652f3ebff97a9dc2c73a"
    "88d8d6646c889ec7e7976f96180ff96c8497405f9481e9618dca378e3f2b95b70792a869ea9e0694b9be76756e7da5515ec9701b0bc9f934e00c55452deb3f0f",
    "15c421d9920830106871b22a9a987332d5170313a61e8e6fdefef1d79570f517b6de2f8eaf4b99cfaffe6e53f858029f973a02aaa3bde4fc51ae6064b77aa9b5"
    "ca56711847cd83c72b0e86320e6bfea89fc76d4a7c7e75778518bbed06f17ebba597edbeb01c940eef50f85902e755016a092b0150c3002530d0f664cc4bfb93",
    "fa3fd96871b8cde57bf91ff9dcf93ff3e073f133e9c62a07342870835c39bf1f389d9b39ee2473b690425c0fbebcbff14bbc1e9c135f58eb41af7b587a0c0ae2"
    "dec3245fcdabf51705337d989f9ef5e025e5f3513daf69baf0abc3d728c7e3ae0f77c65e7d7fd9eeef39fd4781ed07ae52e2601d4444aada2fd083e2bb468c87",
    "7c3622a8660bc1e0ea8812956f1c9fa48e80685047f433e55411a1fad5f7cbf7e2fd40d4fd7fe9205d6d1ca0dcc3fd8cd478ba5a370e7239be303dfe1f9fc7a7"
    "c73faebbb9135f3fa6cce7375fef51f8580227ea7f59cf9832324ab8622a5093f90bf3fd9f26e4dba6f28de367d64bffe79522814c5b4209b1feffeeaf3f62ff",
    "8fbaff573b07d915b1d8596a3c4df5f8bc82170a3b28be1e74c9fcff83c0fcff1d0a1f4be084ffeb3c40404bb855ffe4753fd9fc5e079ad4ff373df85c3c18ff"
    "7f60e76d443b21faffd799bbb1ff47ddff5bd2a3da364686505795bc898b8bad7ce6c96aecff97d5ffbfa2cce7375f1f52f8580227fc1fb4dba8571f9859c1c4",
    "bc21abb8846b08f0ee2d035edf8ff88def2d8ff85c5c74a2d8950016ac0d82cbfff384fc2d0f7e170f667da0a7d5155a883afbf3f778bf10f9f5a27898cb6e74"
    "978e165550844f0ac6125f153353b45ec4e7f7e9c7e54f8f89a9db475cd475a4781f715e7c76bb2c7cf13e2298f927dd475cf47d45cf29f105abbb4c64ef170d",
    "fbfbe1e9d7437cbfe879f2c5f78b06337f7c1e9f1eff98ee8e4b81f9fa7562cc9cbccf464459183cc97119eaf6da6482b0f4d00106e4dc94855cb733dfc4757b"
    "f4fdbd5b4b358fb69a4ab3b9f8a950dc107792952e98a2fb3f637f3f3dfe71dd5503bb6e7397c2c7123871dd4641a2622cf0d62f078feaf7bf4d0f3e173f935e",
    "fef546e161ea12ed50ebfb77d373bfc5fe7f4e7c61f97f7b6b1d95f38feb2f36ab1b664b59e2cbdd2ccac5fe7fa9fcffb816d8f35fb7287c2c81cb7a3f41a56a"
    "be6b5887adcbbcf37a549ffffac283cfc503acfb5f4961c8cf87834f505cffff5ffdff6d0a1f4be045e9d1e15a432e555205a9ac623d6dac48a3fbc8a8faff3f",
    "ee11f569", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 17168U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_c_linNest_info.c) */
