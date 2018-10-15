clear; clc;
%% DATA %%
load X
load y
load index

%% PARAMETERS %%

lambdas = 0;
type = 'linear';

%%

x = X;
y = y;

Fit = SGL(y,x,index,'lambdas', lambdas, 'standardize', false);
Fit.beta