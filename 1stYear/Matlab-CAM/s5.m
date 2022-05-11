sol=[];
sol=solve('2.*a+6-c','a.*b-d.^2','a+c-45', ...
    '16+d-78','a','b','c','d');
for i=1:length(sol.a)
    disp([sol.a(i) sol.b(i) sol.c(i) sol.d(i)])
end