clear all
close all
angle=[1.00E-04
1.00E-03
3.00E-03
5.00E-03
];
THD=[27.94
23.36
16.45
11.39
];
I5=[22.64
21.46
15.28
10.38
];
I7=[10.68
7.3
5.31
3.84
];

figure
plot(angle, THD,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, THD);
ylabel('THD [%]'); 
xlabel('Lin [H]'); 
title('Charakterystyka THD w zależności od Lin');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 60]); 
figure
plot(angle, I5,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, I5);
ylabel('I(5)/I(1) [%]'); 
xlabel('Lin [H]'); 
title('Charakterystyka I(5)/I(1) w zależności od Lin');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 50]); 
figure
plot(angle, I7,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, I7);
ylabel('I(7)/I(1) [%]'); 
xlabel('Lin [H]'); 
title('Charakterystyka I(7)/I(1) w zależności od Lin');
legend('Punkty pomiarowe','Location', 'best');
ylim([0, 50]); 


