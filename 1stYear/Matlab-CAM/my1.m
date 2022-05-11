function [A, detA, rankA, transA]=my1(v1,v2,v3)
[lin1,col1]=size(v1);
[lin2,col2]=size(v2);
[lin3,col3]=size(v3);

if lin1==1 | lin2==1 |lin3==1|col1==3 | col2==3 |col3==3
    A=[v1; v2; v3]
    detA=det(A)
    rankA=rank(A)
    transA=transpose(A)
end