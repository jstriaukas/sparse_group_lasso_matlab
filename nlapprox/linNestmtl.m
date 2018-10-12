function [beta,betaIsZero,eta] = linNestmtl(X,y,index,nrow,ncol,numGroup,...
    rangeGroupInd,groupLen,lambda1,lambda2,...
    beta,innerIter,outerIter,thresh,outerThresh,...
    eta,gamma,betaIsZero,step,reset)

isActive = zeros(numGroup,1);
useGroup = ones(numGroup,1);
groupChange = 1;
ldot = 0;
nullBeta = beta;
outermostCheck = 1000;
p = ncol;
n = nrow;
while (groupChange == 1)
    groupChange = 0;
    [beta,betaIsZero,eta,isActive,groupChange] = linSolver(X, y, index, nrow, ncol, numGroup, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, useGroup, step, reset);
    outermostCounter = 0;
    while(outermostCounter < outerIter && outermostCheck > outerThresh)
        outermostCounter = outermostCounter+1;
        outerOldBeta = beta;
        tempIsActive = isActive;
        [beta,betaIsZero,eta,isActive,groupChange]=linSolver(X, y, index, nrow, ncol, numGroup, beta, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange, isActive, tempIsActive, step, reset);
        outermostCheck = 0;
        outermostCheck = outermostCheck + sum(abs(outerOldBeta - beta));
    end
    
    
    clearvars nullBeta outerOldBeta ldot isActive useGroup tempIsActive prob;
    
end
