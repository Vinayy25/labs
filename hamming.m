
clear all;
close all;


%hamming code 

n = 7; 
k = 4;

p = [1 1 0 ; 1 1 1;0 0 1; 1 0 1]; 
d = [1 1 0 1];
ik = eye(k);
g = cat(2,ik,p);
c1 = mtimes(d,g)
c = mod(c1,2);
e = randerr(1,n);
code = mod(c+e,2);
demod = decode(code , n , k);
humerr= biterr(d,demod)
