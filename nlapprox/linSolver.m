function out = linSolver(X,y,index,nrow,ncol,numGroup,beta,rangeGroupInd, ...
    groupLen,lambda1,lambda2,innerIter,thresh,ldot,nullBeta,gamma,eta,betaIsZero, ...
    groupChange,isActive,useGroup,step,reset)

    for i = 1:numGroup
        if(useGroup(i) == 1)
            startInd = rangeGroupInd(i);
            % Setting up null gradient calc to check if group is 0
            for k = 1:nrow
                etaNull(k) = eta(k);
                for j = startInd:(rangeGroupInd(i) + groupLen(i))
                    etaNull(k) = etaNull(k) - X(k + nrow*j)*beta(j); 
                end
            end   
        for(int k = 0; k < nrow[0]; k++)
        {
          etaNull[k] = eta[k];
          for(int j = startInd; j < rangeGroupInd[i] + groupLen[i]; j++)
          {
            etaNull[k] = etaNull[k] - X[k + nrow[0] * j] * beta[j]; 
          }
        }
        end % end if useGroup(i) == 1
    end % end numGroup loop    
    for(int i = 0; i < numGroup[0]; i++)

     
  
        
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

  
  
  
void linNest(double *X, double* y, int *index, int *nrow, int *ncol, int *numGroup, int *rangeGroupInd, int *groupLen, double *lambda1, double *lambda2, double *beta, int *innerIter, int *outerIter, double *thresh, double *outerThresh, double *eta, double *gamma, int *betaIsZero, double *step, int *reset)
  {
    double* prob = NULL;
    prob = new double[nrow[0]];
    double* nullBeta = NULL;
    nullBeta = new double[ncol[0]];
    int n = nrow[0];
    int p = ncol[0];
    double *ldot = NULL;
    ldot = new double[n];
    int groupChange = 1;
    int* isActive = NULL;
    isActive = new int[numGroup[0]];
    int* useGroup = NULL;
    useGroup = new int[numGroup[0]];
    int* tempIsActive = NULL;
    tempIsActive = new int[numGroup[0]];
    
    for(int i = 0; i < numGroup[0]; i++)
    {
      isActive[i] = 0;
      useGroup[i] = 1;
    }
    
    // outer most loop creating response etc...
    int outermostCounter = 0;
    double outermostCheck = 100000;
    double* outerOldBeta = NULL;
    outerOldBeta = new double[p];
    
    while(groupChange == 1)
    {
      groupChange = 0;
      
      linSolver(X, y, index, nrow, ncol, numGroup, beta, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange, isActive, useGroup, step, reset);
      
      while(outermostCounter < outerIter[0] && outermostCheck > outerThresh[0])
      {
        outermostCounter ++;
        for(int i = 0; i < p; i++)
        {
          outerOldBeta[i] = beta[i];
        }
        
        for(int i = 0; i < numGroup[0]; i++)
        {
          tempIsActive[i] = isActive[i];
        }
        
        linSolver(X, y, index, nrow, ncol, numGroup, beta, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange, isActive, tempIsActive, step, reset);
        
        outermostCheck = 0;
        for(int i = 0; i < p; i++)
        {
          outermostCheck = outermostCheck + fabs(outerOldBeta[i] - beta[i]);
        }
      }
    }
    
    delete [] nullBeta;
    delete [] outerOldBeta;
    delete [] ldot;
    delete [] isActive;
    delete [] useGroup;
    delete [] tempIsActive;
    delete [] prob;
    
    /*return 1*/;
  }
