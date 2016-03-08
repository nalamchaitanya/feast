X = arrayfun(@(x)bin(x,6),[0:63]','UniformOutput',false);
X = cell2mat(X);

Y = arrayfun(@(x)bin(s1(x),4),[0:63]','UniformOutput',false);
Y = cell2mat(Y);

k = [X Y];

L = zeros(64,16);
for i = 0:63
        for j = 0:15
                temp = [bin(i,6) bin(j,4)]';
                temp = k*temp;
                temp(mod(temp,2)==0)=0;
                temp(mod(temp,2)==1)=1;
                temp = sum(temp);
                L(i+1,j+1) = temp;
        end
end
csvwrite('s1_lat.csv',L);
