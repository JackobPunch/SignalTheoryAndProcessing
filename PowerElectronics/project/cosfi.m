clear all
close all
angle=[0	15	30	45	60	75	90	105	120	135	150	165	180];
THD=[0.570045124	0.67453919	0.588244642	0.475095432	0.338608979	0.190322294	0.090845905	0.147526387	0.569757108	1	1	1	1];
figure
plot(angle, THD,'b.', 'MarkerSize', 20);
grid on;
hold on;
plot(angle, THD);
ylabel('cosfi [-]'); 
xlabel('alfa [degree]'); 
title('Charakterystyka cos(fi) w zależności od kąta alfa');
legend('Punkty pomiarowe','Location', 'best');
