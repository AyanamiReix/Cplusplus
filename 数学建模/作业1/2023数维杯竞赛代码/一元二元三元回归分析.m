% 定义数据
X_ratio = [0; 10; 20; 30; 40; 50; 60; 80; 100]; % 脱硫灰与棉花秸秆的比例
Y_tar = [19.46; 17.25; 15.43; 14.14; 13.89; 13.21; 12.84; 12.57; 12.13]; % 焦油产率
Y_water = [26.84; 27.64; 28.11; 28.23; 28.62; 29.01; 30.07; 30.68; 31.02];
Y_char = [29.21; 29.11; 29.3; 29.34; 29.14; 29.33; 29.47; 29.64; 29.87];
Y_syngas = [24.49; 26; 27.16; 28.29; 28.35; 28.45; 27.62; 27.11; 26.98];



% 转换X_ratio为百分比形式
X_ratio = X_ratio / 100;

% 一元回归分析
mdl_1 = fitlm(X_ratio, Y_tar);

% 计算预测值和R方
Y_pred_1 = predict(mdl_1, X_ratio);
R2_1 = mdl_1.Rsquared.Ordinary;

% 绘制原始数据点和一元回归拟合线
figure;
scatter(X_ratio, Y_tar, 'filled');
hold on;
plot(X_ratio, Y_pred_1, 'b-', 'LineWidth', 2);
xlabel('脱硫灰/棉花秸秆比例');
ylabel('焦油产率 (%)');
title(sprintf('一元回归拟合曲线 (R^2 = %.2f)', R2_1));



% 二元回归分析
X = [X_ratio, X_ratio.^2]; % 添加第二个自变量
mdl_2 = fitlm(X, Y_tar);

% 计算预测值和R方
Y_pred_2 = predict(mdl_2, X);
R2_2 = mdl_2.Rsquared.Ordinary;

% 绘制原始数据点和二元回归拟合线

scatter(X_ratio, Y_tar, 'filled');
hold on;
plot(X_ratio, Y_pred_2, 'r-', 'LineWidth', 2);
xlabel('脱硫灰/棉花秸秆比例');
ylabel('焦油产率 (%)');
title(sprintf('二元回归拟合曲线 (R^2 = %.2f)', R2_2));

% 三元回归分析a
X = [X_ratio, X_ratio.^2, X_ratio.^3]; % 添加第三个自变量
mdl_3 = fitlm(X, Y_tar);

% 计算预测值和R方
Y_pred_3 = predict(mdl_3, X);
R2_3 = mdl_3.Rsquared.Ordinary;

% 绘制原始数据点和三元回归拟合线

% 绘制原始数据点
scatter(X_ratio, Y_tar, 100, 'o', 'filled');


plot(X_ratio, Y_pred_3, 'm-', 'LineWidth', 2);
xlabel('脱硫灰/棉花秸秆比例');
ylabel('焦油产率 (%)');
title(sprintf('三元回归拟合曲线 (R^2 = %.2f)', R2_3));
hold off;

