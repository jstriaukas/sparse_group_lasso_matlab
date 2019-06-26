clear; clc;
%% LOAD SIMULATED DATA FROM R %%
addpath('functions');
addpath('rdata');
load X
load y
load index

%% Example %%

Fit = cvSGL(y,X,index,'standardize', false);
Predict = cvSGLpredict(Fit,X(end,:));


