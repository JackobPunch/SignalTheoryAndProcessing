clear all
close all 
clc

load ('Wyniki_R60.mat') 
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:33335;
averageValueR60 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R0in2.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:38889;
averageValueR60in2 = mean(Udc.signals.values(excludeRange+1:end, 1))

% load ('Wyniki_R45in2.mat') 
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on 
% grid on
% excludeRange = 1:83335;
% averageValueR45in2 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R60in2.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:20001;
averageValueR60in2 = mean(Udc.signals.values(excludeRange+1:end, 1))

% load ('Wyniki_R90in2.mat')
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on
% grid on
% excludeRange = 1:26668;
% averageValueR90in2 = mean(Udc.signals.values(excludeRange+1:end, 1))
 
% load ('Wyniki_R135in2.mat')
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on
% grid on
% excludeRange = 1:11021; 
% averageValueR135in2 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R0in3.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:51445;
averageValueR0in3 = mean(Udc.signals.values(excludeRange+1:end, 1))

% load ('Wyniki_R45in3.mat')
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on 
% grid on
% excludeRange = 1:51793;
% averageValueR45in3 = mean(Udc.signals.values(excludeRange+1:end, 1))

load ('Wyniki_R60in3.mat')
figure()
plot(Udc.time, Udc.signals.values(:,1))
hold on 
grid on
ylabel('Udc [V]'); 
xlabel('t [s]');
excludeRange = 1:67087;
averageValueR60in3 = mean(Udc.signals.values(excludeRange+1:end, 1))

% load ('Wyniki_R90in3.mat') 
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on 
% grid on
% excludeRange = 1:66668;
% averageValueR90in3 = mean(Udc.signals.values(excludeRange+1:end, 1))

% load ('Wyniki_R135in3.mat')
% figure()
% plot(Udc.time, Udc.signals.values(:,1))
% hold on
% grid on
% excludeRange = 1:26277;
% averageValueR135in3 = mean(Udc.signals.values(excludeRange+1:end, 1))