clear all
close all

% Specify the path to your Excel file
characteristic = 'D:\Semestr 5\Elektronika\cw3\czest'; % Updated the file path

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
voltage = data{:, 'U'};
frequency = data{:, 'f'};

% Plot the characteristics
figure;
plot(frequency, voltage, 'b.', 'MarkerSize', 20);
grid on;

% Fit a linear model to the data that passes through the first data point
firstPoint = [frequency(1), voltage(1)]; % First data point
dmodel1 = fit(frequency, voltage, 'poly2'); % Use a linear model
dfit1 = dmodel1(frequency);
hold on;
plot(frequency, dfit1, 'r-', 'LineWidth', 2);

% Customize the x-axis ticks and labels
xticks([0 1 10 100]); % Set the locations of the x-ticks
xticklabels({'0', '1', '10', '100'}); % Set the labels for the x-ticks

% Set the x-axis to a logarithmic scale
set(gca, 'XScale', 'log');

% Add labels and title
xlabel('Frequency');
ylabel('Voltage');
title('Voltage vs. Frequency');

% Display the grid and legend
grid on;
legend('Data', 'Fitted Curve', 'Location', 'best');