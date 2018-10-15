rm(list = ls())
#install.packages("SGL")
#install.packages("R.matlab")
require("SGL")
require("R.matlab")
#setwd("/Users/striaukas/Documents/GitHub/midas_lasso_shapre_rest/nlapprox")
setwd("C:/Users/Z440/Documents/GitHub/midas_lasso_shapre_rest/nlapprox")

n = 50; p = 2000; size.groups = 100
index <- ceiling(1:p / size.groups)
X = matrix(rnorm(n * p), ncol = p, nrow = n)
beta = (-2:2)*10
y = X[,1:5] %*% beta + 0.1*rnorm(n)

#_________ SAVING DATA TO MATLAB FORMAT _____________#
y.filename <- paste("rdata/y", ".mat", sep = "")
X.filename <- paste("rdata/X", ".mat", sep = "")
idx.filename <- paste("rdata/index", ".mat", sep = "")
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
lambdas = c(0, 1, 2, 3, 100)
type = "linear"

Fit = SGL(data, index, type = "linear", lambdas = lambdas, standardize = FALSE)
Rbeta <- paste("rdata/Rbeta", ".mat", sep = "")
writeMat(Rbeta, rbeta = Fit$beta)
