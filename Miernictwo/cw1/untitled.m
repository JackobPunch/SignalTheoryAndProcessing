clear all
close all
% Specify the path to your Excel file
characteristic = ['C:\Users\rolni\Downloads\Miernictwo\cw1\last'];

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
dmodel1 = fit(mass, massw, ['poly1']);
dfit1 = dmodel1(mass);
hold on;
plot(mass, dfit1, 'r-', 'LineWidth', 2);

title('Wykres pomiarów wartości wejściowej wzmacniacza');
ylabel('Wertość wejściowa [mV/V]'); 
xlabel('Masa [g]'); 
legend('Punkty pomiarowe', 'Linia trendu');
ylim([0, max(massw) + 0.1]); % Adjusting y-axis limits