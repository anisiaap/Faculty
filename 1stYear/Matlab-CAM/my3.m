h=50;
r=1;
n=6;
[x1,y1,z1 ]=cylinder([r 0], n);
myz1=z1*h;
surf(x1,y1,myz1)
hold on

[x2,y2,z2 ]=cylinder([0 r], n);
myz2=z2*h;
surf(x2,y2,myz2+h)
hold on

[x3,y3,z3 ]=cylinder([r 0], n);
myz3=z3*h;
surf(x3,y3,myz3+2*h)
hold on

[x4,y4,z4 ]=cylinder([0 r], n);
myz4=z4*h;
surf(x4,y4,myz4+3*h)
hold on

[x5,y5,z5 ]=cylinder([r 0], n);
myz5=z5*h;
surf(x5,y5,myz5+4*h)
hold on
