clc; close all

Linp=[100e-6 1e-3 5e-3];

THD=zeros(1,3);
data_cell=cell(1,3);
data_cell1=cell(1,3);

for n=1:3
    Lin=Linp(n);
    sim("untitled1.slx")

    FFTDATA = power_fftscope(Is);
    FFTDATA.fundamental=50;
    FFTDATA.startTime=1e-8;
    FFTDATA.cycles=1;
    FFTDATA.maxFrequancy=1000;
    FFT=FFTDATA.mag/FFTDATA.magFundamental*100;

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

% data_cell1{4}=[1:17]';
% 
% figure()
% for i=1:3
%     x=data_cell1{4};
%     y=Linp(i)*ones(size(data_cell1{4}));
%     z=data_cell1{i};
% 
%     plot3(x,y,z,'LineWidth', 2);
%     hold on
% end

figure
plot(Linp,THD,'b.', 'MarkerSize', 20);
hold on;
plot(Linp,THD);
title('THD=f(Lin)');
ylabel('THD [ ]'); 
xlabel('Lin [H]');
figure
plot(Linp,FFT51,'b.', 'MarkerSize', 20);
hold on;
plot(Linp,FFT51);
title('I(5)/I(1)=f(Lin)');
ylabel('I(5)/I(1) [ ]'); 
xlabel('Lin [H]');
figure
plot(Linp,FFT71,'b.', 'MarkerSize', 20);
hold on;
plot(Linp,FFT71);
title('I(7)/I(1)=f(Lin)');
ylabel('I(7)/I(1) [ ]'); 
xlabel('Lin [H]');