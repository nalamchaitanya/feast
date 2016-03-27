s=zeros(1,64);
for i = 0:63
    s(1,i+1)=bi2de(s1(i));
end
csvwrite('s1_arr.csv',s);
