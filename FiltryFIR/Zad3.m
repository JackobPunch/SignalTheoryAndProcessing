%zad 3a

clear all
close all
clc

%Filtr dolnoprzepustowy
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

%Filtr gornoprzepustowy

clear all
close all
clc

N=15;
wgr=pi/8;

%czesc ujemna 
n=-N:(-1);
h_lp_u=-sin(wgr*n)./(pi*n);
%czesc zerowa
n=0;
h_lp_o=1-wgr/pi;
%czesc dodatnia
n=1:N;
h_lp_d=-sin(wgr*n)./(pi*n);

hlp=[h_lp_u, h_lp_o, h_lp_d];

stem(-N:N, hlp)
hold on
w=hamming(2*N+1);
hLPw=hlp'.*w;
stem(-N:N,hLPw,'r')
legend('rect', 'hamming');
xlabel('N');

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
% H0=abs(w)<wgr; %dolno
H0=abs(w)>wgr; %górno
plot(w,H0,w,H,w,H_ham)
legend('ideal','rect', 'hamming');
ylabel('wzmocnienie');
xlabel('w/pi');
H_db=20*log10(abs(H));
H_ham_db=20*log10(abs(H_ham));
figure
plot(w,H_db,w,H_ham_db)
legend('rect', 'hamming');
ylabel('wzmocnienie [dB]');
xlabel('w/pi');

figure
plot(w,angle(real(H)),w,real(H))
legend('amplitude', 'phase');
xlabel('w/pi');


%Zad3b
figure
freqz(hlp,1);

[Hp,W]=freqz(hlp,1);
figure
plot(W,abs(Hp))

Hp_u = fliplr(Hp);
W_u=W.*(-1);

Hp_c = [Hp_u Hp];
W_c=[W_u W];
figure
plot(W_c, abs(Hp_c));