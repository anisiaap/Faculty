t=0:0.1:6*3.14;
f=sqrt(sin(t)+t.*t);
r=f;
polar(t, r, 'r-')