function val = s1(num)
        s=csvread('s1.csv');
        y = de2bi(num,6);
        x = bi2de(y(1,[1,6]));
        y = bi2de(y(1,[2,3,4,5]));
        val = de2bi(s(x+1,y+1),4);
end
