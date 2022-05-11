function lab8(x,y)
if length(x)~=length(y)
disp('lungimile nu corespund');
else
   for i=1:length(x)
      vx=x(i):0.1:y(i);
      vy1=spline(x,y,vx); 
      vy2=interp1(x,y,vx,'cubic');
      plot(x,y,'ro',vx,vy1,'g',vx,vy2,'r-')
legend('puncte','spline cubic','Hermite cubic') 
   end
end
end