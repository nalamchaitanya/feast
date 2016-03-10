function out = fiestF(right,key)
    eright = Exp(right);
    keymix = xor(eright,key);
    sbst = zeros(1,16);
    sbst([1:4])   = s1(bi2de(keymix([1:6])));
    sbst([5:8])   = s1(bi2de(keymix([7:12])));
    sbst([9:12])  = s1(bi2de(keymix([13:18])));
    sbst([13:16]) = s1(bi2de(keymix([19:24])));
    out = diffu(sbst);
end
