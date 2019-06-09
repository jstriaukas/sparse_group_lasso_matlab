function lambdas = betterPathCalc(y,x,index,alpha,minFrac,nlam,varargin)


[standardize] = ...
    process_options(varargin,'standardize',false);

if (standardize == true)
    X = x;
    means = mean(X,1);
    m = repmat(means,size(X,1),1);
    X = (X - m);
    vars = sqrt(sum(X.^2,1));
    X = X./vars;
    x = X;
    X_transform.Xscale = vars;
    X_transform.Xmeans = means;
end

[n, p] = size(x);
X = x;
resp = y;

%_ preparing for C++ _%
groups = unique(index);
numGroup = length(groups);
rangeGroupInd = zeros((numGroup+1),1);
for i = 1:numGroup
    rangeGroupInd(i,:) = find(index == groups(i), 1 ) - 1;
end
rangeGroupInd(numGroup+1) = p;
groupLen = diff(rangeGroupInd);

lambda_max = zeros(numGroup,1);


if ((alpha>0)&&(alpha<1))
    for i = 1:numGroup
        
        ind = groups(i);
        X_fit = X(:,index == ind);
        cors = X_fit' * resp;
        ord_cors = sort(abs(cors), 'descend');
        
        if (length(ord_cors) > 1)
            norms = zeros(0,length(cors)-1,1);
            lam = ord_cors/alpha;
            
            for j = 1:(length(ord_cors)-1)
                norms(j) = sqrt(sum((ord_cors(1:j)-ord_cors(j+1)).^2));
            end
            if(norms(1) >= lam(2) * (1-alpha)*sqrt(groupLen(i)))
                our_cors = ord_cors(1);
                our_range = [ord_cors(2), ord_cors(1)]/alpha;
            else
                if(norms(length(ord_cors)-1) <= lam(length(ord_cors)) * (1-alpha)*sqrt(groupLen(i)))
                    our_cors  = ord_cors;
                    our_range = [0, ord_cors(length(ord_cors))]/alpha;
                else
                    temp1 = norms(:,1:end-1)';
                    temp2 = lam(2:(length(norms)))*(1-alpha)*sqrt(groupLen(i));
                    temp3 = find((temp1<=temp2)==1);
                    my_ind = max(temp3) + 1;
                    our_cors = ord_cors(1:my_ind);
                    our_range = [ord_cors(my_ind+1), ord_cors(my_ind)]/alpha;
                    
                end
            end
            nn = length(our_cors);
            if(alpha == 0.5)
                alpha = 0.500001;
            end
            A_term = nn*alpha.^2 - (1 - alpha).^2*groupLen(i);
            B_term = - 2 * alpha * sum(our_cors);
            C_term = sum(our_cors.^2);
            
            lams = [(-B_term + sqrt(B_term^2 - 4 * A_term * C_term))/(2*A_term), (-B_term - sqrt(B_term^2 - 4 * A_term * C_term))/(2*A_term)];
            ind1 = (lams >= our_range(1));
            ind2 = (lams <= our_range(2));
            temp = lams((ind1.*ind2)==1);
            lambda_max(i,:) = min(temp);
        elseif (length(ord_cors) == 1) % if (length(ord_cors) > 1)
            lambda_max(i,:) = ord_cors;
            
        end %if (length(ord_cors) > 1)
        
    end % end of for loop
end % end of 0<alpha<1

if(alpha == 1)
    lambda_max = abs(X' * resp);
end

if(alpha == 0)
    for i = 1:numGroup
        ind = groups(i);
        X_fit = X(:,index == ind);
        cors = X_fit' * resp;
        lambda_max(i,:) = sqrt(sum(cors.^2)) / sqrt(groupLen(i));
    end
end

max_lam = max(lambda_max);
min_lam = minFrac*max_lam;
logmax = log(max_lam);
logmin = log(min_lam);
diff_ = (logmin-logmax)/(nlam-1);
lambdas = exp(logmax:diff_:logmin);
lambdas = lambdas./n;
