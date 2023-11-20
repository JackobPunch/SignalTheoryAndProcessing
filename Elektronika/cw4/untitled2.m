clear all
close all
voltage=[0.5
1.0
1.5
2.0
2.5
3.0
3.5
];
frequency=[505
937
1477
1927
2379
2383
3279
];

G=polyfitZero(voltage,frequency,1);
H=polyval(G,[0:0.01:3.5]);
figure();plot(voltage,frequency,'b.', 'MarkerSize', 20);hold on;plot([0:0.01:3.5],H,'r-', 'LineWidth', 2);grid on;
title('Charakterystyka częstotliwości od napięcia');
ylabel('f [Hz]'); 
xlabel('U [V]'); 
legend('Punkty pomiarowe', 'Linia trendu','Location', 'best');