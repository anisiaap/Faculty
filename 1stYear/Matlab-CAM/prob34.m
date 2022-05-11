function prob34(p)
%B
B=[0 0
0 2
2 1
0 0];

%A
A=[0 0
2 1
2 -1
0 0];

%F
F=[0 0
2 -1
0 -2
0 0];

%E
E=[0 0
0 -2
-2 -1
0 0];

%D
D=[0 0
-2 -1
-2 1
0 0];

%C
C=[0 0
-2 1
0 2
0 0];



r=mod(p,3)+1;
HEXAGON=[A
         B
         C
         D
         E
         F]
 line(HEXAGON(:,1),HEXAGON(:,2))


 if r==1
     fill(HEXAGON(:,1),HEXAGON(:,2),'b');
 else
     if r==2
         fill(A(:,1),A(:,2),'b');
         hold on
         fill(B(:,1),B(:,2),'y');
         hold on
         fill(C(:,1),C(:,2),'b');
         hold on
         fill(D(:,1),D(:,2),'y');
         hold on
         fill(E(:,1),E(:,2),'b');
         hold on
         fill(F(:,1),F(:,2),'y');
     
 else
          fill(A(:,1),A(:,2),'b');
          hold on
         fill(B(:,1),B(:,2),'y');
         hold on
         fill(C(:,1),C(:,2),'r');
         hold on
         fill(D(:,1),D(:,2),'b');
         hold on
         fill(E(:,1),E(:,2),'y');
         hold on
         fill(F(:,1),F(:,2),'r');
     end
 end
% 
 text(1,0,'A')
text(0.5,1,'B')
text(-0.5,1,'C')
text(-1.5,0,'D')
text(-0.5,-1,'E')
text(0.5,-1,'F')

 grid;
 
end