options=optimset('Tolx', 10^-6);
[x,fval, exitflag, output]=fzero('f2', -3, options);
iter=output.iterations