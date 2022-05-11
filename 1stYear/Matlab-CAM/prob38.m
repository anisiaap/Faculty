x=-3:0.1:3;
y=-3:0.1:3;
[x,y]=meshgrid(x,y);
z=x.^3-3.*x.*y.*y;

subplot(3,1,1)
plot3(x,y,z)
title('plot3')

subplot(3,1,2)
mesh(x,y,z)
title('mesh')

subplot(3,1,3)
surfl(x,y,z)
title('surf')