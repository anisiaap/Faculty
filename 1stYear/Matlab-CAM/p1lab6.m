% setarea preciziei de calcul
options=optimset('Tolx',10^(-6));
% calcularea solutiei
[x,fval,exitflag,output]=fzero('f1',-3,options); 
% solutia
x
% numarul de iteratii
iter=output.iterations 