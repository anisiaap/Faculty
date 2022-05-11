v=[4 -48 180 -217 -77 ];
rad=roots(v);
sol=[];
for i=1:length(rad)
    if imag(rad(i))==0 & rad(i)-4>=0
        sol=[sol rad(i)];
    end
end
sort(sol)