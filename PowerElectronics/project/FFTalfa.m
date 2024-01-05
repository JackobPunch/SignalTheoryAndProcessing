clc; close all

alfap=[0 45 90 135];

THD=zeros(1,4);
data_cell=cell(1,4);
data_cell1=cell(1,4);

for n=1:4
    alfa=alfap(n);
    sim("untitled1.slx")
    
    FFTDATA = power_fftscope(Is)
    FFTDATA.fundamental=50;
    FFTDATA.startTime=0;
    FFTDATA.cycles=1;
    FFTDATA.maxFrequancy=1000;
    FFT=FFTDATA.mag/FFTDATA.magFundamental*100;
    FFTDATA

    disp(FFTDATA.freq);
    
    sampling_frequency = 1 / (Is.Time(2) - Is.Time(1));
    disp(['Sampling frequency: ' num2str(sampling_frequency)]);

    figure() 
    bar(FFTDATA.freq,FFT); 
    grid on;
    title('FFT');
    ylabel('Mag [% of Fundamental]'); 
    xlabel('Frequency [Hz]'); 
    
    THD(n)=FFTDATA.THD;
    data_cell{n}=FFTDATA.phase;
    data_cell1{n}=cos(data_cell{n});
    
    FFT51(n)=FFT(5)/FFT(1);
    FFT71(n)=FFT(7)/FFT(1);
end

data_cell1{5}=[1:17]';

figure()
for i=1:4
    x=data_cell1{5};
    y=alfap(i)*ones(size(data_cell1{5}));
    z=data_cell1{i};

    plot3(x,y,z,'LineWidth', 2);
    hold on
end
title('Wykres cosfi f(alfa)');
ylabel('alfa [degrees]'); 
xlabel('harmoniczna [ ]');
zlabel('cos fi [ ]')
figure
plot(alfap,THD,'b.', 'MarkerSize', 20);
hold on;
plot(alfap,THD);
title('THD=f(alfa)');
ylabel('THD [ ]'); 
xlabel('alfa [degrees]'); 
figure
plot(alfap,FFT51,'b.', 'MarkerSize', 20);
hold on;
plot(alfap,FFT51);
title('I(5)/I(1)=f(alfa)');
ylabel('I(5)/I(1) [ ]'); 
xlabel('alfa [degrees]');
figure
plot(alfap,FFT71,'b.', 'MarkerSize', 20);
hold on;
plot(alfap,FFT71);
title('I(7)/I(1)=f(alfa)');
ylabel('I(5)/I(1) [ ]'); 
xlabel('alfa [degrees]');
