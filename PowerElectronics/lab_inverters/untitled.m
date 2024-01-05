clear all;
close all;

M = [0.00182475 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2];
U = [5.35E-10
0.0704
0.1434
0.2126
0.2908
0.3648
0.4378
0.5115
0.5843
0.6580
0.7308
0.7780
0.8050
0.8245
0.8400
0.8530
0.8638
0.8725
0.8805
0.8875
0.8938
];

% Split the data into two parts based on M values
M1 = M(M <= 1);
U1 = U(1:length(M1));

M2 = M(M >= 1);
U2 = U(length(M1):end);

% Fit linear trend lines for each part
C1 = polyfit(M1, U1, 1);
C2 = polyfit(M2, U2, 4);

% Find the intersection point
M_intersection = 1;
U_intersection = polyval(C1, M_intersection);

% Evaluate the fitted polynomials for plotting
D1 = polyval(C1, M1);
D2 = polyval(C2, M2);

% Plot the data and trend lines
figure(2);
plot(M, U, 'b.', 'MarkerSize', 20);
hold on;

% Plot the first linear trend line up to M=1
plot(M1, D1, 'r-', 'LineWidth', 2);

% Plot the second linear trend line for M values greater than 1
plot(M2, D2, 'r-', 'LineWidth', 2);

xlabel('Ma [-]');
ylabel('Uobc/Uz [-]');
grid on;
title('Zależność skutecznego napięcia wyjściowego od współczynnika Ma');
legend('Punkty pomiarowe', 'Linia trendu','Location', 'Best');

axis([min(M) max(M) min(U) max(U)]);