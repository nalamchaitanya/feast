function [out,b,c] = difrnd(inp,rnd)
    b = 1;
    c = 0;
    in = inp;
    diffout = zeros(rnd+1,32);
    diffout(1,:)=in;
    for i = 1:rnd
        [out,bias,cnt]=difcrp(in);
        diffout(i+1,:)=out;
        c = c + cnt;
        b = b*bias;
        in = out;
    end
    csvwrite('diff_trial.csv',diffout);
end
