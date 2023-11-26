clear all;
close all;
w0=pi/4;
d=0.999*exp(1i*w0); %stabilny
% d=1.001*exp(1i*w0); %niestabilny
d=[d conj(d)];
c=0.9*exp(1i*w0);
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
plot(W,abs(H))
subplot(2,1,2)
plot(W,angle(H))

imp=[1 zeros([1 500])];

h=filter(b,a,imp);

figure
plot(h)

[H,F]=freqz(b,a,[0,w0])

H0=abs(freqz(b,a,[0,w0]))