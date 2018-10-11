function out = linNest(X,y,index,nrow,ncol,numGroup,...
                    rangeGroupInd,groupLen,lambda1,lambda2,...
                    beta,innerIter,outerIter,thresh,outerThresh,...
                    eta,gamma,betaIsZero,step,reset)

    isActive = zeros(numGroup,1);
    useGroup = ones(numGroup,1);

    
    %// outer most loop creating response etc...
    int outermostCounter = 0;
    double outermostCheck = 100000;
    double* outerOldBeta = NULL;
    outerOldBeta = new double[p];
    
    
    while (grouChange == 1)
        grouChange = 0;
        
    while(groupChange == 1)
    
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