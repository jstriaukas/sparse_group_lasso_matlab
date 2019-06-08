function [ t_uSPA, t_uSPA_b ] = Bootstrap_uSPA( Loss_Diff, L )
% Implements Bootstrap Algorithm 1 for the test for Uniform SPA of Quaedvlieg (2018). 
% Bootstrap is based on a moving block bootstrap with length L. 
B = 999;
T = size(Loss_Diff,1);

d_ij = mean(Loss_Diff,1);
t_uSPA = min(sqrt(T)*d_ij./sqrt(QS(Loss_Diff)), [] , 2);

t_uSPA_b = zeros(B,1);
Demeaned_Loss_Diff = Loss_Diff-repmat(d_ij,T,1);

for b = 1:B
    id = Get_MBB_ID(T, L);
    b_lossdiff = Demeaned_Loss_Diff(id,:);
    omega_b = MBB_Variance(b_lossdiff,L);
    t_uSPA_b(b) = min(sqrt(T)*mean(b_lossdiff,1)./sqrt(omega_b));
end






