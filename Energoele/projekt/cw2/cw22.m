tic %start pomiaru czasu
RAMP_on=0; % zmiana wartości parametru przed symulacją
sim ('cw2_sim') % uruchomienie symulacji z poziomu matlaba(cw2_sim -> nazwa projektu)
save ('Wyniki_symulacji_bez_rampy.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku
RAMP_on=1;
sim ('cw2_sim') % uruchomienie symulacji z poziomu matlaba
save ('Wyniki_symulacji_z_rampa.mat') % zapisanie całej przestrzeni roboczej Workspace do pliku
toc %stop pomiaru czasu