X = arrayfun(@(x)bin(x,6),[0:63]','UniformOutput',false);
X = cell2mat(X);

Y = arrayfun(@(x)bin(s1(x),4),[0:63]','UniformOutput',false);
Y = cell2mat(Y);

D = zeros(64,16);

for i = 0:63
        XP = arrayfun(@(x)xor(bin(i,6),bin(x,6)),[0:63]','UniformOutput',false);
        XP = cell2mat(XP);

        xt = arrayfun(@(x)dec(xor(bin(i,6),bin(x,6))),[0:63]','UniformOutput',false);
        xt = cell2mat(xt);

        YP = arrayfun(@(x)bin(s1(x),4),xt,'UniformOutput',false);
        YP = cell2mat(YP);

        j = xor(Y,YP);
        j = dec(j);

        for k = 0:15
                D(i+1,k+1) = D(i+1,k+1) + size(find(j==k),1);
        end
end
csvwrite('s1_ddt.csv',D);
