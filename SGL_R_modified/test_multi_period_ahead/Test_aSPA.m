function [ t_aSPA, p_value ] = Test_aSPA( LossDiff, weights, L)
% [t_aSPA, p_value ] = Test_aSPA ( LossDiff, weights, L )
% Implements the test for Average SPA of Quaedvlieg (2018). 
% Lossdiff is the [TxH] forecast path loss differential.
% Weight is the [1xH] vector of weights for the losses at different horizons.
% L is the parameter for the moving block bootstrap. 
% Returns the statistic as well as the p-value. 

[t_aSPA, t_aSPA_b] = Bootstrap_aSPA( LossDiff, weights, L);
p_value = mean(t_aSPA < t_aSPA_b);

end


