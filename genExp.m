function a = genExp()
    iter=0;
    while 1
        Y = randi([1,16],1,24);
        t = 0;
        iter = iter+1;
        for i = 1:16
            if(or((size(find(Y==i),2)<1),(size(find(Y==i),2)>2)))
                t=1;
                break;
            end
            if t==1
                break;
            end
        end
        if t==0
            break;
        end
    end
    a = Y;
    iter
    csvwrite('exp.csv',a);
end
