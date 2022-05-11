function  [lamda, vect, vect2, vect3, vect4, sing]=my5(A)
lamda=eig(A)
[line, col ]=size(A);
[vect, val ]=eig(A);

if line==col
    for i=1:length(vect)
        sing=[];
        vect2(:,i)=2*vect(:,i);
        vect3(:,i)=3*vect(:,i);
        vect4(:,i)=4*vect(:,i);
    end
else 
    sing=sdv(A);
    vect2=[];
    vect3=[];
    vect4=[];
   
end
vect
vect2
vect3
vect4
sing
lamda
