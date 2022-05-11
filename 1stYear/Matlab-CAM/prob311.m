function prob311(r)
if r<=0
    r=1;
end
r1=r;
r2=0.5*r;
r3=2*r;
n=15;
h=8;

[x1,y1,z1]=cylinder([r1 r2], n);
Z1=z1*h;
surf(x1,y1,Z1)
colormap('autumn')

hold on
[x2,y2,z2]=cylinder([r2 r3], n);
Z2=z2*h+h;
surf(x2,y2,Z2)
colormap('cool')
hold on
[x3,y3,z3]=cylinder([r3 0], n);
Z3=z3*h+2*h;
surf(x3,y3,Z3)
colormap('summer')
hold on

