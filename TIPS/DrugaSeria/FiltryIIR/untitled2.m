clear all;
close all;
f0=990;
fp=8000;
w0=2*pi*f0/fp;
d=0.999*exp(1i*w0); %stabilny
% d=1.001*exp(1i*w0); %niestabilny
d=[d conj(d)];
c=1*exp(1i*w0);
c=[c conj(c)];
w=linspace(-pi,pi,1000);
circle=exp(1i*w);

figure
plot(circle)
hold on
plot(d,'rx')
plot(c,'bo')
plot(0,0,'bo')

a=poly(d);
b=poly(c)
% freqz(1,A)
[H,W]=freqz(b,a,w);
figure
subplot(2,1,1)
plot(W/pi*fp/2,abs(H))
subplot(2,1,2)
plot(W/pi*fp/2,angle(H))

imp=[1 zeros([1 500])];

h=filter(b,a,imp);

figure
plot(h)

[H,F]=freqz(b,a,[0,w0])

H0=abs(freqz(b,a,[0,w0]))