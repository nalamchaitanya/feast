function out = fiest(inp,key)
    left = inp([1:16]);
    right= inp([17:32]);
    nleft=right;
    nright=xor(fiestF(right,key),left);
    out = [nleft nright];
end
