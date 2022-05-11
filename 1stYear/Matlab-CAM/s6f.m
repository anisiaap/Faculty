plot(x, exp(sin(x)), 'r-', x, cos(x)+0.6, 'cs-')
[xcoord, ycoord]=ginput(2);
for i=1:length(xcoord)
    sol=fsolve('s6', [xcoord(i) ycoord(i)])
end