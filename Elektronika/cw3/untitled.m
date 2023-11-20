clear all
close all
% Specify the path to your Excel file
characteristic = ['D:\Semestr 5\Elektronika\cw3\czest'];

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
voltage = data{:, 'U'};
frequency = data{:, 'f'};

% Plot the characteristics
figure;
plot(frequency, voltage, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel1 = fit(frequency, voltage, ['poly3']);
dfit1 = dmodel1(frequency);
hold on;
plot(frequency, dfit1, 'r-', 'LineWidth', 2);

title('Zależność współczynnika cos fi od napięcia podczas zwarcia');
ylabel('cos fi [-]'); 
xlabel('UZ [V]'); 
legend('Punkty pomiarowe', 'Linia trendu');
% ylim([0.75, 0.9]); % Adjusting y-axis limits