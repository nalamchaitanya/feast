function out = enc(inp,key,rnds)
    keysch = keyExp(key,rnds);
    in = inp;
    for i = 1:rnds
        out = fiest(in,keysch(i,:));
        in = out;
    end
end
