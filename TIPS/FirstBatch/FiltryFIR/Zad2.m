%zad 2 Filtr dolnoprzespustowy

clear all
close all
clc

N=15;
wgr=pi/4;

%czesc ujemna 
n=-N:(-1);
h_lp_u=sin(wgr*n)./(pi*n);
%czesc zerowa
n=0;
h_lp_o=wgr/pi;
%czesc dodatnia
n=1:N;
h_lp_d=sin(wgr*n)./(pi*n);

hlp=[h_lp_u, h_lp_o, h_lp_d];

stem(-N:N, hlp)
hold on
w=hamming(2*N+1);
hLPw=hlp'.*w;
stem(-N:N,hLPw,'r')


% %zad 2 Filtr gornoprzepustowy
% 
% clear all
% close all
% clc
% 
% N=15;
% wgr=pi/8;
% 
% %czesc ujemna 
% n=-N:(-1);
% h_lp_u=-sin(wgr*n)./(pi*n);
% %czesc zerowa
% n=0;
% h_lp_o=1-wgr/pi;
% %czesc dodatnia
% n=1:N;
% h_lp_d=-sin(wgr*n)./(pi*n);
% 
% hlp=[h_lp_u, h_lp_o, h_lp_d];
% 
% stem(-N:N, hlp)
% hold on
% w=hamming(2*N+1);
% hLPw=hlp'.*w;
% stem(-N:N,hLPw,'r')

