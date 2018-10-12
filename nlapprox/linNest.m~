function out = linNest(X,y,index,nrow,ncol,numGroup,...
    rangeGroupInd,groupLen,lambda1,lambda2,...
    beta,innerIter,outerIter,thresh,outerThresh,...
    eta,gamma,betaIsZero,step,reset)

isActive = zeros(numGroup,1);
useGroup = ones(numGroup,1);
groupChange = 1;
ldot = 0;
nullBeta = 0;
while (groupChange == 1)
    groupChange = 0;
    linSolver(X, y, index, nrow, ncol, numGroup, beta, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange, isActive, useGroup, step, reset);
    outermostCounter = 0;
    while(outermostCounter < outerIter && outermostCheck > outerThresh)
        outermostCounter = outermostCounter+1;
        for i = 1:p
            outerOldBeta(i) = beta(i);
        end
        for j = 1:numGroup
            tempIsActive(i) = isActive(i);
        end
        linSolver(X, y, index, nrow, ncol, numGroup, beta, rangeGroupInd, groupLen, lambda1, lambda2, innerIter, thresh, ldot, nullBeta, gamma, eta, betaIsZero, groupChange, isActive, tempIsActive, step, reset);
        
        outermostCheck = 0;
        for i = 1:p
            outermostCheck = outermostCheck + abs(outerOldBeta(i) - beta(i));
        end
    end
    
    
    clearvars nullBeta outerOldBeta ldot isActive useGroup tempIsActive prob;
    
end
