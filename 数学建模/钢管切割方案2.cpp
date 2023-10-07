#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

// 定义一个递归函数来寻找所有可能的切割方案
void findSolutions(int remainingLength,           // 剩余需要切割的长度
                   const std::vector<int> &sizes, // 可用的切割尺寸
                   std::vector<int> &currentCut,  // 当前已经选择的切割方案
                   std::vector<std::vector<int>> &solutions, // 存储所有有效的切割方案
                   int minSize,                             // 可用尺寸中的最小值
                   int startPos = 0)                        // 开始选择的位置
{
    // 如果剩余长度小于最小尺寸并大于0，则这是一个有效的方案
    if (remainingLength < minSize && remainingLength >= 0) {
        solutions.push_back(currentCut);
        return;
    }

    // 遍历所有尺寸，从startPos开始
    for (int i = startPos; i < sizes.size(); ++i) {
        // 只有当剩余长度足够大时，才选择当前尺寸
        if (remainingLength >= sizes[i]) {
            // 将当前尺寸添加到currentCut中
            currentCut.push_back(sizes[i]);
            // 递归地寻找后续的切割方案，传递i作为新的startPos
            findSolutions(remainingLength - sizes[i], sizes, currentCut, solutions, minSize, i);
            // 回溯：撤销最后的选择，尝试其他尺寸
            currentCut.pop_back();
        }
    }
}

int main() {
    // 可用的切割尺寸
    std::vector<int> sizes = {4, 5, 6, 8};
    // 总的需要切割的长度
    int totalLength = 19;
    // currentCut用于在递归中存储当前的切割方案
    std::vector<int> currentCut;
    // solutions用于存储所有找到的有效的切割方案
    std::vector<std::vector<int>> solutions;
    // 获取sizes中的最小值
    int minSize = *std::min_element(sizes.begin(), sizes.end());

    // 调用递归函数开始寻找切割方案
    findSolutions(totalLength, sizes, currentCut, solutions, minSize);

    // 输出所有找到的切割方案和相应的余料
    std::cout << "Cutting Schemes:               Residual:" << std::endl;
    std::cout << "----------------------------   ---------" << std::endl;
    for (const auto &solution : solutions) {
        for (int i = 0; i < sizes.size(); ++i) {
            if (i < solution.size()) {
                std::cout << std::setw(4) << solution[i] << " ";
            } else {
                std::cout << "     "; // 为不足的部分输出5个空格
            }
        }
        std::cout << std::setw(12) << "Residual: " << totalLength - std::accumulate(solution.begin(), solution.end(), 0) << "\n";
    }

    // 输出找到的方案总数
    std::cout << "\nTotal number of solutions: " << solutions.size() << std::endl;

    return 0;
}
