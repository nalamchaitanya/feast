function out = exp(in)
    x = csvread('exp.csv');
    out = in(x);
end
