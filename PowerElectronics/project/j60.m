tic %start pomiaru czasu
L_obc=100e-6;
alfa=60; % zmiana wartości parametru przed symulacją
sim ('untitled1') % uruchomienie symulacji z poziomu matlaba(cw2_sim -> nazwa projektu)
save ('Wyniki_R60.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku

Lin=1e-3;
alfa=60;
sim ('untitled1') % uruchomienie symulacji z poziomu matlaba
save ('Wyniki_R60in2.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku


Lin=5e-3;
alfa=60;
sim ('untitled1') % uruchomienie symulacji z poziomu matlaba
save ('Wyniki_R60in3.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku
toc %stop pomiaru czasu