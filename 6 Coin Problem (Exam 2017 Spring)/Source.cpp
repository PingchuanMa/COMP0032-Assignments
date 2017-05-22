#include <iostream>
#include <vector>
#define INF 9999999 // 设置一个无法达到的大值代表当前的硬币种类和个数无法凑出要求的金额
using namespace std;

int main() {

    // 初始化参数
    int valueNum = 0; // 面额数量
    int finalMoney = 0; // 目标金额
    cin >> valueNum; // 输入面额数量
    vector<int> values(valueNum); // 记录各类硬币的面额
    vector<int> numbers(valueNum); // 记录各面额硬币的数量
    for (int i = 0; i < valueNum; ++i) {
        cin >> values[i] >> numbers[i]; // 输入各类硬币的面额和数量
    }
    cin >> finalMoney; // 输入目标金额

                       // 设计动态规划矩阵[包含前i种面额, 恰好达到总额j] := 满足条件的最少硬币数
    vector<vector<int> > dp(valueNum + 1, vector<int>(finalMoney + 1, 0)); // 构造二维动态规划数组并
    for (int i = 1; i <= finalMoney; ++i) {
        dp[0][i] = INF; // 初始化为[0, INF, INF, ...]
    }

    //            { dp[i - 1, j] when 面额i无法满足要求 (1)
    // dp[i, j] = {
    //            { min(dp[i - 1, j - k * i的面额] + k) when 1 <= k <= i面额硬币的数量 and k * i的面额 > j (2)

    for (int i = 1; i <= valueNum; ++i) {
        for (int j = 1; j <= finalMoney; ++j) {
            int min = INF; // 合并(1)(2)情况 将无法满足要求看作 k = 0 求最小值
            for (int k = 0; k <= numbers[i - 1]; ++k) {
                if (j - k * values[i - 1] < 0) break; // 当k个新添加面额硬币的总金额大于设定总额j则跳出
                if (min > dp[i - 1][j - k * values[i - 1]] + k) {
                    min = dp[i - 1][j - k * values[i - 1]] + k;
                }
            }
            dp[i][j] = min; // 为其赋新值
        }
    }
    cout << ((dp[valueNum][finalMoney] == INF) ? -1 : dp[valueNum][finalMoney]) << endl; // 如果最终恰好达到finalMoney的硬币数量为INF则说明无法配对
    return 0;
}