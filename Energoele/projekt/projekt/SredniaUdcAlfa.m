clear all
close all 
clc
load ('Wyniki_R0.mat') 
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:80202;
averageValueR0 = mean(Udc.signals.values(excludeRange+1:end, 1))
 
load ('Wyniki_R45.mat') 
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:56668;
averageValueR45 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R90.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:26668;
averageValueR90 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R135.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:63335;
averageValueR135 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_L0.mat') 
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:80002;
averageValueL0 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_L45.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:43335;
averageValueL45 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_L90.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:52525;
averageValueL90 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_L135.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:53423;
averageValueL135 = mean(Udc.signals.values(excludeRange+1:end, 1))


