t=-9:0.1:3;
if t<-3 | t>3
    y=sin(5*t);
else y=cos(t)-cos(3)-sin(15);
end
subplot(2,1,1);
plot(t, y, 'g-')
xlabel('x'); ylabel('y');
grid;

x=-3:0.1:3;
f=sin(3.14*x).*cos(3.14*x);
g=sin(3.14*x+1).*cos(3.14*x+1);
subplot(2,1,2);
plot(x,f,'m--',x,g,'cs-')