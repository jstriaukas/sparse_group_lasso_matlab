clear; clc;
%% LOAD SIMULATED DATA FROM R %%

load X
load y
load index

%% SET PARAMETERS PARAMETERS %%

lambdas = [0 1 2 3];
type = 'linear';

%% FIT THE MODEL USING MATLAB %%

Fit = SGL(y,X,index,'lambdas', lambdas, 'standardize', false);

%% LOAD BETA ESTIMATED USING THE SAME DATA IN R %%

load rbeta


%% COMPARE BETAS %%

disp(['Mean absolute difference of MATLAB and R estimate: ', num2str(mean(mean(abs(Fit.beta-rbeta))))]);