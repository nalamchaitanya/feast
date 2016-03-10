function [out,bias,cnt] = lincrp(inp)
    [sin,bias,cnt] = getHB(inp);
    left = inp([1:16]);
    righ = inp([17:32]);
    next = or(diffu(sin),left);
    out = [righ next];
end
