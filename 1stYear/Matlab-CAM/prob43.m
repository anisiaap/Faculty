function [X]=prob43(A,B)
[line, col]=size(A);
if rank(A)==rank([A B]) & line==col
    X=inv(A)*B
elseif rank(A)==rank([A B])
    X=pinv(A)*B
end
end