function out = diffu(in)
    x = csvread('diffu.csv');
    out = in(x);
end
