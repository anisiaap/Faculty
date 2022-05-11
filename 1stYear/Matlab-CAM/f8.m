function dy=f8(x,y)
dy=zeros(3,1);
 dy=[-2*y(1)+y(2)-2*y(3)+sin(x);
        -2*y(2)+x(1)+2*y(3)-cos(x);
        5*y(3)+3*y(1)-3*y(2)]; 
end
%{
function f=f8(x,y)
if length(x)~=length(y)
    disp('lungimile nu corespund');
else 
    vx=min(x):(max(x)-min(x))/100:max(x);
    vy1=spline(x, y, vx)
    vy2=interp1(x, y, vx, 'cubic')
    plot(x,y,'ro',vx,vy1,'g',vx,vy2,'b--')
end
%}
%x=v(1);
%y=v(2);
%f=[x.^2+y.^2-4; x-y-1];
%f=2.^(-sin(x))-x.*log(x)+4;