% 输入数据
DFA_CS = [0, 10, 20, 30, 40, 50, 60, 80, 100]; % DFA/CS比例
tar_yield = [19.46, 17.25, 15.43, 14.14, 13.89, 13.21, 12.84, 12.57, 12.13];
water_yield = [26.84, 27.64, 28.11, 28.23, 28.62, 29.01, 30.07, 30.68, 31.02];
char_yield = [29.21, 29.11, 29.3, 29.34, 29.14, 29.33, 29.47, 29.64, 29.87];
syngas_yield = [24.49, 26, 27.16, 28.29, 28.35, 28.45, 27.62, 27.11, 26.98];

% 转换为百分比形式
DFA_CS = DFA_CS / 100;

% 构建设计矩阵
X = [ones(length(DFA_CS), 1) DFA_CS' tar_yield' water_yield' char_yield' syngas_yield'];

% 计算VIF
VIF = zeros(1, size(X, 2));
for i = 2:size(X, 2)
    [b, bint, r, rint, stats] = regress(X(:,i), X(:,[1:i-1, i+1:end]));
    VIF(i) = 1 / (1 - stats(1));
end

% 显示VIF值
disp('VIF values:');
disp(VIF);

% 计算条件数
[U, S, V] = svd(X);
condition_numbers = max(diag(S)) ./ diag(S);

% 显示条件数
disp('Condition numbers:');
disp(condition_numbers);
