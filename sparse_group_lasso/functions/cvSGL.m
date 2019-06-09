function out = cvSGL(y, x, index, varargin)
[type,maxit,thresh,minFrac,nlam,gamma,standardize,verbose,step,reset,alpha,lambdas,nfold] = ...
    process_options(varargin,'type','linear','maxit',1000,'thresh',1e-4,...
    'minFrac',0.05,'nlam',100,'gamma',0.8,'standardize',false, ...
    'verbose',false,'step',1,'reset',10,'alpha',0.95,'lambdas',[],'nfold',10);
if isempty(lambdas)
    lambdas = betterPathCalc(y,x,index,alpha,minFrac,nlam,'standardize',standardize);
end
if (nlam ~= length(lambdas)) && (~isempty(lambdas))
    nlam = length(lambdas);
end
X_transform = [];
if (standardize == true)
    X = x;
    means = mean(X,1);
    m = repmat(means,size(X,1),1);
    X = (X - m);
    vars = sqrt(sum(X.^2,1));
    X = X./vars;
    x = X;
    X_transform.Xscale = vars;
    X_transform.Xmeans = means;
    Sol.X_transform = X_transform;
end
intercept = mean(y);
Sol.intercept = intercept;
y = y - intercept;
if (strcmp('linear',type))

    inner_iter = maxit;
    outer_iter = maxit;
    outer_thresh = thresh;
    [lambdas,lldiff,lldiffSD,CVSol] = linCrossVal(y,x,index,thresh,inner_iter, ...
        outer_iter, outer_thresh, minFrac, ...
        nlam,lambdas,gamma,verbose, ...
        step,reset,alpha,nfold);
    
    Sol.lldiff = lldiff;
    Sol.lambdas = lambdas;
    Sol.llSD = lldiffSD;
    Sol.CVSol = CVSol;
    
end
Sol.standardize = standardize;
out = Sol;