clc;
clear all;
close all;
k =3;
g1=7;
g2=5;
m=[1 0 0 0 1 0];
trel = poly2trellis(k,[g1,g2]);
code = convenc(m,trel);
l=length(m);
e= randerr(1,length(code))
code1= mod((code+e),2);
decode = vitdec(code1,trel,l,'true','hard');
humerr=biterr(m,decode);