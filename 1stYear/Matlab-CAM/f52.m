function sol=f52(p)
r=roots(p);
sol=[];
for i=1:length(r)
    if imag(r(i))==0 
        sol=[sol r(i)];
    end
end