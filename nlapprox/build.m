
function build(target)

    entryPoint = 'c_linNest';
    
    nrow = int32(50);
    ncol = int32(10);
    X = zeros(nrow, ncol, 'double');
    y = zeros(nrow, 1, 'double');
    index = zeros(ncol, 1, 'int32');
    numGroup = int32(4);
    rangeGroupInd = zeros(numGroup+1, 1, 'int32');
    groupLen = zeros(numGroup, 1, 'int32');
    lambda1 = 0;
    lambda2 = 0;
    beta = zeros(1, ncol, 'double');
    innerIter = int32(0);
    outerIter = int32(0);
    thresh = 0;
    outerThresh = 0;
    eta = zeros(nrow, 1, 'double');
    gamma = 0;
    betaIsZero = int32(0);
    step = 0;
    reset = int32(0);
    
    cfg = coder.config(target);
    cfg.CustomSource = 'code.c';
    
    cfg.CustomSourceCode = [ '#include "code.h"'];
    
    cfg.GenerateReport = true;
    cfg.LaunchReport = false;
    
    codegen(entryPoint, ...
        '-args', {X, y, index, nrow, ncol, numGroup, rangeGroupInd, ...
        groupLen, lambda1, lambda2, innerIter, outerIter, ...
        thresh, outerThresh, eta, gamma, step, reset}, ...
        '-config', cfg);
end