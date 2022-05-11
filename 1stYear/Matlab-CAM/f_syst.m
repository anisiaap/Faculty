function g=f_syst(v)
%{
x=v(1);
y=v(2);

g(1)=x.^2+y.^2-4;
g(2)=x-y-1;
%}


%{
x=v(1);
y=v(2);


g(1)=sin(x+y)-1.1.*x-0.2;
g(2)=1.1.*x.*x+2.*y.*y-1;
%}