clear all
close all
d=0.25;
N=20;
T=4;
P=1000;
t=linspace(0,T,P);
w0=2*pi/T;
tau=d*T;
a0=d;
x=a0;
A=a0;
e2=tau-a0^2*T;
for n=1:N
    an=1/(pi*n)*sin(w0*n*tau);
    bn=1/(pi*n)*(cos(w0*n*tau)-1);
    %x=X+Xn*(exp(j*w0*n*t)+exp(-j*w0*n*t));
    x=x+an*cos(w0*n*t)-bn*sin(w0*n*t);
    A(n+1)=2*an;
    plot(t,x)
    e2(n+1)=e2(n)-an^2*T/2-bn^2*T/2;
end
figure()
plot(0:N,e2)
figure
stem(0:N,abs(A))