% 设置输出格式以显示更多小数位
format long;

% 假设数据

%DFA_CS = [0/100, 10/100, 20/100, 30/100, 40/100, 50/100, 60/100, 80/100, 100/100]; % DFA/CE比例
% tar_yield = [19.46, 17.25, 15.43, 14.14, 13.89, 13.21, 12.84, 12.57, 12.13];
% water_yield = [26.84, 27.64, 28.11, 28.23, 28.62, 29.01, 30.07, 30.68, 31.02];
% char_yield = [29.21, 29.11, 29.3, 29.34, 29.14, 29.33, 29.47, 29.64, 29.87];
% syngas_yield = [24.49, 26, 27.16, 28.29, 28.35, 28.45, 27.62, 27.11, 26.98];




%DFA_CE下
% DFA_CE = [10/100, 20/100, 30/100, 40/100, 50/100, 60/100, 80/100, 100/100]; % DFA/CE比例
% tar_yield=[34.42	38.31	42.69	43.78	44.53	44.41	43.24	45.28];
% water_yield=[27.42	21.37	17.84	16.9	16.25	18.25	19.93	16.14];
% char_yield=[21.43	24.91	24.17	24.7	24.54	24.59	23.57	24.61];
% syngas_yield=[16.73	15.41	15.3	14.62	14.68	12.75	13.26	13.97];

%DFA_LG下
DFA_LG=[10/100	20/100	30/100	40/100	50/100	60/100	80/100	100/100];
tar_yield=[18.06	13.77	11.29	10.28	9.49	9.02	10.3	8.19];
water_yield=[15.3	18.54	20.17	20.97	21.53	21.87	21.41	23.69];
char_yield=[58.17	57.46	57.13	56.98	57.14	57.23	57.15	57.43];
syngas_yield=[8.47	10.23	11.41	11.77	11.84	11.88	11.14	10.69];



% 将DFA/CE比例转换为列向量
DFA_LG = DFA_LG(:);

% 计算Kendall tau-b相关性系数
[kendall_tar, p_tar] = corr(DFA_LG, tar_yield(:), 'type', 'kendall');
[kendall_water, p_water] = corr(DFA_LG, water_yield(:), 'type', 'kendall');
[kendall_char, p_char] = corr(DFA_LG, char_yield(:), 'type', 'kendall');
[kendall_syngas, p_syngas] = corr(DFA_LG, syngas_yield(:), 'type', 'kendall');

% 输出结果，显示更多小数位
fprintf('焦油产率的Kendall tau-b: %.10f, p值: %.10f\n', kendall_tar, p_tar);
fprintf('水产率的Kendall tau-b: %.10f, p值: %.10f\n', kendall_water, p_water);
fprintf('焦炭产率的Kendall tau-b: %.10f, p值: %.10f\n', kendall_char, p_char);
fprintf('合成气产率的Kendall tau-b: %.10f, p值: %.10f\n', kendall_syngas, p_syngas);

% 恢复默认的输出格式
format;
