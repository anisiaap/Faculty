syms a b c d
sol=solve(2*a+b-c , a*d-d*d , a+c-45,b+d-78,a ,b ,c ,d );

for i=1:length(sol.a)
    disp([sol.a(i) sol.b(i) sol.c(i) sol.d(i)])
end