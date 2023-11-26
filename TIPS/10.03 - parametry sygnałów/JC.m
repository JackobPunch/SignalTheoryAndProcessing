clear all
close all
N=1000;
% for n = 0:N-1
%     if n<500
%         x(n+1)=1;
%     else
%         x(n+1)=0;
%     end
% end
n=0:N-1;
% x=n<500;
x=sin(2*pi*0.1*n);
plot(n,x)

x_mean=0;
x_sum=0;
% for n=0:N-1
%     x_sum=x_sum+x(n+1);
% end
% x_mean=x_sum/N;
x_sum=sum(x);
x_mean=x_sum/N;

% x_var=0;
% for n=0:N-1
%     x_var=x_var+(x(n+1)-x_mean)^2;
% end
% x_var=x_var/(N-1)
x_var=sum((x-x_mean).^2);
x_var=x_var/(N-1);