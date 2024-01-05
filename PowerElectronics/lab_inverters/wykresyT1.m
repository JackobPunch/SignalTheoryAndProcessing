clear all; close all;

M=[0.1
0.2
0.3
0.4
0.5
0.6
0.7
0.8
0.9
1
1.1
1.2
1.3
1.4
1.5
1.6
1.7
1.8
1.9
2
];

U=[0.073825
0.146725
0.220775
0.2915
0.365
0.43775
0.51125
0.58425
0.65775
0.73075
0.77775
0.805
0.8245
0.84
0.853
0.8635
0.8725
0.8805
0.8875
0.89375
];

C=polyfitZero(M,U,1);
D=polyval(C,[0:0.01:2]);
figure(2);plot(M,U,'b.', 'MarkerSize', 20);hold on;plot([0:0.01:2],D,'r-', 'LineWidth', 2);xlabel('Ma [-]');ylabel('Uobc/Uz [-]');grid on;
title('Zależność skutecznego napięcia wyjściowego od współczynnika Ma');
ylabel('M [-]'); 
xlabel('Uobz/Uz [-]'); 
legend('Punkty pomiarowe', 'Linia trendu');


