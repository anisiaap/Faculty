function [sg_min,sg_max,nr_cond]=prob56(A)

sing=sdv(A);
sg_min=min(sing);
sg_max=max(sing);
nr_cond=cond(A);