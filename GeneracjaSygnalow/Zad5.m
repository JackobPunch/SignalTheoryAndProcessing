clear all;
close all;
clc;
f0=50;
fp=10000;   
n=200;
Td=n/fp;
t=linspace(0,Td,n);
w0=2*pi*f0;
k=2*pi*f0/0.01;
%dfi/dt=w0*k.*t
fi=w0*t+(1/2)*k.*t.^2;
fi0=0;
x=sin(fi+fi0);
figure 
plot(t,x); 