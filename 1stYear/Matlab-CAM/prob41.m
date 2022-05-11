A=[4 3 -1; -1 1 1; 1 0 3];
B=[2; 0; -1];

if rank(A)==rank([A B])
    X=inv(A)*B

end