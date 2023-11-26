% %zad 2 Filtr dolnoprzespustowy
% 
% clear all
% close all
% clc
% 
% N=15;
% wgr=pi/4;
% 
% %czesc ujemna 
% n=-N:(-1);
% h_lp_u=sin(wgr*n)./(pi*n);
% %czesc zerowa
% n=0;
% h_lp_o=wgr/pi;
% %czesc dodatnia
% n=1:N;
% h_lp_d=sin(wgr*n)./(pi*n);
% 
% hlp=[h_lp_u, h_lp_o, h_lp_d];
% 
% stem(-N:N, hlp)
% hold on
% w=hamming(2*N+1);
% hLPw=hlp'.*w;
% stem(-N:N,hLPw,'r')


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

%zad 3a FIR

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

n=-N:N;
k=1;
w_ham=hamming(2*N+1)';
for w=linspace(-pi,pi,1000);
    H(k)=sum(hlp.*exp(-j*w*n));
    H_ham(k)=sum(hlp.*w_ham.*exp(-j*w*n));
    k=k+1;
end

w=linspace(-pi,pi,1000);
figure
H0=abs(w)<wgr;
plot(w,H,w,H0,w,H_ham)
H_db=20*log10(abs(H));
H_ham_db=20*log10(abs(H_ham));
figure
plot(w,H_db,w,H_ham_db)
legend('rect', 'hamming');



figure;
plot(w,angle(real(H)),w,real(H))
freqz(hlp,1)





