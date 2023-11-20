% 新数据表格
DFA_LG = [10, 20, 30, 40, 50, 60, 80, 100]; % DFA/LG浓度
Tar_Yield = [18.06, 13.77, 11.29, 10.28, 9.49, 9.02, 10.3, 8.19];
Water_Yield = [15.3, 18.54, 20.17, 20.97, 21.53, 21.87, 21.41, 23.69];
Char_Yield = [58.17, 57.46, 57.13, 56.98, 57.14, 57.23, 57.15, 57.43];
SynGas_Yield = [8.47, 10.23, 11.41, 11.77, 11.84, 11.88, 11.14, 10.69];
% 创建新的图形窗口
figure;

% 绘制 Tar Yield 折线图
plot(DFA_CE, Tar_Yield, '-o', 'LineWidth', 1.5, 'DisplayName', 'Tar Yield');
hold on; % 保持绘制状态

% 绘制 Water Yield 折线图
plot(DFA_CE, Water_Yield, '-o', 'LineWidth', 1.5, 'DisplayName', 'Water Yield');

% 绘制 Char Yield 折线图
plot(DFA_CE, Char_Yield, '-o', 'LineWidth', 1.5, 'DisplayName', 'Char Yield');

% 绘制 SynGas Yield 折线图
plot(DFA_CE, SynGas_Yield, '-o', 'LineWidth', 1.5, 'DisplayName', 'SynGas Yield');

% 添加标题、坐标轴标签和图例
title('Yield of Decomposition Products vs. DFA/CE Concentration');
xlabel('DFA/CE Concentration (%)');
ylabel('Yield wt.%(daf)');
legend('Location', 'best');

% 显示图形
grid on;
hold off; % 停止保持绘制状态



set(gcf, 'Position', [100, 100, 600, 450]);

