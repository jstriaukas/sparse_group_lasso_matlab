function omega = MBB_Variance( y, L )
% Computes the 'natural variance' estimator of the resampled data.
	[T,N] = size(y);
	omega = zeros(1,N);
	ydem = y - repmat(mean(y,1),T,1);
    K = floor(T/L);
    for n = 1:N
        temp = reshape(ydem(1:K*L,n), [K, L]);
        omega(n) = mean(sum(temp,1).^2)/L;
	end
end
