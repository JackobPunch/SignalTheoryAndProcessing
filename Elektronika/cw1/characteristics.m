clear all
close all
% Specify the path to your Excel file
characteristic = 'C:\Users\rolni\Downloads\Elektronika\f40e04';

% Import data from the Excel file
data = readtable(characteristic);

% Extract voltage and current data from the table
voltage = data{:, 'U0'};
current = data{:, 'I0'};

% Plot the characteristics
figure;
plot(current, voltage, 'b.', 'MarkerSize', 20);
hold on;

% Fit a polynomial to the data 
coefficients = polyfit(current, voltage, 2);
fitted_voltage = polyval(coefficients, current);

% Plot the trend line
plot(current, fitted_voltage, 'r-', 'LineWidth', 2);
xlabel('Natężenie [A]'); 
ylabel('Napięcie [V]'); 
title('Charakterystyka napięciowo-prądowa');
legend('Punkty pomiarowe', 'Linia trendu');
grid on;