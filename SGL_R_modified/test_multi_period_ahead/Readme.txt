Matlab code for the tests introduced in 'Quaedvlieg (2018), Multi-Horizon Forecast Comparison.'

'Example_data.mat' is a set of loss-differences for horizons H=1,...,20. LossDiff_aSPA is a set that has aSPA, but not uSPA, while LossDiff_uSPA has both. 

'Test_aSPA' and 'Test_uSPA' can directly be called on the data, and are implemented as in the paper with a moving block bootstrap.

Example Code:
[t_uSPA, p_uSPA] = Test_uSPA(LossDiff_uSPA, 3);
[t_aSPA, p_aSPA] = Test_aSPA(LossDiff_uSPA, ones(1,20)/20, 3);