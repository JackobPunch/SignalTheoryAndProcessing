clear all
close all
% Specify the path to your Excel file
characteristic = 'C:\Users\rolni\Downloads\Elektronika\f40eaut';

% Import data from the Excel file
data = readtable(characteristic);

% Extract voltage and current data from the table
efficiency = data{:, 'U0'};
current = data{:, 'I0'};

% Plot the characteristics
figure;
plot(current, efficiency, 'b.', 'MarkerSize', 20);
grid on;

% Choose a logarithmic model
logarithmic_model = fittype('a*log(x) + b', 'independent', 'x', 'dependent', 'y');

% Create options for the fit
opts = fitoptions(logarithmic_model);
opts.StartPoint = [0, 0]; % Adjust the starting point as needed

% Fit the data with the logarithmic model using the specified options
dmodel = fit(current, efficiency, logarithmic_model, opts);
dfit = dmodel(current);
hold on;
plot(current, dfit, 'r-', 'LineWidth', 2);

xlabel('Natężenie [A]'); 
ylabel('Sprawność'); 
title('Charakterystyka sprawności od natężenia obciążenia');
legend('Punkty pomiarowe', 'Linia trendu');

% Change the axes
%xlim([0, max(current) + 1]); % Adjusting x-axis limits
%ylim([0, max(efficiency) + 0.1]); % Adjusting y-axis limits



