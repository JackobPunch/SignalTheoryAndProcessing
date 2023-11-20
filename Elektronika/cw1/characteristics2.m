clear all
close all
% Specify the path to your Excel file
characteristic = ['C:\Users\rolni\Downloads\Elektronika\f40eaut'];

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
voltage = data{:, 'U0'};
current = data{:, 'I0'};

% Plot the characteristics
figure;
plot(current, voltage, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel = fit(current, voltage, ['poly1']);
dfit = dmodel(current);
hold on;
plot(current, dfit, 'r-', 'LineWidth', 2);

xlabel('Natężenie [A]'); 
ylabel('Napięcie [V]'); 
title('Charakterystyka napięciowo prądowa');
legend('Punkty pomiarowe', 'Linia trendu');

ylim([min(voltage)-1, max(voltage) + 1]); % Adjusting y-axis limits