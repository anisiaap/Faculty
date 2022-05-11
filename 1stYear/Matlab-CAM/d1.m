function dy=d1(x,y)
dy=zeros(3,1);
dy(1)=-2*y(1)+y(2)-2*y(3)+sin(x);
dy(2)=-2*y(2)+x(1)+2*y(3)-cos(x);
dy(3)=5*y(3)+3*y(1)-3*y(2);