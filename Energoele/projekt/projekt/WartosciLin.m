tic 

L_obc=100e-6;
alfa=60; 
sim ('untitled1') 
save ('Wyniki_R60.mat') 

Lin=1e-3;
alfa=0; 
sim ('untitled1') 
save ('Wyniki_R0in2.mat') 
% alfa=45
% sim ('untitled1') 
% save ('Wyniki_R45in2.mat') 
alfa=60;
sim ('untitled1') 
save ('Wyniki_R60in2.mat') 
% alfa=90; 
% sim ('untitled1') 
% save ('Wyniki_R90in2.mat') 
% alfa=135;
% sim ('untitled1') 
% save ('Wyniki_R135in2.mat') 

Lin=5e-3;
alfa=0; 
sim ('untitled1') 
save ('Wyniki_R0in3.mat') 
% alfa=45;
% sim ('untitled1') 
% save ('Wyniki_R45in3.mat') 
alfa=60;
sim ('untitled1') 
save ('Wyniki_R60in3.mat') 
% alfa=90; 
% sim ('untitled1') 
% save ('Wyniki_R90in3.mat') 
% alfa=135;
% sim ('untitled1') 
% save ('Wyniki_R135in3.mat') 
toc 