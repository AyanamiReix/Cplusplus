#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <iomanip>

using namespace std;

//cuttingPatterns 为18种切割模式
std::vector<std::vector<int>> cuttingPatterns = {
    {5,0,0,0},
    {5,0,1,0},
    {4,2,0,0},
    {4,1,1,0},
    {3,3,0,0},
    {3,2,1,0},
    {3,0,0,2},
    {2,4,0,0},
    {2,1,0,2},
    {2,0,1,2},
    {1,2,0,2},
    {1,1,2,1},
    {1,0,3,1},
    {0,3,1,1},
    {0,2,2,1},
    {0,1,3,1},
    {0,0,5,0},
    {0,0,0,4}
};

int evaluateSolution(const std::vector<int>& usage) {
    std::vector<int> production(4, 0);
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < 4; j++) {
            production[j] += cuttingPatterns[i][j] * usage[i];
        }
    }

    // Check if the solution meets the requirements 如果不符合切割要求的话，返回一个较大值（较差方案，使之不得不舍弃
    if (production[0] < 15 || production[1] < 28 || production[2] < 21 || production[3] < 30) {
        return std::numeric_limits<int>::max();
    }

    std::vector<std::pair<int, int>> usageWithIndex; // Pair of (usage, index)
    for(int i = 0; i < 18; i++) {
        usageWithIndex.push_back({usage[i], i});
    }
    // Sort by usage
    std::sort(usageWithIndex.begin(), usageWithIndex.end(), [](const auto& a, const auto& b){
        return a.first > b.first;
    });

    int totalAdditionalCost = 0;
    int lastUsage = -1;
    int rank = 0;
    
    for(const auto& [currentUsage, index] : usageWithIndex) {
        if (currentUsage != lastUsage) {
            rank++;
            lastUsage = currentUsage;
        }
        int additionalCostPerPipe = rank * 10;
        totalAdditionalCost += currentUsage * additionalCostPerPipe;

    }

    int totalCost = totalAdditionalCost;
    for (int i = 0; i < 18; i++) {
        totalCost += usage[i] * 100; // Base cost of each pipe
    }
  
    return totalCost;
}


std::vector<int> simulatedAnnealing() {
//std::pair<std::vector<int>, std::vector<int>> simulatedAnnealing() {
    std::vector<int> bestProduction(4, 0);

    srand(time(nullptr));
    std::vector<int> currentUsage(18, 0);
    int currentScore = evaluateSolution(currentUsage);

    std::vector<int> bestUsage = currentUsage;
    int bestScore = currentScore;

    double temperature = 1000;
    double coolingRate = 0.995;
    int iterations = 100000;

    for(int i = 0; i < iterations; i++) {
        std::vector<int> neighborUsage = currentUsage;
        int randomPattern = rand() % 18;
        neighborUsage[randomPattern] = (neighborUsage[randomPattern] + 1) % 10;  // We can use a pattern up to 10 times
        int neighborScore = evaluateSolution(neighborUsage);

        // If the neighboring solution is better or accepted with a certain probability
        if(neighborScore < currentScore || (double)rand() / RAND_MAX < exp((currentScore - neighborScore) / temperature)) {
            currentUsage = neighborUsage;
            currentScore = neighborScore;
        }

        if(neighborScore < bestScore) {
            bestScore = neighborScore;
            bestUsage = neighborUsage;
        }

        temperature *= coolingRate;
    }
    return bestUsage;
}



int main(){
   
    std::vector<int> pipeLengths = {290, 315, 350, 455};




    std::vector<int> bestUsage = simulatedAnnealing();

        // Step 1: 将每个模式的使用次数映射到模式索引
    std::vector<std::pair<int, int>> usageWithIndex;
    for (int i = 0; i < bestUsage.size(); ++i) {
        if (bestUsage[i] > 0) {
            usageWithIndex.push_back({bestUsage[i], i});
        }
    }

    // Step 2: 根据使用次数进行排序
    std::sort(usageWithIndex.begin(), usageWithIndex.end(), 
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) { 
                return a.first > b.first; 
            });

    // Step 3: 根据排名计算附加费用
    int lastUsage = -1;  // 保存上一次的使用次数
    int currentRank = 0;
    int totalAdditionalCost = 0;
    for (const auto& [usageCount, patternIndex] : usageWithIndex) {
        if (usageCount != lastUsage) {
            ++currentRank;
            lastUsage = usageCount;
        }
        
        int additionalCostPerPipe = currentRank * 10; // 根据排名计算附加成本
        totalAdditionalCost += usageCount * additionalCostPerPipe;  // 累加总附加成本
    }
    int numPipesUsed = std::accumulate(bestUsage.begin(), bestUsage.end(), 0);
    int totalCost = (numPipesUsed * 100) + totalAdditionalCost;
    
    
/*--------------------------------------------------------------以下为打印------------------------------------------------------------------------------------------------*/

     // Step 1: 将每个模式的使用次数映射到模式索引
    std::vector<std::pair<int, int>> usageWithIndex;
    for (int i = 0; i < bestUsage.size(); ++i) {
        if (bestUsage[i] > 0) {
            usageWithIndex.push_back({bestUsage[i], i});
        }
    }

    // Step 2: 根据使用次数进行排序
    std::sort(usageWithIndex.begin(), usageWithIndex.end(), 
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) { 
                return a.first > b.first; 
            });

    // Step 3: 根据排名计算附加费用
    int lastUsage = -1;  // 保存上一次的使用次数
    int currentRank = 0;
    int totalAdditionalCost = 0;
    for (const auto& [usageCount, patternIndex] : usageWithIndex) {
        if (usageCount != lastUsage) {
            ++currentRank;
            lastUsage = usageCount;
        }
        
        int additionalCostPerPipe = currentRank * 10; // 根据排名计算附加成本
        totalAdditionalCost += usageCount * additionalCostPerPipe;  // 累加总附加成本

        std::cout << "Pattern " << std::setw(2) << (patternIndex + 1) << " used: " << std::setw(2) << usageCount << " times."
                << std::setw(5) << " |Additional cost per pipe:" << std::setw(3) << additionalCostPerPipe
                << std::setw(5) << " | Total additional cost:" << std::setw(4) << usageCount * additionalCostPerPipe;

        for(int i = 0; i < 4; i++) {
            std::cout << std::setw(5) << " |" << pipeLengths[i] << "mm: " << std::setw(2) << cuttingPatterns[patternIndex][i] * usageCount;
        }
        std::cout << std::endl;
    }




/*--------------------------------------------------------------以下为打印------------------------------------------------------------------------------------------------*/

    int numPipesUsed = std::accumulate(bestUsage.begin(), bestUsage.end(), 0);
    std::vector<int> bestProduction(4, 0); 
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < 4; j++) {
            bestProduction[j] += cuttingPatterns[i][j] * bestUsage[i];
        }
    }

    
    int totalCost = (numPipesUsed * 100) + totalAdditionalCost;
        
    std::cout << "Total Cost: " << totalCost << std::endl;

// 输出最终生成的四种钢管的总数
    for(int i = 0; i < 4; i++) 
    {
        std::cout << pipeLengths[i] << "mm: " << bestProduction[i] << std::endl;
    }
    return 0;

}