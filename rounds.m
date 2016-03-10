function a = rounds(rnds)
    key = zeros(1,32);
    freq = zeros(32,1);
    for j = 1:32
        z = zeros(1,32);
        z(j)=1;
        z
        for i = 1:1000
            X = randi(2,1,32)-1;
            Y = xor(enc(X,key,rnds),enc(xor(X,z),key,rnds));
            y = sum(Y');
            freq(y) = freq(y)+1;
        end
    end
    csvwrite('freq.csv',freq);
    plot([1:32]',freq);
    saveas(gcf,'freq.png');
end
