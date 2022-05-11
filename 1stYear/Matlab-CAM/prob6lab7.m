x=-6:0.1:6;

f=sin(x)+sqrt(abs(x));
plot( x,f, 'r-')
g=@(x) -f(x);


[xmax1,fmax1]=fminbnd(g,-6,-4);
fprintf('punct de maxim: %g, maximul: %g\n',xmax1,-fmax1)
[xmin1,fmin1]=fminbnd(f,-2,-0.5);
fprintf('punct de minim: %g, minimul: %g\n',xmin1,fmin1)
[xmax2,fmax2]=fminbnd(g,-0.5,0);
fprintf('punct de maxim: %g, maximul: %g\n',xmax2,-fmax2)
[xmin2,fmin2]=fminbnd(f,-0.2,0.2);
fprintf('punct de minim: %g, minimul: %g\n',xmin2,fmin2)
[xmax3,fmax3]=fminbnd(g,1,3);
fprintf('punct de maxim: %g, maximul: %g\n',xmax3,-fmax3) 
[xmin3,fmin3]=fminbnd(f,3.5,5.5);
fprintf('punct de minim: %g, minimul: %g\n',xmin3,fmin3)