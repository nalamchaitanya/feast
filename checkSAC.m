function y = checkSAC()
	arr1 = zeros(64,4);
	arr2 = zeros(1,6);
	arr3 = zeros(1,4);
	arr4 = zeros(1:6);
	for i = 1:6
		arr2(i) = 1
		disp('new round');
		for j = 0:63
			arr1(j+1,:) = xor( de2bi(s1(j),4) , de2bi(s1(bi2de( xor(de2bi(j,6),arr2) ) ) , 4) );
		end
		disp(arr1);
		arr2(i) = 0;
	
		if checkBalance(arr1(:,1)) ~= 0
			arr3(1) = 1;
		end
	
		if checkBalance(arr1(:,2)) ~= 0
			arr3(2) = 1;
		end
	
		if checkBalance(arr1(:,3)) ~= 0
			arr3(3) = 1;
		end
	
		if checkBalance(arr1(:,4)) ~= 0
			arr3(4) = 1;
		end
	
		if(sum(arr3) > 0 )
			arr4(i) = 1;
		end

	end
	if sum(arr4) > 0
		y = 1;
	else
		y = 0;
	end
end