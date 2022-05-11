function my4(r)
teta=-8:0.1:8;

if r~=0
    x1=0+r*cos(teta);
    y1=0+r*sin(teta);
    line(x1,y1,'color','cyan')
    hold on

    x2=0+r*2*cos(teta);
    y2=0+r*2*sin(teta);
    line(x2,y2,'color','red')
    hold on

    x3=0+r*3*cos(teta);
    y3=0+r*3*sin(teta);
    line(x3,y3,'color','green')
    hold on
end



