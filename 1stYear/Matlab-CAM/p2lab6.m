x=0:0.1:10;
plot(x, exp(cos(x)),'b-', x, sin(x)+1,'c:');
[x0,y0]=ginput(2);
x1=fzero('f1', x(1))
x2=fzero('f1', x(2))  
