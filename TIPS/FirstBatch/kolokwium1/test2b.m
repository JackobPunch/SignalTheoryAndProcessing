clear all
close all
N=20;
T=4;
P=1000;
t=linspace(0,T,P);
w0=2*pi/T;
x0=0;
x1=2*(cos(t)+j*sin(t));
x2=4j*(cos(2*t)+j*sin(2*t));
x3=6*(cos(3*t)+j*sin(3*t));
x4=8j*(cos(4*t)+j*sin(4*t));

for n=1:N
    x=x0+xn*(exp(j*w0*n*t)+exp(-j*w0*n*t));
end
var()
    