%% Parametry symulacji
Ts=200e-9 ; % Krok całkowania
%% Parametry obwodu
Uin=100; %wartość napięcia wyjściowego
RL=50e-3;%rezystancja zastępcza dławika 
L=1e-3 ;%indukcyjność dławika
C=1e-3; %pojemność kondensatora 
Rload=10;%rezystancja odbiornika
fsw=20e3; %częstotliwość przełączeń IGBT (ustawić w Pulse Genarator)
D=50 ; %współczynnik wypełnienia w Pulse Generator (w %)
Rdson=50e-3;%rezystancja IGBT w trakcie przewodzenia