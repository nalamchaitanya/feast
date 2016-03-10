function out = Exp(in)
    x = csvread('exp.csv');
    out = in(x);
end
