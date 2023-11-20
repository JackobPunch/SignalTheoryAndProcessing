clear all
close all
% Specify the path to your Excel file
characteristic = 'C:\Users\rolni\Downloads\Miernictwo\cw1\last.xlsx';

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
massw = data{:, 'g2'};
mass = data{:, 'g1'};

% Plot the characteristics
figure;
plot(mass, massw, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel1 = fit(mass, massw, 'poly1');
dfit1 = dmodel1(mass);
hold on;
plot(mass, dfit1, 'r-', 'LineWidth', 2);

% Calculate the deviation
deviation = massw - dfit1;

% Plot the deviation
figure;
plot(mass, deviation, 'b.', 'MarkerSize', 20);
grid on;
xlabel('Masa zadana [g]'); 
ylabel('Odchylenie [mV/V]');
title('Odchylenie pomiarów od przyjętej aproksymacji');
ylim([-1, 1]); % Adjusting y-axis limits