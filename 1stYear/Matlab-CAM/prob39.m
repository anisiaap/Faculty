rc1=1;
rc2=2;
h=3;
n=10;
[xp,yp,z]=cylinder([rc1 rc2],n);
zp=h*z;
surf(xp,yp,zp)
colormap('summer')
hold on

rp=3;
nn=6;
[xpp,ypp,zz]=cylinder([rp 0], nn);
zpp=zz*h;
surf(xpp, ypp, zpp)

