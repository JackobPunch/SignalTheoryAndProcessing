clear all
close all
clc
load ('Wyniki_R0.mat') 
figure()
subplot(2,1,1)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_R45.mat')
subplot(2,1,1)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_R90.mat') 
subplot(2,1,1)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_R135.mat') 
subplot(2,1,1)
plot(Is.time, Is.signals.values(:,1))
legend('Wyniki Alfa_0', 'Wyniki Alfa_4_5','Wyniki Alafa_9_0','Wyniki Alfa_1_3_5');
% legend('Wyniki Alafa_9_0','Wyniki Alfa_1_3_5');
title('Przebiegi prądu fazowego przy obciążeniu rezystancyjnym');
ylabel('I [A]'); 
xlabel('t [s]'); 


load ('Wyniki_L0.mat') 
subplot(2,1,2)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_L45.mat') 
subplot(2,1,2)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_L90.mat') 
subplot(2,1,2)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
load ('Wyniki_L135.mat') 
subplot(2,1,2)
plot(Is.time, Is.signals.values(:,1))
hold on 
grid on
legend('Wyniki Alfa_0', 'Wyniki Alfa_4_5','Wyniki Alafa_9_0','Wyniki Alfa_1_3_5');
% legend('Wyniki Alafa_9_0','Wyniki Alfa_1_3_5');
title('Przebiegi prądu fazowego przy obciążeniu rezystancyjno-indukcyjnym');
ylabel('I [A]'); 
xlabel('t [s]'); 