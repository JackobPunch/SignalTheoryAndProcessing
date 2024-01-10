clear all
close all
N=10;
x=ones(1,N);
y=x;
for k=0:N-1
    n=k:N-1;
    R(k+1)=sum(x(n+1).*y(n+1-k));
end

k=0:N-1;
plot(k,R)
hold on
stem(k,x)