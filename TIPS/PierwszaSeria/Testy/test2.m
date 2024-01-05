clc
clear all
close all

t = linspace(0, 2*pi, 100000000);
x0 = 1*(cos(t) + 1i*sin(t));
x1 = -3i*(cos(t) + 1i*sin(t));
x2 = 2*(cos(2*t) + 1i*sin(2*t));
x3 = -5i*(cos(3*t) + 1i*sin(3*t));
x4 = 6*(cos(4*t) + 1i*sin(4*t));

y=x0+x1+conj(x1)+x2+conj(x2)+x3+conj(x3)+x4+conj(x4);

result1=var(y) %the right one

%the loop doesn't give the same result 
% x = [x0 x1 x2 x3 x4];
% 
% for n = 1:length(x)-1
%     x(n) = x(n) + conj(x(n));
% end
% 
% result2 = var(x)
