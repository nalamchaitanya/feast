function [sin,bias,cnt] = getHB(inp)
    bias = 1;
    cnt = 0;
    inp = inp([17:32]);
    inp = Exp(inp);
    s1 = csvread('s1_lat.csv');
    s1 = s1 - 32;
    s1 = abs(s1/64);
    z = zeros(1,16);
    for i = 1:4
        x = dec(inp([(i-1)*6+1:i*6]));
        x = x+1;
        y = find(s1(x,:)==max(s1(x,:)));
        y = y(1,1);
        if x ~= 1
            cnt = cnt +1;
            bias = s1(x,y)*bias*2;
        end
        y = y-1;
        z([(i-1)*4+1:i*4]) = de2bi(y,4);
    end
    sin = z;
end
