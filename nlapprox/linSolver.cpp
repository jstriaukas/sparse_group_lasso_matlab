#include "mex.h"
#include "math.h"
#include "iostream"


using namespace std;

void linGradCalc(int *nrow, double *eta, double *y, double *ldot)
  {
    for(int i = 0; i < nrow[0]; i++)
    {
      ldot[i] = (eta[i] - y[i])/nrow[0];  /* OR MAYBE NOT? */
    }
  }
double linNegLogLikelihoodCalc(int *nrow, double *eta, double *y)
  {
    double squareSum = 0;
    
    for(int i = 0; i < nrow[0]; i++)
    {
      squareSum = squareSum + pow(eta[i] - y[i], 2)/2; 
    }
    
    return squareSum/nrow[0];   /* OR MAYBE NOT? */
  }
  
  
void linSolver(double *X, double *y, int* index, int *nrow, int *ncol, int *numGroup, double *beta, int *rangeGroupInd, int *groupLen, double *lambda1, double *lambda2, int *innerIter, double *thresh, double *ldot, double *nullBeta, double *gamma, double *eta, int* betaIsZero, int& groupChange, int* isActive, int* useGroup, double *step, int *reset)
  {
    double *theta = new double[ncol[0]];
    int startInd = 0;
    double zeroCheck = 0;
    double check = 0;
    int count = 0;
    double t = step[0];
    double diff = 1;
    double norm = 0;
    double uOp = 0;
    double Lnew = 0;
    double Lold = 0;
    double sqNormG = 0;
    double iProd = 0;
    double *etaNew = NULL;
    etaNew = new double[nrow[0]];
    double *etaNull = NULL;
    etaNull = new double[nrow[0]];
    //  int reset = 20;
    
    for(int i = 0; i < numGroup[0]; i++)
    {
      if(useGroup[i] == 1)
      {
        startInd = rangeGroupInd[i];
        
        // Setting up null gradient calc to check if group is 0
        for(int k = 0; k < nrow[0]; k++)
        {
          etaNull[k] = eta[k];
          for(int j = startInd; j < rangeGroupInd[i] + groupLen[i]; j++)
          {
            etaNull[k] = etaNull[k] - X[k + nrow[0] * j] * beta[j]; 
          }
        }
        
        // Calculating Null Gradient
        linGradCalc(nrow, etaNull, y, ldot);
        
        double *grad = NULL;
        grad = new double[groupLen[i]];
        
        for(int j = 0; j < groupLen[i]; j++)
        {
          grad[j] = 0;
          for(int k = 0; k < nrow[0]; k++)
          {
            grad[j] = grad[j] + X[k + nrow[0] * (j + rangeGroupInd[i])] * ldot[k];
          }
          if(grad[j] < lambda1[0] && grad[j] > -lambda1[0])
          {
            grad[j] = 0;
          }
          if(grad[j] > lambda1[0])
          {
            grad[j] = grad[j] - lambda1[0];
          }
          if(grad[j] < -lambda1[0])
          {
            grad[j] = grad[j] + lambda1[0];
          }
          if(pow(grad[j],2) == pow(lambda1[0],2))
          {
            grad[j] = 0;
          }
          
        }
        
        zeroCheck = 0;
        for(int j = 0; j < groupLen[i]; j++)
        {
          zeroCheck = zeroCheck + pow(grad[j],2);
        }
        
        if(zeroCheck <= pow(lambda2[0],2)*groupLen[i])  //Or not?
        {
          if(betaIsZero[i] == 0)
          {
            for(int k = 0; k < nrow[0]; k++)
            {
              for(int j = rangeGroupInd[i]; j < rangeGroupInd[i] + groupLen[i]; j++)
              {
                eta[k] = eta[k] - X[k + nrow[0] * j] * beta[j];
              }
            }
          }
          betaIsZero[i] = 1;
          for(int j = 0; j < groupLen[i]; j++)
          {
            beta[j + rangeGroupInd[i]] = 0;
          }
        }
        else
        {
          if(isActive[i] == 0)
          {
            groupChange = 1;
          }
          isActive[i] = 1;
          
          for(int k = 0; k < ncol[0]; k++)
          {
            theta[k] = beta[k];
          }
          
          betaIsZero[i] = 0;
          double *z = NULL;
          z = new double[groupLen[i]];
          double *U = NULL;
          U = new double[groupLen[i]];
          double *G = NULL;
          G = new double[groupLen[i]];
          double *betaNew = NULL;
          betaNew = new double[ncol[0]];
          
          count = 0;
          check = 100000;
          
          
          
          while(count <= innerIter[0] && check > thresh[0])
          {
            
            count++;
            
            linGradCalc(nrow, eta, y ,ldot);
            
            for(int j = 0; j < groupLen[i]; j++)
            {		  
              grad[j] = 0;
              for(int k = 0; k < nrow[0]; k++)
              {
                grad[j] = grad[j] + X[k + nrow[0] * (j + rangeGroupInd[i])] * ldot[k];
              }
              
            }
            
            diff = -1;
            //	      t = 0.5;
            Lold = linNegLogLikelihoodCalc(nrow, eta, y);
            
            // Back-tracking
            
            while(diff < 0)
            {
              for(int j = 0; j < groupLen[i]; j++)
              {
                z[j] = beta[j + rangeGroupInd[i]] - t * grad[j];
                if(z[j] < lambda1[0] * t && z[j] > -lambda1[0] * t)
                {
                  z[j] = 0;
                }
                if(z[j] > lambda1[0] * t)
                {
                  z[j] = z[j] - lambda1[0] * t;
                }
                if(z[j] < -lambda1[0] * t)
                {
                  z[j] = z[j] + lambda1[0] * t;
                }
              }
              
              norm = 0;
              for(int j = 0; j < groupLen[i]; j++)
              {
                norm = norm + pow(z[j],2);
              }
              norm = sqrt(norm);
              
              if(norm != 0){
                uOp = (1 - lambda2[0]*sqrt(double(groupLen[i]))*t/norm);   //Or not?
              }
              else{uOp = 0;}
              
              if(uOp < 0)
              {
                uOp = 0;
              }
              
              for(int j = 0; j < groupLen[i]; j++)
              {
                U[j] = uOp*z[j];
                G[j] = 1/t *(beta[j + rangeGroupInd[i]] - U[j]);
                
              }
              
              // Setting up betaNew and etaNew in direction of Grad for descent step
              
              for(int k = 0; k < nrow[0]; k++)
              {
                etaNew[k] = eta[k];
                for(int j = 0; j < groupLen[i]; j++)
                {
                  etaNew[k] = etaNew[k] - t*G[j] * X[k + nrow[0]*(rangeGroupInd[i] + j)];
                }
              }
              
              Lnew = linNegLogLikelihoodCalc(nrow, etaNew, y);
              
              sqNormG = 0;
              iProd = 0;
              
              for(int j = 0; j < groupLen[i]; j++)
              {
                sqNormG = sqNormG + pow(G[j],2);
                iProd = iProd + grad[j] * G[j];
              }
              
              diff = Lold - Lnew - t * iProd + t/2 * sqNormG;
              
              t = t * gamma[0];
            }
            t = t / gamma[0];
            
            check = 0;
            
            for(int j = 0; j < groupLen[i]; j++)
            {
              check = check + fabs(theta[j + rangeGroupInd[i]] - U[j]);
              for(int k = 0; k < nrow[0]; k++)
              {
                eta[k] = eta[k] - X[k + nrow[0] * (j + rangeGroupInd[i])]*beta[j + rangeGroupInd[i]];
              }
              beta[j + rangeGroupInd[i]] = U[j] + count%reset[0]/(count%reset[0]+3) * (U[j] - theta[j + rangeGroupInd[i]]);
              theta[j + rangeGroupInd[i]] = U[j];
              
              for(int k = 0; k < nrow[0]; k++)
              {
                eta[k] = eta[k] + X[k + nrow[0] * (j + rangeGroupInd[i])]*beta[j + rangeGroupInd[i]];
              }
            }
          }
          delete [] z;
          delete [] U;
          delete [] G;
          delete [] betaNew;
        }
        delete [] grad;
      }
    }
    delete [] etaNew;
    delete [] etaNull;
    delete [] theta;
  }

void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    
    double  *X,*y,*lambda1,*lambda2,*beta,*thresh;
    double  *eta,*gamma,*step,*ldot,*nullBeta;
    int index,nrow,ncol,numGroup,rangeGroupInd,groupLen;
    int innerIter,groupChange,betaIsZero,reset,isActive,useGroup;
    double rbeta;
    

    /*int& groupChange, int* isActive, 
    int* useGroup,  
    DOUBLE *ldot, *nullBeta*/
  
            
	/* Create a pointer to the input vectors and scalar inputs */
     X = mxGetPr(prhs[0]);   
     y = mxGetPr(prhs[1]);
     index = mxGetScalar(prhs[2]);
     nrow = mxGetScalar(prhs[3]);
     ncol = mxGetScalar(prhs[4]);
     
     numGroup = mxGetScalar(prhs[5]);
     beta = mxGetPr(prhs[6]);
     rangeGroupInd = mxGetScalar(prhs[7]);
     groupLen = mxGetScalar(prhs[8]);
     
     lambda1 = mxGetPr(prhs[9]); 
     lambda2 = mxGetPr(prhs[10]);
     
     innerIter = mxGetScalar(prhs[11]);
     thresh =  mxGetPr(prhs[12]); 
     ldot =  mxGetPr(prhs[13]);
     
     nullBeta =  mxGetPr(prhs[14]);
     gamma =  mxGetPr(prhs[15]); 
     eta =  mxGetPr(prhs[16]);
     
     betaIsZero = mxGetScalar(prhs[17]);
     groupChange = mxGetScalar(prhs[18]);
     isActive = mxGetScalar(prhs[19]);
     useGroup = mxGetScalar(prhs[20]);
     step = mxGetPr(prhs[21]);
     reset = mxGetScalar(prhs[22]);


	/* Get the dimension of beta */
	rbeta = mxGetM(prhs[6]);
   
    

	/* Set the output pointer */
	plhs[0] = mxCreateDoubleMatrix(rbeta, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(1, 1, mxREAL); 

	/* Create a C pointer to a copy of the output vectors */
	beta = mxGetPr(plhs[0]);
    betaIsZero = mxGetScalar(plhs[1]);
	/* Call the C subroutine */
    /*linSolver(X,y,index,     nrow, ncol,  numGroup, beta,  rangeGroupInd,  groupLen,  lambda1,  lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange,    isActive, useGroup, step, reset) */
	linSolver(X, y, &index, &nrow, &ncol, &numGroup, beta, &rangeGroupInd, &groupLen, lambda1, lambda2, &innerIter, thresh, ldot, nullBeta, gamma, eta, &betaIsZero, groupChange, &isActive, &useGroup, step, &reset);
}       





