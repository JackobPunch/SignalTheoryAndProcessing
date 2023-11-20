clear all
close all 
clc
load ('Wyniki_symulacji_bez_rampy.mat') % załadowanie do Workspace danych zapisanych w pliku z rozszerzeniem mat

figure()
subplot(2,1,1)
plot(ans.Przebiegi.time, ans.Przebiegi.signals.values(:,1))
subplot(2,1,2)
plot(ans.Przebiegi.time, ans.Przebiegi.signals.values(:,2))


load ('Wyniki_symulacji_z_rampa.mat')

subplot(2,1,1)
hold on
plot(ans.Przebiegi.time, ans.Przebiegi.signals.values(:,1))
subplot(2,1,2)
hold on
plot(ans.Przebiegi.time, ans.Przebiegi.signals.values(:,2))