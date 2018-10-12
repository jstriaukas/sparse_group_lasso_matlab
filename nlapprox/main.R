rm(list = ls())
require("SGL")
require("R.matlab")
#setwd("/Users/striaukas/Documents/GitHub/midas_lasso_shapre_rest/nlapprox")
setwd("C:/Users/Z440/Documents/GitHub/midas_lasso_shapre_rest/nlapprox")
set.seed(123)
n = 50; p = 10; size.groups = 3
index <- ceiling(1:p / size.groups)
X = matrix(rnorm(n * p), ncol = p, nrow = n)
beta = (-2:2)*10
y = X[,1:5] %*% beta + 0.1*rnorm(n)

#_________ SAVING DATA TO MATLAB FORMAT _____________#
y.filename <- paste("y", ".mat", sep = "")
X.filename <- paste("X", ".mat", sep = "")
idx.filename <- paste("index", ".mat", sep = "")
writeMat(y.filename, y = y)
writeMat(X.filename, X = X)
writeMat(idx.filename, index = index)
#____________________________________________________#

#_________ DATA AND PARAMETERS _____________#
data = list(x = X, y = y)
maxit = 1000 
thresh = 0.001 
min.frac = 0.1
nlam = 20
gamma = 0.8
standardize = TRUE
verbose = FALSE
step = 1
reset = 10
alpha = 0.95
lambdas = c(0, 1, 2, 3)
type = "linear"

Fit = SGL(data, index, type = "linear", lambdas = lambdas, standardize = FALSE)