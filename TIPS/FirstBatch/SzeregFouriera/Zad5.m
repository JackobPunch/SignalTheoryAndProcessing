clc
clear all
close all

d=0.25;
N=20;
T=4;
P=1000;
t=linspace(0,T,P);
w0=2*pi/T;
tau=d*T;
a0=0;
x=a0;
e2=1/3*(T/4)^3-a0^2*T;
for n=1:N
    Xpn=((-1)^n-1)/(-j*2*pi*n);
    Xtn=Xpn*1/(j*w0*n);
    x=x+Xtn*2*cos(w0*n*t);
    A(n+1)=abs(Xtn*2);
    plot(t,x)
    e2(n+1)=e2(n)-Xtn^2*T*2; %błąd aproksymacji
end
figure
stem(0:N,A)
figure
plot(0:N,e2)