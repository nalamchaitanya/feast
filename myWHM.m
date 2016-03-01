function w = myWHM(n)
        w = hadamard(2^n);
        w(w==-1)=0;
