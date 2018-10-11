clear; clc;
%% DATA %%
load X
load y
load index

%% PARAMETERS %%
maxit = 1000;
thresh = 0.001;
min.frac = 0.1;
nlam = 20;
gamma = 0.8;
standardize = true;
verbose = false;
step = 1;
reset = 10;
alpha = 0.95;
lambdas = [1, 2, 3];
type = 'linear';

%%

x = X;
y = y;

Fit = SGL(y,x,index);
