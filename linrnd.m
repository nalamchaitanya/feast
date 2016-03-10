function [out,b,c] = linrnd(inp,rnd)
    b = 1;
    c = 0;
    in = inp;
    for i = 1:rnd
        [out,bias,cnt]=lincrp(in);
        c = c + cnt;
        b = b*bias;
        in = out;
    end
    b = b/2;
end
