function [ t_uSPA, p_value ] = Test_uSPA( LossDiff, L )
% [t_uSPA, p_value ] = Test_uSPA ( LossDiff, L )
% Implements the test for Uniform SPA of Quaedvlieg (2018). 
% Lossdiff is the [TxH] forecast path loss differential. 
% L is the parameter for the moving block bootstrap. 
% Returns the statistic as well as the p-value. 

[t_uSPA, t_uSPA_b] = Bootstrap_uSPA( LossDiff, L );

p_value = mean(t_uSPA < t_uSPA_b);

end

