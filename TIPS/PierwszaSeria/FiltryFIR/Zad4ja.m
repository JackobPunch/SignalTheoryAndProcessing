clc
clear all 
close all
f0=150;
fp=1000;
f1=100;
f2=250;
n=1000;
T=1/fp*n;
t=linspace(0,T,n);
x1=sin(2*pi*f1);
x2=sin(2*pi*f2);
x=x1+x2;
subplot(4,1,1)
plot(t,x1)
subplot(4,1,2)
plot(t,x2)
subplot(4,1,3)
plot(t,x)

