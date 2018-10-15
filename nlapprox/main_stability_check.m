clear; clc;
%% LOAD SIMULATED DATA FROM R %%

load X
load y
load index

%% SET PARAMETERS PARAMETERS %%

%% FIT THE MODEL WITH DEFAULTS %%
lambdas = [0 1 2 3 inf];
maxit = 1e3;
thresh = 1e-3;
minFrac = 1e-1;
nlam = length(lambdas);
gamma = 0.8;
standardize = false;
step = 1;
reset = 20;
alpha = 0.95;

Fit = SGL(y,X,index,'lambdas', lambdas, 'standardize', false, 'maxit',maxit, ...
    'thresh',thresh, 'minFrac',minFrac,'nlam',nlam,'gamma',gamma,'standardize',standardize, ...
    'verbose',false,'step',step,'reset',reset,'alpha',alpha,'lambdas',lambdas);

%% FIT THE MODEL WITH DEFAULTS %%
lambdas = [0 1 2 3 inf];
maxit = 0;
thresh = 1e-3;
minFrac = 1e-1;
nlam = length(lambdas);
gamma = 0.8;
standardize = false;
step = 1;
reset = 20;
alpha = 0.95;

Fit = SGL(y,X,index,'lambdas', lambdas, 'standardize', false, 'maxit',maxit, ...
    'thresh',thresh, 'minFrac',minFrac,'nlam',nlam,'gamma',gamma,'standardize',standardize, ...
    'verbose',false,'step',step,'reset',reset,'alpha',alpha,'lambdas',lambdas)