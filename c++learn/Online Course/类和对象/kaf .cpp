#include <iostream>
#include <boost/math/distributions/chi_squared.hpp>

int main() {
    // 观察频数
    int observed[2][2] = {{27, 8}, {24, 11}};

    // 计算卡方统计值
    double chiSquare = 0.0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            double expected = (observed[i][0] + observed[i][1]) * (observed[0][j] + observed[1][j]) / static_cast<double>(observed[0][0] + observed[0][1] + observed[1][0] + observed[1][1]);
            chiSquare += (observed[i][j] - expected) * (observed[i][j] - expected) / expected;
        }
    }

    // 计算p值
    int degreesOfFreedom = 1; // 自由度
    boost::math::chi_squared_distribution<double> chiSquaredDist(degreesOfFreedom);
    double pValue = 1.0 - boost::math::cdf(chiSquaredDist, chiSquare);

    // 输出卡方统计值和p值
    std::cout << "卡方统计值: " << chiSquare << std::endl;
    std::cout << "p值: " << pValue << std::endl;

    return 0;
}
