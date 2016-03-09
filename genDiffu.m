function a = diffu()
    Z=[0; 4; 8; 12;];
    Z=repmat(Z,1,4);
    iter=0;
    while 1
        Y = [randperm(4);randperm(4);randperm(4);randperm(4);];
        t = 0;
        iter = iter+1;
        for i = 1:4
            for j = 1:4
                if(size(find(Y(:,i)==j),1)~=1)
                    t=1;
                    break;
                end
            end
            if t==1
                break;
            end
        end
        if t==0
            break;
        end
    end
    a = (Y + Z);
    a = a([1:16]);
    csvwrite('diffu.csv',a);
end
