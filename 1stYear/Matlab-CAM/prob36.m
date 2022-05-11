teta=0:0.1:2.1*pi;  

r=2;
x1=0+r*cos(teta);
y1=0+r*sin(teta);

line(x1,y1,'color', 'red')
a=1.5;
b=2.5;
x2=0+a*cos(teta);
y2=0+b*sin(teta);

line(x2,y2)
grid;