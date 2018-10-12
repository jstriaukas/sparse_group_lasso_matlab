clear; clc;
%% DATA %%
load X
load y
load index

%% PARAMETERS %%

lambdas = [0, 1, 2, 3];
type = 'linear';

%%

x = X;
y = y;

Fit = SGL(y,x,index,'lambdas', lambdas, 'standardize', false);
