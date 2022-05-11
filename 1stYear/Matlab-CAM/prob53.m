function sol=prob53(v)
p=roots(v);
sol=[];
for i=1:length(p)
    if imag(p(i))~=0 & abs(p(i))>1
        sol=[sol p(i)];
    end
end
