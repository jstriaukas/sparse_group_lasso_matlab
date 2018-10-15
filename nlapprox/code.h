#pragma once


extern int linNest(double *X, double* y, int* index, int *nrow, int *ncol, int *numGroup, int *rangeGroupInd,
	int *groupLen, double *lambda1, double *lambda2, double *beta, int *innerIter, int *outerIter, double *thresh,
	double *outerThresh, double *eta, double *gamma, int *betaIsZero, double *step, int *reset);

extern void gaussian3x3(const double* image, const int* imsize, double* output);
