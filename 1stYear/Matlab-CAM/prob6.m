clear, clc
% graph
x=-8:0.1:10; 
y= (x/4).^2-sin(x)-0.5;
plot(x,y)
% function -f for determining the local maximums g=@(x) -fct(x);
% determining the extreme points and the local minimums and maximums
[xmin1,fmin1]=fminbnd(y,-6,-3);
fprintf('minimum point: %g, minimum: %g\n',xmin1,fmin1)
[xmax1,fmax1]=fminbnd(g,-3,-1);
fprintf('maximum point: %g, maximum: %g\n',xmax1,-fmax1)
[xmin2,fmin2]=fminbnd(y,0,3);
fprintf('minimum point: %g, minimum: %g\n',xmin2,fmin2)
[xmax2,fmax2]=fminbnd(g,4,6);
fprintf('maximum point: %g, maximum: %g\n',xmax2,-fmax2)
[xmin3,fmin3]=fminbnd(y,6,8);
fprintf('minimum point: %g, minimum: %g\n',xmin3,fmin3)