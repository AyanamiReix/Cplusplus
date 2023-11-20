% Kendall tau coefficients data
kendall_data = [
    1, 0.066666667, -1, 0.2, 0.2, 0.866666667, 0.276026224, 0.2, -0.466666667;
    0.8, -1, -1, -0.948683298, -1, NaN, NaN, NaN, NaN;
    0.8, 1, 1, 0, -0.4, NaN, NaN, NaN, NaN
];

% Gas names for the x-axis
gases = {'H2', 'CO', 'CO2', 'CH4', 'C2H6', 'C3H8', 'C3H6', 'C2H4', 'C4H10'};

% Table names for the y-axis
tables = {'DFA/CS', 'DFA/CE', 'DFA/LG'};

% Generate the colormap
cmap = [
    linspace(0, 1, 128)', linspace(0, 1, 128)', ones(128, 1);  % Blue to white
    ones(128, 1), linspace(1, 0, 128)', linspace(1, 0, 128)'   % White to red
];

% Create the heatmap
figure;
h = heatmap(gases, tables, kendall_data, 'Colormap', cmap, 'MissingDataColor', 'white');

% Set color limits to [-1, 1]
h.ColorLimits = [-1, 1];

% Add title
title('Kendall Tau Coefficients Heatmap');
