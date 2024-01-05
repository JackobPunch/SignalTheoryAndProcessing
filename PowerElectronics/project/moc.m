clear all; clc; close all;

Ts=100e-6;
alfa=0;
f=50;
fi=0;
w=2*pi*f;
Ls=50e-6;
Lin=11e-3;
Rin=1/30*w*Lin;
R_obc=6;
L_obc=10e-6;
% L_obc=200e-3;
Rdiode=1e-3;
Vdiode=1.5;

% sim('untitled10x2810x29.slx')
ALFA=0:15:180;
P_wyniki = zeros(size(ALFA));
Q_wyniki = zeros(size(ALFA));
S_wyniki = zeros(size(ALFA));

excludeRange = 1:150000;

for i = 1:length(ALFA)
   sim('untitled10x2810x29.slx')

    P_wyniki(i) = max(P.signals.values(excludeRange+1:end,2));
    Q_wyniki(i) = max(Q.signals.values(excludeRange+1:end,2));
    S_wyniki(i) = sqrt(P_wyniki(i).^2 + Q_wyniki(i).^2);

    alfa = alfa + 15;
end

figure(1)
plot(ALFA, P_wyniki,'b.', 'MarkerSize', 20)
hold on; grid on;
plot(ALFA, P_wyniki,'r-');
title('Wykres zależności mocy czynnej od alfa')
xlabel('ALFA'); ylabel('P [W]'); ylim([0 30000]);


figure(2)
plot(ALFA, Q_wyniki,'b.', 'MarkerSize', 20)
hold on; grid on;
plot(ALFA, Q_wyniki,'r-');
title('Wykres zależności mocy biernej od alfa')
xlabel('ALFA'); ylabel('Q [VAr]'); ylim([0 30000]);

figure(3)
plot(ALFA, S_wyniki,'b.', 'MarkerSize', 20)
hold on; grid on;
plot(ALFA, S_wyniki,'r-');
title('Wykres zależności mocy pozornej od alfa')
xlabel('ALFA'); ylabel('S [VA]'); ylim([0 30000]);