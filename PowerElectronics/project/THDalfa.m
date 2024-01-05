clear all
close all
angle=[0
45
90
135
];
THD=[22.77
15.94
67.74
936.95
];
I5=[21.11
14.02
59.68
280.77
];
I7=[7.25
7.21
29.62
281.38
];

figure
plot(angle, THD,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, THD);
ylabel('THD [%]'); 
xlabel('Kąt [degree]'); 
title('Charakterystyka THD w zależności od kąta alfa');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 1200]); 
figure
plot(angle, I5,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, I5);
ylabel('I(5)/I(1) [%]'); 
xlabel('Kąt [degree]'); 
title('Charakterystyka I(5)/I(1) w zależności od kąta alfa');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 370]); 
figure
plot(angle, I7,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, I7);
ylabel('I(7)/I(1) [%]'); 
xlabel('Kąt [degree]'); 
title('Charakterystyka I(7)/I(1) w zależności od kąta alfa');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 370]); 


