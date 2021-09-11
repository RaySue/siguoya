//假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。 
//
// 当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的矩阵来表示的。 
//
// 例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。请你计算出粉刷
//完所有房子最少的花费成本。 
//
// 注意： 
//
// 所有花费均为正整数。 
//
// 示例： 
//
// 输入:
// [[17,2,17],
//  [16,16,5],
//  [14,3,19]]
//


//输出: 10
//解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
//     最少花费: 2 + 5 + 3 = 10。
// 
// Related Topics 动态规划 
// 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    int ans = INT_MAX;

    void backtrack(vector <vector<int>> costs, int depth, int color, int path)
    {
        if (depth == costs.size())
        {
            if (ans > path) ans = path;

            return;
        }
        vector<int> cost = costs[depth];
        for (int i = 0; i < 3; ++i)
        {
            if (i == color) continue;
            path += cost[i];
            backtrack(costs, depth + 1, i, path);
            path -= cost[i];
        }

    }

    // 暴力， 回溯算法
    int minCost(vector <vector<int>> &costs)
    {
        if (costs.empty() || costs[0].empty()) return 0;
        backtrack(costs, 0, -1, 0);
        return ans;
    }



    // 动态规划
    // 状态 dp[i][j] 表示第 i 间房子使用第 j 中颜色的最省钱的方案
    // dp[i][j] = min(d[k][0] + data[k][0], d[k][1] + data[k][1], d[k][2] + data[k][2]), k in {0,1,2} && k != i
    int minCost2(vector <vector<int>> &costs)
    {
        if (costs.empty() || costs[0].empty()) return 0;
        if (costs.size() == 1 ) return min(min(costs[0][0], costs[0][1]), costs[0][2]);
        for (int i = 1; i < costs.size(); ++i)
        {
            costs[i][0] = min(costs[i - 1][1], costs[i - 1][2]) + costs[i][0];
            costs[i][1] = min(costs[i - 1][0], costs[i - 1][2]) + costs[i][1];
            costs[i][2] = min(costs[i - 1][0], costs[i - 1][1]) + costs[i][2];
        }
        return min(min(costs.back()[0], costs.back()[1]), costs.back()[2]);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
