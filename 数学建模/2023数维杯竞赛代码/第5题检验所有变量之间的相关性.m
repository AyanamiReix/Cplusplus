% 假设ALL是一个包含所有因变量数据的矩阵
% 计算相关系数矩阵
R = corrcoef(ALL);


% 显示相关系数矩阵

disp(R);

% 查看相关系数是否显著
% 对相关系数矩阵中的每个元素进行显著性检验
p_value_matrix = zeros(size(R));
n = size(ALL, 1); % 样本大小

for i = 1:size(R, 1)
    for j = i+1:size(R, 2)
        t_stat = R(i,j) * sqrt((n-2) / (1-R(i,j)^2));
        p_value_matrix(i,j) = 2 * (1 - tcdf(abs(t_stat), n-2));
    end
end

% 显示显著性p值矩阵
disp(p_value_matrix);







% 假设Yields是包含四个产物产量的矩阵，DFA_CS是浓度
% 将DFA_CS和Yields合并为一个新的矩阵
AllData = [DFA_CS, Yields];

% 计算条件数
condAllData = cond(AllData);

% 显示结果
disp(['条件数（包含DFA/CS浓度和四个产物产量）: ', num2str(condAllData)]);
% 计算只包含产物产量的条件数
condYields = cond(Yields);

% 显示结果
disp(['条件数（只包含四个产物产量）: ', num2str(condYields)]);





