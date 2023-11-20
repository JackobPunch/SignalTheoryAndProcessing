%% Parametry symulacji
%Ts=(1/fsw)/1000 ; % Krok całkowania
%% Parametry obwodu
Uin=100; %wartość napięcia wyjściowego
RL=50e-3;%rezystancja zastępcza dławika
L=1e-3 ;%indukcyjność dławika
C=1e-3; %pojemność kondensatora
Rload=10;%rezystancja odbiornika
fsw=20e3; %częstotliwość przełączeń IGBT (ustawić w Pulse Genarator)
Ts=(1/fsw)/1000 ; % Krok całkowania
D=50 ; %współczynnik wypełnienia w Pulse Generator (w %)
Rdson=50e-3;%rezystancja IGBT w trakcie przewodzenia

tic %start pomiaru czasu
RAMP_on=0; % zmiana wartości parametru przed symulacją
sim ('cw2sim') % uruchomienie symulacji poziomu matlaba(dcdc_ETAP4  nazwa projektu)
save ('Wyniki_symulacji_bez_rampy.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku
RAMP_on=1;
sim ('cw2sim') % uruchomienie symulacji poziomu matlaba
save ('Wyniki_symulacji_z_rampa.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku
toc %stop pomiaru czasu