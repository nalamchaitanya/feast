function ff = fiestF(right,key)
    eright = exp(right);
    keymix = xor(eright,key);
    sbst = zeros(1,16);
    sbst([1:4])   = s1(keymix([1:6]));
    sbst([5:8])   = s2(keymix([7:12]));
    sbst([9:12])  = s3(keymix([13:18]));
    sbst([13:16]) = s4(keymix([19:24]));
    out = diffu(sbst);
end
