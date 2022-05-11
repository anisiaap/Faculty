function f=f2(x,y)
if length(x)~=length(y)
    disp('lungimile nu corespund');
else 
for i=1:length(x)
    vx=x(i):0.1:y(i);
    vx1=spline(x,y,vx);
    vx2=interp1(x,y,vx,'cubic');
    P2=polyfit(x,y,2);
    vx3=polyval(P2, vx);
    P5=polyfit(x,y,5);
    vx4=polyval(P5, vx);
    plot(x,y,vx, vx1, vx, vx2, vx, vx3,vx, vx4)
    hold on 
    legend('puncte','spline cubic','Hermite cubic','parab', '5th') 
end
end 
end


%function f=f2(v)

%f=v(1)/(v(1).^2+v(2).^2+v(3).^2+1);



%f=exp((-x).^2)-log(1-x+x.^2./3);
