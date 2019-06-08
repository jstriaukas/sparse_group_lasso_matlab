# SGL predict function internal:
cvSGL.predict.internal <- function(obj, newx, s="lambda.1se"){
  l<-getmin(obj$lambdas,obj$lldiff,obj$llSD)
  if(s=="lambda.1se"){lam <- l$lambda.1se} else {lam <- l$lambda.min}
  idx <- which(obj$lambdas==lam)
  fit <- obj$fit
  X <- newx
  if (!is.null(obj$X.transform)) {
    if (is.matrix(X)) {
      X <- t(t(newX) - obj$X.transform$X.means)
      X <- t(t(X)/obj$X.transform$X.scale)
    }
    if (is.vector(X)) {
      X <- X - obj$X.transform$X.means
      X <- X/obj$X.transform$X.scale
    }
  }
  intercept <- fit$intercept
  if(is.null(intercept)) {intercept <- 0}
  if (is.matrix(X)) {
    eta <- X %*% fit$beta[, idx] + intercept
  }
  if (is.vector(X)) {
    eta <- sum(X * fit$beta[, idx]) + intercept
  }
  y.pred <- eta
  return(y.pred)
}

# cvSGL saves transformations...
cvSGL.internal <- function(data, index = rep(1, ncol(data$x)), type = "linear", 
                           maxit = 1000, thresh = 0.001, min.frac = 0.05, nlam = 20, 
                           gamma = 0.8, nfold = 10, standardize = TRUE, verbose = FALSE, 
                           step = 1, reset = 10, alpha = 0.95, lambdas = NULL,block.cv = FALSE) {
  X.transform <- NULL
  if (standardize == TRUE) {
    X <- data$x
    means <- apply(X, 2, mean)
    X <- t(t(X) - means)
    var <- apply(X, 2, function(x) (sqrt(sum(x^2))))
    X <- t(t(X)/var)
    data$x <- X
    X.transform <- list(X.scale = var, X.means = means)
  }
  if (type == "linear") {
    if (standardize == TRUE) {
      intercept <- mean(data$y)
      data$y <- data$y - intercept
    }
    Sol <- linCrossVal(data, index, nfold = nfold, maxit = maxit, 
                       thresh = thresh, min.frac = min.frac, nlam = nlam, 
                       lambdas = lambdas, gamma = gamma, verbose = verbose, 
                       step = step, reset = reset, alpha = alpha, block.cv = block.cv)
    if (standardize == TRUE) {
      Sol$fit = list(beta = Sol$fit$beta, lambdas = Sol$fit$lambdas, 
                     intercept = intercept, step = step)
    }
  }
  Sol = list(fit = Sol$fit, lldiff = Sol$lldiff, lambdas = Sol$lambdas, 
             type = type, llSD = Sol$llSD, X.transform = X.transform)
  class(Sol) = "cv.SGL"
  return(Sol)
}