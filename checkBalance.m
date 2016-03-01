function y = checkBalance(x)
temp1 = numel(find(x));
temp2 = numel(find(~x));
if temp1 == temp2
	y = 0;
else
	y = 1;
end