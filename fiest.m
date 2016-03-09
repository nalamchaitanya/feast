function out = fiest(inp,key)
    left = a([1:16]);
    right= a([17:32]);
    nleft=right;
    nright=xor(fiestF(right,key),left);
    out = [nleft nright];
end
