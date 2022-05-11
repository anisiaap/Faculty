rs=6371;
[x,y,z]=sphere(360/15);
X=x*rs;
Y=y*rs;
Z=z*rs;
surf(X,Y,Z)
