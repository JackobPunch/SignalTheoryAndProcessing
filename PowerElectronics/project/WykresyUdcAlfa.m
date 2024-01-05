clear all
close all 
clc

UR=[524.0554 375.6400 68.3863 0.1386];
UL=[525.0844 374.9394 3.5426 0.2189];
alfa=[0 45 90 135];
figure
plot(alfa,UR,'b.', 'MarkerSize', 20);
hold on;
grid on;
plot(alfa,UR)
title('Udc=f(alfa) - obciążenie rezystancyjne');
ylabel('Udc [V]'); 
xlabel('alfa [degrees]'); 
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 530]); 
figure
plot(alfa,UL,'b.', 'MarkerSize', 20);
hold on;
grid on;
plot(alfa,UL)
title('Udc=f(alfa) - obciążenie rezystancyjno-indukcyjne');
ylabel('Udc [V]'); 
xlabel('alfa [degrees]'); 
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 530]); 