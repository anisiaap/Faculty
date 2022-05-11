function [a,b,c,d]=my2(A)
[line, col ]=size(A);

if line>=2

    a=A(2,:);
    b=transpose(a);
    c=3.*a;
    d=0;
    for i=1:length(a)
        d=d+a(i);
    end
end