%prob 2
dom=[2, 5];
y0=0.1;
[xval, fval]=ode45('ftest', dom, y0);
plot( xval, fval(:,1),'-o')

%prob 3

vx=[ 0.2 -5.1 2 1.3 2.9 -0.5];

Px=polyfit(xval,fval,2);
vy1=polyval(Px, vx)
vy2=spline(xval, fval, vx)


