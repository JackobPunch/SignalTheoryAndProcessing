clc
clear all
close all

%zadanie 1

n = 3;
T = 0.25;
N = 1000;
t = linspace(0,T,N);

%zbiór1

x1 = 1/sqrt(T)*ones(size(t));
x2 = sqrt(2/T)*cos(2*pi*n*t/T);
x3 = sqrt(2/T)*sin(2*pi*n*t/T);

plot(t,x1,t,x2,t,x3)

dt = t(5)-t(4);
I12 = sum(x1(1:end-1).*x2(1:end-1))*dt
I11 = sum(x1(1:end-1).*x1(1:end-1))*dt
I22 = sum(x2(1:end-1).*x2(1:end-1))*dt

% %zbiór2
% n1 = 2;
% n2 = 3;
% 
% x1 = 1/sqrt(T)*exp(j*2*pi*n1*t/T);
% x2 = 1/sqrt(T)*exp(j*2*pi*n2*t/T);
% 
% subplot(2,1,1)
% plot(t,real(x1),t,real(x2))
% 
% subplot(2,1,2)
% plot(t,imag(x1),t,imag(x2))
% 
% dt = t(5)-t(4); 
% I12 = sum(x1(1:end-1).*conj(x2(1:end-1)))*dt
% I11 = sum(x1(1:end-1).*conj(x1(1:end-1)))*dt