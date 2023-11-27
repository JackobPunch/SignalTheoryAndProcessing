clear all; close all

fp=1000;
f0=150;
wg=2*pi*f0/fp;
N=15;
n=[-N:-1];
h=sin(wg*n)./(pi*n);
n=[1:N];
h=[h wg/pi sin(wg*n)./(pi*n)].*hamming(2*N+1)';
figure
n=[-N:N];
plot(n,h);

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

y=filter(h,1,x);
x1d=[zeros(1,N) x1(1:end-N)];
subplot(4,1,4); plot(nx,y,nx,x1d);
[H,W]=freqz(h,1);
figure
plot(W/pi*fp/2,abs(H)); grid on;
title('Charakterystyka amplitudowa');
H1=abs(sum(h.*exp(-j*w1*n)))
H2=abs(sum(h.*exp(-j*w2*n)))
