function [lambdas,lldiff,lldiffSD,CVSol] = linCrossVal(y,x,index,thresh,innerIter, ...
    outerIter, outerThresh, minFrac, ...
    nlam,lambdas,gamma,verbose, ...
    step,reset,alpha,nfold,varargin)

[foldid,israndom] = ...
    process_options(varargin,'foldid',[],'israndom',false);

[n,p] = size(x);
%_ preparing for C++ _%
groups = unique(index);
numGroup = length(groups);
rangeGroupInd = zeros((numGroup+1),1);
for i = 1:numGroup
    rangeGroupInd(i,:) = find(index == groups(i), 1 ) - 1;
end
rangeGroupInd(numGroup+1) = p;
groupLen = diff(rangeGroupInd);
beta_naught = zeros(p,1);
beta = beta_naught;

if isempty(lambdas)
    lambdas = betterPathCalc(y,x,index,alpha,minFrac,nlam,'standardize',false);
end

lldiff = zeros(nlam,1);
lldiffFold = zeros(nlam,nfold);

size_ = floor(n/nfold);
o_flow = [ones(n - size_ * nfold,1), zeros(nfold - (n - size_ * nfold),1)];
sizes = size_ + o_flow;
ind_split = [1;cumsum(sizes)];

if isempty(foldid)
    population = cat(2, repmat(1:nfold, 1, floor(n/nfold)), 1:mod(n,nfold));
    if israndom
        foldid = population(randperm(length(population), n));
    else
        foldid = sort(population);
    end
else
    nfolds = max(foldid);
end

%lambdas
for i = 1:nfold % oneDim use parfor hence it would not improve the speed to use if here.
    which = foldid == i;
    y_new   = y(~which,:);
    x_new   = x(~which,:);
    beta_new = oneDim(y_new,x_new,index,thresh,innerIter, ...
        outerIter, outerThresh, minFrac, ...
        nlam,lambdas,gamma,verbose, ...
        step,reset,alpha);
    for k = 1:nlam
        lldiffFold(k,i) = sum((y(which,:) - x(which,:) * beta_new( :,k)).^2) / 2;
        lldiff(k,i) =  sum((y(which,:) - x(which,:) * beta_new( :,k)).^2) / 2;
    end
    %clear beta_new
    if verbose
        disp(['*** nfold -', num2str(i), '***']);
    end
    
end % end of nfolds
lldiff = sum(lldiff,2);
lldiffSD = std(lldiffFold,[],2)*sqrt(nfold);
lambda_cv = lambdas(min(lldiff)==lldiff);

[beta_cv,~] = oneDim(y,x,index,thresh,innerIter, ...
        outerIter, outerThresh, minFrac, ...
        1,lambda_cv,gamma,verbose, ...
        step,reset,alpha);
    
CVSol.beta = beta_cv;
CVSol.lambda = lambda_cv;
