figure(); % otwarcie nowego okna graficznego
subplot(3,1,1); % otwarcie podokna (subplot)
plot (out.Przebiegi.time, out.Przebiegi.signals.values(:,1:2)) ;
% wydruk wyników do aktywnego podokna
hold on; % odblokowanie możliwości nadpisywania dodatkowych
% przebiegów w tym samym oknie
axis([0e-3 5e-2 0 100]); % ustalenie skali w osi x i osi y
grid on; % aktywacja siatka
title('Przebieg prądu i napięcia'); % tytuł
legend('Iwe','Uwe');% opis poszczególnych przebiegów
subplot(3,1,2);
plot (out.Przebiegi.time, out.Przebiegi.signals.values(:,1));
axis([0e-3 5e-3 0 50]);
grid on;
title('Przebieg prądu'); % tytuł
subplot(3,1,3);
plot (out.Przebiegi.time, out.Przebiegi.signals.values(:,2));
axis([0e-3 05e-3 0 100]);
grid on;
title('Przebieg napięcia'); % tytuł
