 clear all; close all;
%%jalowy

U2=[248.3
240.5
195.9
153.2
124.6
103.0
74.1
50.2
];
I0=[1.077
0.972
0.571
0.370
0.287
0.239
0.184
0.144
];
P0=[120.35
112.55
75.36
48.52
34.00
24.60
13.86
7.07
];
cosfi0=[0.26
0.276
0.389
0.496
0.549
0.576
0.589
0.567
];
%zwarcie
Uz=[12.76
11.12
9.48
7.9
6.62
5
1.68
1.54
];
Iz=[11.76
10.24
8.64
7.28
6.08
4.6
3.68
3.36
];
cosfiz=[0.846
0.846
0.846
0.845
0.845
0.843
0.843
0.843
];
Pz=[221.12
167.68
121.072
83.84
58.56
34.16
8.48
7.12
];
%wykresy
B=polyfitZero(U2(1:8),I0(1:8),2);
B1=polyfitZero(U2(4:8),I0(4:8),1);
A=polyval(B,[0:0.01:248.3]);
A1=polyval(B1,[0:0.01:248.3]);
figure(1);plot(U2,I0,'b.', 'MarkerSize', 20);
hold on;
plot([0:0.01:248.3],A,'r-', 'LineWidth', 2);
hold on;
plot([0:0.01:248.3],A1,'g-', 'LineWidth', 2);
title('Zależność prądu biegu jałowego od napięcia');
ylabel('I0 [A]'); 
xlabel('U1 [V]'); 
legend('Punkty pomiarowe', 'Linia trendu d*U1^2', 'Linia trendu c*U1');

C=polyfitZero(U2,P0,2);
D=polyval(C,[0:0.01:248.3]);
figure(2);plot(U2,P0,'b.', 'MarkerSize', 20);hold on;plot([0:0.01:248.3],D,'r-', 'LineWidth', 2);xlabel('U1 [V]');ylabel('P0 [W]');grid on;
title('Zależność mocy na biegu jałowym od napięcia');
ylabel('P0 [W]'); 
xlabel('U1 [V]'); 
legend('Punkty pomiarowe', 'Linia trendu d*U1^2');

E=polyfit(U2,cosfi0,2);
F=polyval(E,[50.2:0.01:248.3]);
figure(3);plot(U2,cosfi0,'b.', 'MarkerSize', 20);hold on;plot([50.2:0.01:248.3],F,'r-', 'LineWidth', 2);xlabel('U [V]');ylabel('cos φ');grid on;
title('Zależność cos fi na biegu jałowym od napięcia');
ylabel('cos fi [-]'); 
xlabel('U1 [V]'); 
legend('Punkty pomiarowe', 'Linia trendu');

G=polyfitZero(Uz,Iz,1);
H=polyval(G,[0:0.01:12.76]);
figure(4);plot(Uz,Iz,'b.', 'MarkerSize', 20);hold on;plot([0:0.01:12.76],H,'r-', 'LineWidth', 2);xlabel('U [V]');ylabel('cos φ');grid on;
title('Zależność prądu zwarciowego od napięcia');
ylabel('IZ [A]'); 
xlabel('UZ [V]'); 
legend('Punkty pomiarowe', 'Linia trendu');

I=polyfitZero(Uz,Pz,2);
J=polyval(I,[0:0.01:12.76]);
figure(5);plot(Uz,Pz,'b.', 'MarkerSize', 20);hold on;plot([0:0.01:12.76],J,'r-', 'LineWidth', 2);xlabel('U [V]');ylabel('cos φ');grid on;
title('Zależność mocy zwarciowej od napięcia');
ylabel('PZ [W]'); 
xlabel('UZ [V]'); 
legend('Punkty pomiarowe', 'Linia trendu a*UZ^2');

