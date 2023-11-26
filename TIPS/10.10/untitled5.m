close all
clear all
N=1000;
for tau=[10^-17, 2*10^-17,4*10^-17]
% t=[-5*tau:5*tau/N:5*tau]
t=linspace(-5*tau,5*tau,N);
d1=exp(-pi*t.^2/tau^2)/tau;
hold on
plot(t,d1)

P1=sum(d1)*(t(2)-t(1))
end