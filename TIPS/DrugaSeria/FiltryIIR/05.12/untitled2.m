%filtry FIR 
%Zad 5
%Najpierw odtwarzamy zad 1
%następnie

x=imp;
yb=zeros([1 length(a)-1]);
for n = 1:length(x)
    y(n)=x(n)-sum(a(2:end).*yb);
    yb=[y(n) yb(1:end-1)];
end

max(abs(y-h))
%zad 1 fir plus to dokończenie zadania
