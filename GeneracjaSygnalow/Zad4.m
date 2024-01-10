clear all;
close all;
clc;
fp=100;   
Td=8*pi;
n=Td/(1/fp)
t=linspace(0,Td,n);
w0=0;
dw=Td/n;
k=dw*t;
%dfi/dt=w0*k.*t
fi=w0*t+(1/2)*k.*t.^2;
fi0=0;
x=sin(fi+fi0);
figure 
plot(t,x); 

