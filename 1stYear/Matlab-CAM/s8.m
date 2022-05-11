t0=[0 0.2 -0.1];
dom=[0 3];
[xval, yval]=ode45('f8', dom, t0)
%{
theta=0:pi/60:2*pi; r=sqrt(4);
x=r*cos(theta);
y=r*sin(theta);
plot(x,y,'r--')
hold on
plot(x, x-1)
hold on
[xcoord, ycoord]=ginput(2)
for i=1:length(xcoord)
    sol=fsolve('f8', [xcoord(i), ycoord(i)])
end

x=3.1:0.1:5;
plot(x,2.^(-sin(x)),x,x.*log(x)-4)
[xcoord, ycoord]=ginput(1)
[x, fval, exitflag, output ]=fzero('f8', xcoord)

%}