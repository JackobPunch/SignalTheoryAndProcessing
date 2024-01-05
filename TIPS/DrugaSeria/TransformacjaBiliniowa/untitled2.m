clc;clear all; close all;
n=3;
w3dB=0.8*pi;
%K1
T=1; fs=1;
wc=(2/T)*tan(w3dB/2);
%K2
k=0:1:n-1;
sk=wc*exp(j*pi()*(1+2*k)/(2*n))*exp(j*pi/2);
sk=sk';
zplane([],sk)
title('Bieguny filtru analogowego')
%K3
G0=prod(-sk)/prod(2-sk);
figure(2)
zera=[-1 -1 -1]';
bieguny=(2+(sk))./(2-(sk));
zplane(zera,bieguny)
title('Bieguny filtru cyfrowego')
%K4
mian = poly(bieguny);
licz = poly(zera);
figure(3)
[H,w1]=freqz(G0*licz,mian);
plot(w1,(abs(H)));grid on;