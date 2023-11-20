figure(); % otwarcie nowego okna graficznego
subplot(2,1,1); % otwarcie podokna (subplot) 
plot (out.wyniki_structure.time, out.wyniki_structure.signals.values(:,1)) ;
 % wydruk wyników do aktywnego podokna 
hold on; % odblokowanie możliwości nadpisywania dodatkowych 
 % przebiegów w tym samym oknie 
axis([0e-3 20e-3 -2 2]); 
axis([0e-3 20e-3 -2 2]); % ustalenie skali w osi x i osi y 
grid on; % aktywacja siatka
title('Przebieg'); % tytuł 
legend('sinus'); % opis poszczególnych przebiegów
subplot(2,1,2);
plot (out.wyniki_structure.time, out.wyniki_structure.signals.values(:,2),'--r');
axis([0e-3 20e-3 -2 2]); 
legend('K*sinus');
grid on; 
