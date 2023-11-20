clear all
close all
% Specify the path to your Excel file
characteristic = ['C:\Users\rolni\Downloads\Miernictwo\cw1\nap'];

% Import data from the Excel file
data = readtable(characteristic);

% Extract efficiency and current data from the table
massw = data{:, 'g1o'};
mass = data{:, 'g1'};
mmax = data{:, 'g1omax'};
mmin = data{:, 'g1omin'};

% Plot the characteristics
figure;
plot(mass, massw, 'b.', 'MarkerSize', 20);
grid on;

% Fit a polynomial to the data 
dmodel1 = fit(mass, massw, ['poly1']);
dfit1 = dmodel1(mass);
hold on;
plot(mass, dfit1, 'r-', 'LineWidth', 2);

dmodel2 = fit(mass, mmax, ['poly1']);
dfit2 = dmodel2(mass);
hold on;
plot(mass, dfit2, 'b-', 'LineWidth', 2);

dmodel3 = fit(mass, mmin, ['poly1']);
dfit3 = dmodel3(mass);
hold on;
plot(mass, dfit3, 'b-', 'LineWidth', 2);

xlabel('Masa rzeczywista [g]'); 
ylabel('Masa na wzmacniaczu [g]'); 
legend('Punkty pomiarowe', 'Linia trendu','Granice błędu maksymalnego');
ylim([0, max(mass) + 1]); % Adjusting y-axis limits