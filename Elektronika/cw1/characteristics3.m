clear all
close all
% Specify the path to your Excel file
characteristic = 'C:\Users\rolni\Downloads\Elektronika\f40eaut';

% Import data from the Excel file
data = readtable(characteristic);

% Extract voltage and current data from the table
efficiency = data{:, 'n'};
current = data{:, 'I0'};

% Plot the characteristics
figure;
plot(current, efficiency, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel = fit(current, efficiency, 'poly1');
dfit = dmodel(current);

hold on;
plot(current, dfit, 'r-', 'LineWidth', 2);
xlabel('Natężenie [A]'); 
ylabel('Sprawność'); 
title('Charakterystyka sprawności od natężenia obiążenia');
legend('Punkty pomiarowe', 'Linia trendu');

ylim([0, max(efficiency) + 0.1]); % Adjusting y-axis limits