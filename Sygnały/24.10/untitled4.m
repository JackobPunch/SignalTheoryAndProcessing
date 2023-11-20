clear all
close all

x=[1 2 3 0 0];
h=[1 1 1 1];
Nh=length(h);
xbuf=zeros(1,Nh-1);
for n=1:length(x)
    y(n)=x(n)*h(1)+sum(xbuf.*h(2:end));
    xbuf=[x(n),xbuf(1:end-1)];
end
y
filter(h,1,x)
    