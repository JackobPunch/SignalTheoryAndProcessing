% Define parameters for the first linear function y1 = a1*x + b1
a1 = 1.036;
b1 = -0.08431;

% Define parameters for the second linear function y2 = a2*x + b2
a2 = 1.044;
b2 = -0.1649;

% Define the range of x values
x = linspace(-10, 10, 100); % Generates 100 points between -10 and 10

% Calculate the y values for each linear function
y1 = a1 * x + b1;
y2 = a2 * x + b2;

% Plotting the linear functions
figure;
plot(x, y1, 'b', 'LineWidth', 2); % Plotting the first linear function in blue
hold on; % To plot the second function on the same figure
plot(x, y2, 'r', 'LineWidth', 2); % Plotting the second linear function in red

% Adding labels and title
xlabel('Masa zadana [g]');
ylabel('Masa otrzymana [g]');
title('Zestawienie aproksymacji wagowych');
legend('y=1.036*x-0.08431', 'y=1.044*x-0.1649');
grid on; % To show the grid in the background
ylim([0, 5]); % Adjusting y-axis limits
xlim([0, 5]); % Adjusting x-axis limits