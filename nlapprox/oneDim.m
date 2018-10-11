function out = oneDim(y,x,index,thresh,inner_iter, ...
    outer_iter, outer_thresh, minFrac, ...
    nlam,lambdas,gamma,verbose, ...
    step,reset,alpha)
if(isempty(lambdas))
    lambdas = [1, 2, 3];
    % not yet implemented:
    %lambdas = betterPathCalc(data = data, index = index, alpha=alpha, min.frac = min.frac, nlam = nlam, type = "linear")
end

X = x;
y = y;
[n,p] = size(X);

%_ Set up the group lasso _%

[~,ord] = sort(index);
index = index(ord);
X = X(:,ord);
[~,unOrd]=ismember(1:length(ord),ord);

%_ preparing for C++ _%
groups = unique(index);
num_groups = length(groups);
range_group_ind = zeros((num_groups+1),1);
for i = 1:num_groups
    range_group_ind(i,:) = find(index == groups(i), 1 ) - 1;
end
range_group_ind(num_groups+1) = p;
group_length = diff(range_group_ind);

nlam = length(lambdas);
beta_old = zeros(p,1);
beta_is_zero = ones(num_groups,1);
eta = zeros(n,1);

%_Loop through Lambdas_%
for k = 1:nlam
      %beta_is_zero = ones(num_groups,1);
      %beta_old = zeros(p,1);
      %eta = zeros(n,1);
      lambda1 = lambdas(k)*alpha;
      lambda2 = lambdas(k)*(1-alpha);
      beta = beta_old;
      junk = linNest(X,y,index,n,p,...
          num_groups,range_group_ind,group_length,...
          lambda1,lambda2,...
          beta,...
          inner_iter,outer_iter,thresh,outer_thresh,...
          eta,gamma,...
          beta_is_zero,step,reset);
      
      beta_new  = junk.beta;
      beta(:,k) = beta_new;
      beta_is_zero = junk.betaIsZero;
      eta = junk.eta;
      beta_old = beta.new;
      if(verbose)
        disp(["*** Lambda - ", num2str(k), " ***"]);
      end
end
    
out = 1;




