A=[1 -1;3 2 ];
lamda=eig(A);

[vec, val]=eig(A);
[line, col ]=size(vec);

for i=1:col
    