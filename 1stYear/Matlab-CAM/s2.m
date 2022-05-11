clear, clc
v0=[0.6 -0.2 -0.1];
[vmin,fmin,exitflag,output]=fminsearch('f2',v0);
vmin
fmin
output.algorithm