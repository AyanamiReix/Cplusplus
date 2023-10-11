#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

// 递归函数来找到所有可能的切割方案
void findSolutions(int remainingLength,  // 当前剩余的钢管长度
                   const std::vector<int> &sizes,  // 可用的切割尺寸
                   std::vector<int> &currentCut,  // 当前正在考虑的切割方案
                   std::vector<std::vector<int>> &solutions,  // 所有找到的切割方案
                   int minSize,  // 可用的最小切割尺寸
                   int startPos = 0)  // 当前切割尺寸的开始位置
{
    // 当剩余长度小于最小尺寸但大于等于0时，保存当前方案
    if (remainingLength < minSize && remainingLength >= 0) {
        solutions.push_back(currentCut);
        return;
    }

    // 循环遍历所有可能的切割尺寸
    for (int i = startPos; i < sizes.size(); ++i) {
        // 如果剩余长度允许进行当前切割
        if (remainingLength >= sizes[i]) {
            // 将当前尺寸添加到当前方案中
            currentCut.push_back(sizes[i]);
            // 递归寻找更多的切割方案，使用startPos确保不产生重复方案（例如4,5和5,4）
            findSolutions(remainingLength - sizes[i], sizes, currentCut, solutions, minSize, i);
            // 移除刚刚添加的尺寸，以回溯到前一个状态
            currentCut.pop_back();
        }
    }
}

int main() {
    // 可用的切割尺寸
    std::vector<int> sizes = {290, 315, 350, 455};
    // 钢管的总长度
    int totalLength = 1850;
    // 当前正在考虑的切割方案
    std::vector<int> currentCut;
    // 用于存储所有找到的切割方案
    std::vector<std::vector<int>> solutions;
    // 计算可用的最小切割尺寸
    int minSize = *std::min_element(sizes.begin(), sizes.end());

    // 调用函数来找到所有可能的切割方案
    findSolutions(totalLength, sizes, currentCut, solutions, minSize);

    const int maxCuts = 6;  // 设置一个方案中最多有6个切割

    // 输出余料小于最小尺寸且大于等于0的方案
    int count1 = 0;
    std::cout << "Cutting Schemes (Residual < MinSize and >= 0):" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    for (const auto &solution : solutions) {
        for (int i = 0; i < maxCuts; ++i) {
            if (i < solution.size()) {
                std::cout << std::setw(5) << solution[i] << " ";
            } else {
                std::cout << "      ";  // 6个空格用于对齐输出
            }
        }
        int residual = totalLength - std::accumulate(solution.begin(), solution.end(), 0);
        std::cout << "Residual: " << residual << "\n";
        count1++;
    }
    std::cout << "\nTotal number of solutions for Residual < MinSize and >= 0: " << count1 << std::endl;

    // 输出余料小于100的方案
    int count2 = 0;
    std::cout << "\nCutting Schemes (Residual < 100):" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (const auto &solution : solutions) {
        int residual = totalLength - std::accumulate(solution.begin(), solution.end(), 0);
        if (residual <= 100) {
            for (int i = 0; i < maxCuts; ++i) {
                if (i < solution.size()) {
                    std::cout << std::setw(5) << solution[i] << " ";
                } else {
                    std::cout << "      ";  // 6个空格用于对齐输出
                }
            }
            std::cout << "Residual: " << residual << "\n";
            count2++;
        }
    }
    std::cout << "\nTotal number of solutions for Residual < 100: " << count2 << std::endl;

    return 0;
}



// START with currentCut = []

// CALL findSolutions(7, {2, 3, 4}, currentCut, solutions, 2)

// 1. Choose 2
//    -> currentCut = [2]
//    -> Recur with remainingLength = 5

//    1.1. Choose 2
//        -> currentCut = [2, 2]
//        -> Recur with remainingLength = 3

//        1.1.1. Choose 2
//              -> currentCut = [2, 2, 2]
//              -> Recur with remainingLength = 1 (end recursion, because 1 < minSize)
//              -> currentCut = [2, 2] (after popping the last choice)

//        1.1.2. Choose 3
//              -> currentCut = [2, 2, 3]
//              -> Recur with remainingLength = 0 (valid combination)
//              -> currentCut = [2, 2] (after popping the last choice)

//        -> currentCut = [2] (after popping the last choice)

//    1.2. Choose 3
//        -> currentCut = [2, 3]
//        -> Recur with remainingLength = 2

//        1.2.1. Choose 2
//              -> currentCut = [2, 3, 2]
//              -> Recur with remainingLength = 0 (valid combination)
//              -> currentCut = [2, 3] (after popping the last choice)

//        -> currentCut = [2] (after popping the last choice)

//    -> currentCut = [] (after popping the last choice)

// 2. Choose 3
//    -> currentCut = [3]
//    -> Recur with remainingLength = 4

//    2.1. Choose 2
//        -> currentCut = [3, 2]
//        -> Recur with remainingLength = 2

//        2.1.1. Choose 2
//              -> currentCut = [3, 2, 2]
//              -> Recur with remainingLength = 0 (valid combination)
//              -> currentCut = [3, 2] (after popping the last choice)

//        -> currentCut = [3] (after popping the last choice)

//    2.2. Choose 3 (No valid combinations, as it leaves 1 < minSize)
//    2.3. Choose 4 (No valid combinations, as it leaves 0 < minSize)

//    -> currentCut = [] (after popping the last choice)

// 3. Choose 4
//    -> currentCut = [4]
//    -> Recur with remainingLength = 3

//    3.1. Choose 2
//        -> currentCut = [4, 2]
//        -> Recur with remainingLength = 1 (end recursion, because 1 < minSize)
//        -> currentCut = [4] (after popping the last choice)

//    3.2. Choose 3
//        -> currentCut = [4, 3]
//        -> Recur with remainingLength = 0 (valid combination)
//        -> currentCut = [4] (after popping the last choice)

//    -> currentCut = [] (after popping the last choice)

// End of the function.
