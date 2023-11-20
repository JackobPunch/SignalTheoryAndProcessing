clear all
close all
% Specify the path to your Excel file
characteristic = ['D:\Semestr 5\Elektronika\cw4\Zeszyt'];

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
voltage = data{:, 'f'};
frequency = data{:, 'U'};

% Plot the characteristics
figure;
plot(frequency, voltage, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel1 = fit(frequency, voltage, ['poly1']);
dfit1 = dmodel1(frequency);
hold on;
plot(frequency, dfit1, 'r-', 'LineWidth', 2);

title('Charakterystyka częstotliwości od napięcia');
ylabel('f [Hz]'); 
xlabel('U[V]'); 
legend('Punkty pomiarowe', 'Linia trendu','Location', 'best');
xlim([0, 3.5]); % Adjusting y-axis limits
ylim([0, 3500]); % Adjusting y-axis limits