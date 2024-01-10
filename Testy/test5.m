%filtr dolnoprzepustowy
N=7;
wgr1=pi/9;


%czesc ujemna
n=-N:(-1);
h_lp_u=sin(wgr1*n)./(pi*n);
%czesc zerowa
n=0;
h_lp_o=wgr1/pi;
%czesc dodatnia
n=1:N;
h_lp_d=sin(wgr1*n)./(pi*n);

hlp=[h_lp_u, h_lp_o, h_lp_d];

w=blackman(2*N+1);
hLPw=hlp'.*w;
wynik=sum(hLPw(1:7))