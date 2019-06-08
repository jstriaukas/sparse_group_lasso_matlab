function [ id ] = Get_MBB_ID( T, L )
%Get_MBB_ID obtains ids of resampled observations using a
%moving block bootstrap with blocks of length L
    id = zeros(T,1);
	id(1) = ceil(T*rand(1,1));
	for t = 2:T
		if rem(t,L) == 0
			id(t) = ceil(T*rand(1,1));
		else
			id(t) = id(t-1)+1;
        end
        if id(t) > T
				id(t) = 1;
        end	
    end
end
	
