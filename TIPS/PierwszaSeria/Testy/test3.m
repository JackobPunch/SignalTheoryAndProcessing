%% Test3
 clear all
 close all
 clc
%Zadanie 1
%Filtr pasmowoprzepustowy
N=7;
wgr1=pi/5;
wgr2=pi/3;

%czesc ujemna 
n=-N:(-1);
h_bp_u=(sin(wgr2*n)-sin(wgr1*n))./(pi*n);
%czesc zerowa
n=0;
h_bp_o=(wgr2-wgr1)/pi;
%czesc dodatnia
n=1:N;
h_bp_d=(sin(wgr2*n)-sin(wgr1*n))./(pi*n);

hbp=[h_bp_u, h_bp_o, h_bp_d];

stem(-N:N, hbp)
hold on
w=hamming(2*N+1);
hBPw=hbp'.*w;
stem(-N:N,hBPw,'r')
wynik=sum(hBPw(1:11))

% 
% n=[-7:7]
% wg1 = pi/7;
% H1 = abs(sum(hbp.*exp(-j*wg1*n)))


%Zadanie 2
format long
h = [1 -1 2 2];
n = 0:length(h)-1;
f=300;
fp=1200;
wg2 = 2*pi*f;
H2 = abs(sum(h.*exp(-j*wg2*n/fp)))
