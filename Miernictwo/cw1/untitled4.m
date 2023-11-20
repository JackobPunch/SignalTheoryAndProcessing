clear all
close all
% Specify the path to your Excel file
characteristic = 'C:\Users\rolni\Downloads\Miernictwo\cw1\wag.xlsx';

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
massw = data{:, 'g2o'};
mass = data{:, 'g2'};
mmax = data{:, 'g2omax'};
mmin = data{:, 'g2omin'};

% Fit a polynomial to the data 
dmodel1 = fit(mass, massw, 'poly1');
dfit1 = dmodel1(mass);

dmodel2 = fit(mass, mmax, 'poly1');
dfit2 = dmodel2(mass);

dmodel3 = fit(mass, mmin, 'poly1');
dfit3 = dmodel3(mass);

% Plot the variation of approximations 2 and 3 against 1
figure;
hold on;
plot(mass, dfit2 - dfit1, 'g-', 'LineWidth', 2);
% plot(mass, dfit3 - dfit1, 'm-', 'LineWidth', 2);
grid on;
xlabel('Masa zadana [g]'); 
ylabel('Odchylenie [g]');
title('Odchylenie błędu maksymalnego');
