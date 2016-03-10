function a = rounds(rnds)
    key = zeros(1,32);
    freq = zeros(32,1);
    z = eye(32);
    for j = 1:32
        Z = z(j,:);
        for i = 1:1000
            X = randi(2,1,32)-1;
            Y = xor(enc(X,key,rnds),enc(xor(X,Z),key,rnds))
            y = sum(Y')
            freq(y) = freq(y)+1;
        end
    end
    csvwrite('freq.csv',freq);
    hold on;
    scatter([1:32]',freq/sum(freq));
    nck = arrayfun(@(x)nchoosek(32,x),[1:32]','UniformOutput',false);
    nck = cell2mat(nck);
    plot([1:32]',nck/sum(nck));
    saveas(gcf,'freq.png');
end
