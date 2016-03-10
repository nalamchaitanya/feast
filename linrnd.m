function [out,b,c] = linrnd(inp,rnd)
    b = 1;
    c = 0;
    in = inp;
    linout = zeros(rnd+1,32);
    linout(1,:)=in;
    for i = 1:rnd
        [out,bias,cnt]=lincrp(in);
        linout(i+1,:)=out;
        c = c + cnt;
        b = b*bias;
        in = out;
    end
    b = b/2;
    csvwrite('lin_trial.csv',linout);
end
