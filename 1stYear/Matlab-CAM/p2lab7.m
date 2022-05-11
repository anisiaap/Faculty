theta=0:pi/60:2*pi; r=sqrt(4);
x=r*cos(theta);
y=r*sin(theta);
plot(x,y,'r--')
hold on 
% x-y=1 => y=x-1
x1=-3:0.1:3; y11=x1-1;
plot(x1,y11,'b') 
axis equal, grid, hold on
[xcoord,ycoord]=ginput(2); 


disp('solutiile sistemului')
for i=1:length(xcoord)
 sol=fsolve('f_syst',[xcoord(i),ycoord(i)])
end 