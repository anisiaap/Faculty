Puncte=[5 4;-7 4;-7 -3;5 -3;5 4]
subplot(2,1,1)
line(Puncte(:,1),Puncte(:,2))
grid;
%
subplot(2,1,2)
fill(Puncte(:,1),Puncte(:,2),'r')
grid;