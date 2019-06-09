function out = cvSGLpredict(obj, newx)

intercept = obj.intercept;
b = obj.CVSol.beta;
out = newx*b+intercept;
