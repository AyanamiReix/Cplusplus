% Data for DFA/CE
mix_ratios_ce = [20, 40, 50, 80, 100];
H2_ce = [26.6, 47.8, 55.6, 65.8, 57.9];
CO_ce = [13.7, 10.6, 8.1, 6.5, 5.3];
CO2_ce = [18.7, 9.8, 5.9, 3.2, 2];
CH4_ce = [3.2, 1.9, 1.3, 1.3, 0.7];
C2H6_ce = [13.8, 8.6, 4.4, 3.4, 3.2];

% Data for DFA/LG
mix_ratios_lg = [20, 40, 50, 80, 100];
H2_lg = [0.67, 0.72, 0.78, 0.81, 0.79];
CO_lg = [15.23, 15.76, 17.305, 19.075, 20.935];
CO2_lg = [24.35, 37.91, 39.26, 41.23, 43.56];
CH4_lg = [27.67, 33.25, 33.86, 30.26, 29.87];
C2H6_lg = [0.08, 0.06, 0.09, 0.07, 0.05];

% Plot for DFA/CE
figure;
subplot(3, 2, 1);
plot(mix_ratios_ce, H2_ce, '-o');
title('H2 Yield for DFA/CE');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

subplot(3, 2, 2);
plot(mix_ratios_ce, CO_ce, '-o');
title('CO Yield for DFA/CE');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

subplot(3, 2, 3);
plot(mix_ratios_ce, CO2_ce, '-o');
title('CO2 Yield for DFA/CE');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

subplot(3, 2, 4);
plot(mix_ratios_ce, CH4_ce, '-o');
title('CH4 Yield for DFA/CE');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

subplot(3, 2, 5);
plot(mix_ratios_ce, C2H6_ce, '-o');
title('C2H6 Yield for DFA/CE');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

% Plot for DFA/LG
figure;
subplot(3, 2, 1);
plot(mix_ratios_lg, H2_lg, '-o');
title('H2 Yield for DFA/LG');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;
subplot(3, 2, 2);
plot(mix_ratios_lg, CO_lg, '-o');
title('CO Yield for DFA/LG');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;
subplot(3, 2, 3);
plot(mix_ratios_lg, CO2_lg, '-o');
title('CO2 Yield for DFA/LG');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;
subplot(3, 2, 4);
plot(mix_ratios_lg, CH4_lg, '-o');
title('CH4 Yield for DFA/LG');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;
subplot(3, 2, 5);
plot(mix_ratios_lg, C2H6_lg, '-o');
title('C2H6 Yield for DFA/LG');
xlabel('Mixing Ratio');
ylabel('Yield');
grid on;

% Calculate Kendall's tau for DFA/CE
kendall_tau_ce = zeros(1, 5);
kendall_p_ce = zeros(1, 5);
gases_ce = {H2_ce, CO_ce, CO2_ce, CH4_ce, C2H6_ce};

for i = 1:5
    [kendall_tau_ce(i), kendall_p_ce(i)] = corr(mix_ratios_ce', gases_ce{i}', 'type', 'Kendall');
end

% Calculate Kendall's tau for DFA/LG
kendall_tau_lg = zeros(1, 5);
kendall_p_lg = zeros(1, 5);
gases_lg = {H2_lg, CO_lg, CO2_lg, CH4_lg, C2H6_lg};

for i = 1:5
    [kendall_tau_lg(i), kendall_p_lg(i)] = corr(mix_ratios_lg', gases_lg{i}', 'type', 'Kendall');
end

% Display Kendall's tau results for DFA/CE
disp('Kendall''s tau coefficients for DFA/CE:');
disp(kendall_tau_ce);
disp('Kendall''s p-values for DFA/CE:');
disp(kendall_p_ce);

% Display Kendall's tau results for DFA/LGa
disp('Kendall''s tau coefficients for DFA/LG:');
disp(kendall_tau_lg);
disp('Kendall''s p-values for DFA/LG:');
disp(kendall_p_lg);
