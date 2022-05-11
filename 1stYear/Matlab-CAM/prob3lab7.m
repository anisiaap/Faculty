sol=solve('m+p-2*n','n*q-p^2','m+q-37','n+p-36','m','n','p','q')
for i=1:length(sol.m)
    disp([sol(i).m sol(i).n sol(i).p sol(i).q])
end

