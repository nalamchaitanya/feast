function [out,bias,cnt] = difcrp(inp)
    [sin,bias,cnt] = getDB(inp);
    left = inp([1:16]);
    righ = inp([17:32]);
    next = xor(diffu(sin),left);
    out = [righ next];
end
