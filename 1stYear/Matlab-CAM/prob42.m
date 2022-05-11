%{
A=[4 3 -1;-1 1 1;1 0 3; 4 4 3];
B=[2; 0; -1; 1];
if rank(A)==rank([A B])
    X=pinv(A)*B
end
%}
C=[-6 8 -1;2 0 -3];
D=[-5; 7];
if rank(C)==rank([C D])
    X=pinv(C)*D
end
