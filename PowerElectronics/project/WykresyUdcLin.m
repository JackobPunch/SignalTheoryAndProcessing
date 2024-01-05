clear all
close all 
clc

Uin0=[524.0554 500.3336 420.5664];
% Uin45=[375.6400 365.4718 302.7794];
Uin60=[264.2976 260.2937 218.3012];
% Uin90=[68.3863 65.3645 44.0212];
% Uin135=[0.1386 0.1416 0.1626];
Lin=[100e-6 1e-3 5e-3];
figure
plot(Lin,Uin0,'b.', 'MarkerSize', 20);
hold on;
grid on;
plot(Lin,Uin0)
title('Udc=f(Lin) dla alfa=0');
ylabel('Udc [V]'); 
xlabel('Lin [H]'); 
legend('Punkty pomiarowe','Location', 'best');
ylim([200, 530]); 
% figure
% plot(Lin,Uin45,'b.', 'MarkerSize', 20);
% hold on;
% plot(Lin,Uin45)
% title('Charakterystyka napięcia od Lin');
% ylabel('Uin [V]'); 
% xlabel('Lin [H]'); 
figure
plot(Lin,Uin60,'b.', 'MarkerSize', 20);
hold on;
grid on;
plot(Lin,Uin60)
title('Udc=f(Lin) dla alfa=60');
ylabel('Udc [V]'); 
xlabel('Lin [H]'); 
legend('Punkty pomiarowe','Location', 'best');
ylim([200, 530]); 
% figure
% plot(Lin,Uin90,'b.', 'MarkerSize', 20);
% hold on;
% plot(Lin,Uin90)
% title('Charakterystyka napięcia od Lin');
% ylabel('Uin [V]'); 
% xlabel('Lin [H]'); 
% figure
% plot(Lin,Uin135,'b.', 'MarkerSize', 20);
% hold on;
% plot(Lin,Uin135)
% title('Charakterystyka napięcia od Lin');
% ylabel('Uin [V]'); 
% xlabel('Lin [H]'); 