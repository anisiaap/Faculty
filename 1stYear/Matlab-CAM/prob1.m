function [Z1,Z2]=prob1(Z)
%Z=[2-3i,-i ; 4+7i, 5];
Z1=Z';
Z2=Z.';
disp(Z1);
disp(Z2);

%{
Se observa ca operatorul .' (punct-apostrof) genereaza transpusa unei 
matrice cu elemente numere complexe, pe când operatorul ' (apostrof)
genereaza conjugata transpusei matricei respective.
%}