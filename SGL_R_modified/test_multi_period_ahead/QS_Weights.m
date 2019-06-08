function [ wQS ] = QS_Weights( x )
%QS_WEIGHTS, from HAC() function
    argQS = 6*pi*x/5;
    w1 = 3./(argQS.^2);
    w2 = (sin(argQS)./argQS)-cos(argQS);
    wQS = w1.*w2;
    wQS(x == 0) = 1;
end

