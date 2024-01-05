%Zad.1
clc;clear all;close all;
n=2;
w=0:0.01:100;
wc=25;
G_n2=1./(sqrt(1+(1j*w/(1j*wc)).^(2*n)));
plot(w,G_n2,'r','LineWidth',1.1);
grid on;
hold on
n=4;
G_n4=1./(sqrt(1+(1j*w/(1j*wc)).^(2*n)));
plot(w,G_n4,'g','LineWidth',1.1);
grid on;
hold on
n=8;
G_n8=1./(sqrt(1+(1j*w/(1j*wc)).^(2*n)));
plot(w,G_n8,'b','LineWidth',1.1);
grid on;
hold on
xlabel('\omega')
ylabel('G(\omega)')
legend('n=2','n=4','n=8')
