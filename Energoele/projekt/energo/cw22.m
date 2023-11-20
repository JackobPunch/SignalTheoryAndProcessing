clear all
load ('Wyniki_symulacji_bez_rampy.mat') % załadowanie do Workspace danych zapisanych w pliku z rozszerzeniem mat
dane_bez_rampy=Przebiegi;
figure()
subplot(2,1,1)
plot(dane_bez_rampy.time, [dane_bez_rampy.signals.values(:,1)])
subplot(2,1,2)
plot(dane_bez_rampy.time, [dane_bez_rampy.signals.values(:,3)])
load ('Wyniki_symulacji_z_rampa.mat')
dane_z_rampa=Przebiegi;
subplot(2,1,1)
hold on
plot(dane_z_rampa.time, [dane_z_rampa.signals.values(:,1)])
subplot(2,1,2)
hold on
plot(dane_z_rampa.time, [dane_z_rampa.signals.values(:,3)])

