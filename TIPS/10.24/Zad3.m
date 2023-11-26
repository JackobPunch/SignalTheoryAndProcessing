clear all
close all
d=0.25;
N=20;
T=4;
P=1000;
t=linspace(0,T,P);
w0=2*pi/T;
tau=d*T;
X0=d;
x=X0;
A=X0;
e2=tau-X0^2*T;
for n=1:N
    Xn=1/(pi*n)*sin(w0*n*tau/2);
    %x=X+Xn*(exp(j*w0*n*t)+exp(-j*w0*n*t));
    x=x+Xn*2*cos(w0*n*t);
    A(n+1)=2*Xn;
    plot(t,x)
    e2(n+1)=e2(n)-T*abs(Xn)^2*2;
end
figure()
stem(0:N,abs(A))
figure()
plot(0:N,e2)