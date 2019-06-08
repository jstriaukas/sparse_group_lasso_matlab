function [ omega ] = QS( y)
%Returns columnwise QS HAC estimator of the variance
    [T,N] = size(y);
    bw = 1.3*T^(1/5);
    weight = QS_Weights((1:T-1)/bw);
    omega = zeros(1,N);
    for i=1:N
        workdata = y(:,i)-mean(y(:,i));
        omega(i)= workdata'*workdata/T;
        for j=1:T-1
            omega(i) = omega(i) + 2*weight(j)*(workdata(1:T-j)'*workdata(j+1:T))/T;
        end
    end
end

