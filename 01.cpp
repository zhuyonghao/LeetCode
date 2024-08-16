// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 01背包问题的函数
// int knapsack01(int W, vector<int> &weights, vector<int> &values)
// {
//     int n = weights.size();
//     // 创建一个二维的DP数组，大小为(n+1) x (W+1)
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     // 填充DP数组
//     for (int i = 1; i <= n; i++)
//     {
//         for (int w = 1; w <= W; w++)
//         {
//             if (weights[i - 1] <= w)
//             {
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//             }
//             else
//             {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }

//     // 返回背包可以容纳的最大价值
//     return dp[n][W];
// }

// int main()
// {
//     int W; // 背包的容量
//     int n; // 物品的数量

//     cout << "输入背包的容量: ";
//     cin >> W;

//     cout << "输入物品的数量: ";
//     cin >> n;

//     vector<int> weights(n); // 物品的重量
//     vector<int> values(n);  // 物品的价值

//     cout << "输入每个物品的重量和价值:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << "物品 " << i + 1 << " 的重量和价值: ";
//         cin >> weights[i] >> values[i];
//     }

//     int max_value = knapsack01(W, weights, values);

//     cout << "背包的最大价值为: " << max_value << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 01背包问题的函数（使用一维数组实现）
int knapsack01(int W, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    // 创建一个一维的DP数组，大小为(W+1)
    vector<int> dp(W + 1, 0);

    // 填充DP数组
    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= weights[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // 返回背包可以容纳的最大价值
    return dp[W];
}

int main()
{
    int W; // 背包的容量
    int n; // 物品的数量

    cout << "输入背包的容量: ";
    cin >> W;

    cout << "输入物品的数量: ";
    cin >> n;

    vector<int> weights(n); // 物品的重量
    vector<int> values(n);  // 物品的价值

    cout << "输入每个物品的重量和价值:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "物品 " << i + 1 << " 的重量和价值: ";
        cin >> weights[i] >> values[i];
    }

    int max_value = knapsack01(W, weights, values);

    cout << "背包的最大价值为: " << max_value << endl;

    return 0;
}

// 完全背包
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int completeKnapsack(int W, const vector<int> &weight, const vector<int> &value)
{
    int n = weight.size();
    vector<int> dp(W + 1, 0);

    // 遍历每种物品
    for (int i = 0; i < n; ++i)
    {
        // 倒序遍历容量，确保每种物品可以被多次选择
        for (int j = weight[i]; j <= W; ++j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[W];
}

int main()
{
    int W = 10;                      // 背包容量
    vector<int> weight = {2, 3, 5};  // 每种物品的重量
    vector<int> value = {6, 10, 20}; // 每种物品的价值

    int maxValue = completeKnapsack(W, weight, value);
    cout << "背包的最大价值是: " << maxValue << endl;

    return 0;
}
