DFA_CS = [0  10  20  30  40  50  60  80  100];
DFA_CE = [10, 20, 30, 40, 50, 60, 80, 100]; % DFA/CE比例
% DFA_LG=[10	20	30	40	50	60	80	100];
DFA_LG=[10/100	20/100	30/100	40/100	50/100	60/100	80/100	100/100];

%DFA_CS下
% Y1 = [19.46 17.25 15.43 14.14 13.89 13.21 12.84 12.57 12.13]; % 焦油产率
% Y2 = [26.84 27.64 28.11 28.23 28.62 29.01 30.07 30.68 31.02];
% Y3 = [29.21 29.11 29.3 29.34 29.14 29.33 29.47 29.64 29.87];
% Y4 = [24.49 26 27.16 28.29 28.35 28.45 27.62 27.11 26.98];

%DFA_CE下
% Y1=[34.42	38.31	42.69	43.78	44.53	44.41	43.24	45.28];
% Y2=[27.42	21.37	17.84	16.9	16.25	18.25	19.93	16.14];
% Y3=[21.43	24.91	24.17	24.7	24.54	24.59	23.57	24.61];
% Y4=[16.73	15.41	15.3	14.62	14.68	12.75	13.26	13.97];


%DFA_LG下
Y1=[18.06	13.77	11.29	10.28	9.49	9.02	10.3	8.19];
Y2=[15.3	18.54	20.17	20.97	21.53	21.87	21.41	23.69];
Y3=[58.17	57.46	57.13	56.98	57.14	57.23	57.15	57.43];
Y4=[8.47	10.23	11.41	11.77	11.84	11.88	11.14	10.69];

TY =Y2;



% 一元回归分析
mdl_1 = fitlm(DFA_LG, TY);
R2_1 = mdl_1.Rsquared.Ordinary;
fprintf('%f\n', R2_1);

% 二元回归分析
DFA_LG_Squared = DFA_LG.^2;
mdl_2 = fitlm([DFA_LG', DFA_LG_Squared'], TY);
R2_2 = mdl_2.Rsquared.Ordinary;
fprintf('%f\n', R2_2);


% 三元回归分析
DFA_LG_Cubed = DFA_LG.^3;
mdl_3 = fitlm([DFA_LG', DFA_LG_Squared', DFA_LG_Cubed'], TY);
R2_3 = mdl_3.Rsquared.Ordinary;
fprintf('%f\n', R2_3);

% 获取三元回归方程的字符串表示形式
equation_str = mdl_3.Formula.char;
fprintf('三元回归方程: %s\n', equation_str);

% 获取三元回归方程的系数
coefficients = mdl_3.Coefficients.Estimate;
fprintf('三元回归方程的系数:\n');
disp(coefficients);

% 获取回归的标准误差（误差项）
std_error = mdl_3.RMSE;
fprintf('回归标准误差 (误差项): %f\n', std_error);

% 绘制数据散点图和拟合曲线
figure;

% 绘制数据散点图
scatter(DFA_LG, TY, 'filled', 'MarkerEdgeColor', 'k', 'MarkerFaceColor', 'r');
hold on;

% 绘制拟合曲线
x_values = min(DFA_LG):0.01:max(DFA_LG);
y_pred = predict(mdl_3, [x_values', x_values'.^2, x_values'.^3]);
plot(x_values, y_pred, 'b-', 'LineWidth', 2);

xlabel('DFA/CE比例');
ylabel('焦油产率');
title('三元回归拟合曲线');
legend('数据散点', '拟合曲线');
grid on;

hold off;



%以下是所有输出结果:
