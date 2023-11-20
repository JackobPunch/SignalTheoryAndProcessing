clear all
close all
% Specify the path to your Excel file
characteristic = ['D:\Semestr 5\Maszyny\cosz'];

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
massw = data{:, 'COS'};
mass = data{:, 'UZ'};

% Plot the characteristics
figure;
plot(mass, massw, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel1 = fit(mass, massw, ['poly1']);
dfit1 = dmodel1(mass);
hold on;
plot(mass, dfit1, 'r-', 'LineWidth', 2);

title('Zależność współczynnika cos fi od napięcia podczas zwarcia');
ylabel('cos fi [-]'); 
xlabel('UZ [V]'); 
legend('Punkty pomiarowe', 'Linia trendu');
ylim([0.75, 0.9]); % Adjusting y-axis limits