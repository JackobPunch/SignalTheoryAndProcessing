clc
clear all 
close all
f0=150;
fp=1000;
f1=100;
f2=250;
Nt=200;
nt=[0:Nt-1];
x1=sin(2*pi*f1/fp*nt);
x2=sin(2*pi*f2/fp*nt);
x=x1+x2;
subplot(4,1,1)
plot(nt,x1)
subplot(4,1,2)
plot(nt,x2)
subplot(4,1,3)
plot(nt,x)

Nx=200;
f1=100;
f2=250;
w1=2*pi*f1/fp;
w2=2*pi*f2/fp;
nx=[0:Nx-1];
x1=sin(w1*nx);
x2=sin(w2*nx);
figure
subplot(4,1,1); plot(nx,x1); 
subplot(4,1,2); plot(nx,x2);
x=x1+x2;
subplot(4,1,3); plot(nx,x);

