function out = SGL(y, x, index,varargin)


[type,maxit,thresh,minFrac,nlam,gamma,standardize,verbose,step,reset,alpha,lambdas,cpp] = ...
    process_options(varargin,'type','linear','maxit',1000,'thresh',1e-3,...
    'minFrac',1e-1,'nlam',20,'gamma',0.8,'standardize',true, ...
    'verbose',false,'step',1,'reset',20,'alpha',0.95,'lambdas',[1,2,3],'cpp',false);

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
end

if (strcmp('linear',type))
    if (standardize == true)
        intercept = mean(y);
        y = y - intercept;
    end
    inner_iter = maxit;
    outer_iter = maxit;
    outer_thresh = thresh;
    [beta,lambdas] = oneDim(y,x,index,thresh,inner_iter, ...
        outer_iter, outer_thresh, minFrac, ...
        nlam,lambdas,gamma,verbose, ...
        step,reset,alpha,cpp);
    
    if (standardize == true)
      Sol.beta = beta;
      Sol.lambdas = lambdas; 
      Sol.type = type;
      Sol.intercept = intercept;
      Sol.X_transform = X_transform; 
    else
      Sol.beta = beta;
      Sol.lambdas = lambdas; 
    end
end

out = Sol;