clear all
close all

f=10;
T=1;
Td=2;
N=1000;
t=linspace(0,Td,N);
s=1-t/T;
obw=exp(-t/T);
x=obw.*sin(2*pi*f*t);
plot(t,s,t,obw,t,x)