clc
clear all
close all

T=4;
N=13;
nt=1000;
t=linspace(0,T,nt);
X0=0.5;
x=0;
x=x+X0;
A=X0;
e2=T/2-T*X0.^2;

for n=1:N
    Xn=((-1).^n-1)/(-j*2*pi*n);
    A(n+1)=abs(2*Xn);
    e2(n+1)=e2(n)-T*2*abs(Xn)^2;
    x=x+Xn*(exp(j*2*pi*n*t/T)-exp(-j*2*pi*n*t/T));
    plot(t,x)
    pause(0.1)
end

figure
stem(0:N,A)
figure
plot(e2)