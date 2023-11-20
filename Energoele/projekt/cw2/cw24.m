%% KROK 1: Utworzenie struktury dla funkcji power_fft_scope dla zapisanej w workspace przykładowej zmiennej iload (w formacie Structure with time)
FFTDATA = power_fftscope(out.Przebiegi); % 
%% KROK 2: Ustawienie parametrów analizy - szukaj w HELP do funkcji
FFTDATA.fundamental=20e3; % ustawienie podstawowej harmonicznej sygnału (w Hz)
FFTDATA.startTime=0; 
FFTDATA.cycles=40; 
FFTDATA.maxFrequency=1000e3;
FFTDATA.THDmaxFrequency=inf;
FFTDATA.freqAxis="hertz";
%% KROK 3: ponowne przeliczenie funkcji
FFTDATA = power_fftscope(FFTDATA); 
%% KROK 4: Wydobycie i obróbka uzyskanych wyników
FFT=FFTDATA.mag/FFTDATA.magFundamental*100; 
figure() 
bar(FFTDATA.freq,FFTDATA.mag/FFTDATA.magFundamental*100); 
grid on;