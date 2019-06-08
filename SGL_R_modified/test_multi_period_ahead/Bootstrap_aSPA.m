function [ t_aSPA, t_aSPA_b ] = Bootstrap_aSPA( Loss_Diff, weights, L)
% Implements Bootstrap Algorithm 1 for the test for Average SPA of Quaedvlieg (2018). 
% Bootstrap is based on a Moving Block Bootstrap with parameter L.
% Weights are the weights on the various horizons, size conforming to Loss_Diff.
B = 999;
T = size(Loss_Diff,1);

Weighted_Loss_Diff = sum(repmat(weights, T, 1).*Loss_Diff,2);
d_ij = mean(Weighted_Loss_Diff,1);
t_aSPA = sqrt(T)*d_ij./sqrt(QS(Weighted_Loss_Diff));

t_aSPA_b = zeros(B,1);
Demeaned_Loss_Diff = Weighted_Loss_Diff-repmat(d_ij,T,1);
for b = 1:B
    id = Get_MBB_ID(T, L);
    b_lossdiff = Demeaned_Loss_Diff(id,:);
    zeta_b = MBB_Variance(b_lossdiff,L);
    t_aSPA_b(b) = sqrt(T)*( mean(b_lossdiff, 1))/sqrt(zeta_b);
end








