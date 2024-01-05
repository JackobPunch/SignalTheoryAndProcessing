tic 
L_obc=100e-6;
alfa=0; 
sim ('untitled1') 
save ('Wyniki_R0.mat') 
alfa=45;
sim ('untitled1') 
save ('Wyniki_R45.mat') 
alfa=90; 
sim ('untitled1') 
save ('Wyniki_R90.mat') 
alfa=135;
sim ('untitled1') 
save ('Wyniki_R135.mat') 

L_obc=200e-3;
alfa=0;
sim ('untitled1') 
save ('Wyniki_L0.mat') 
alfa=45;
sim ('untitled1') 
save ('Wyniki_L45.mat') 
alfa=90;
sim ('untitled1') 
save ('Wyniki_L90.mat')
alfa=135;
sim ('untitled1') 
save ('Wyniki_L135.mat') 
toc 