x=3.1:0.1:5;
plot(x,2.^(-sin(x)), 'b-', x, -4+x.*log(x), 'r:');
[x0, y0]=ginput(1);
x=fzero('f1', x(1))
x
