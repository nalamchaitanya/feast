function nl = nonLinearity(Y)
        dim = 6;
        w = myWHM(6);
        s = arrayfun(@(x)s1(x),[0:63]);
        s = de2bi(s,4);
        nl = zeros(1,4);
        for i = 1:4
                temp = repmat(s(:,i),1,64);
                temp = xor(temp,w);
                nl(1,i) = min(sum(temp));
        end
