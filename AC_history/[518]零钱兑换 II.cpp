//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
//
// 
//
// 
// 
//
// 示例 1: 
//
// 输入: amount = 5, coins = [1, 2, 5]
//输出: 4
//解释: 有四种方式可以凑成总金额:
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
// 
//
// 示例 2: 
//
// 输入: amount = 3, coins = [2]
//输出: 0
//解释: 只用面额2的硬币不能凑成总金额3。
// 
//
// 示例 3: 
//
// 输入: amount = 10, coins = [10] 
//输出: 1
// 
//
// 
//
// 注意: 
//
// 你可以假设： 
//
// 
// 0 <= amount (总金额) <= 5000 
// 1 <= coin (硬币面额) <= 5000 
// 硬币种类不超过 500 种 
// 结果符合 32 位符号整数 
// 
// 👍 269 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 暴力回溯算法 time out
    int ans;

    void backtrack(vector<int> &coins, int start, int amount)
    {
        if (amount == 0)
        {
            ans++;
            return;
        }
        for (int i = start; i < coins.size(); ++i)
        {
            if (amount < 0) return;
            amount -= coins[i];
            backtrack(coins, i, amount);
            amount += coins[i];
        }
    }

    int change1(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        backtrack(coins, 0, amount);
        return ans;
    }

    // 动态规划 (自底向上)
    // 状态：dp[i] 第 i 个状态表示凑成金额 i 所需要的硬币数
    // dp[i] = dp[i-c1] + dp[i-c2] + ... + dp[i-cn]
    // 明确选择 coins 比如：[1,2,5]
    // base caes: dp[0] = 1 (初始化)
    /////////////////////////// [0,1,2,3,4,5,...,10,...]
    // 假设选择只有1，那么dp[i]    [1,1,1,1,1,1,...,1,...]
    // 假设选择只有2，那么dp[i]    [1,0,1,0,1,0,...,1,...]
    // 假设选择只有5，那么dp[i]    [1,0,0,0,0,1,...,1,...]
    // 合并上面的结果             [1,1,2,2,3]
    // 如果选择有1，2，5 那么dp[5] 可以从0位置通过+5得到，可以从1位置通过加+2+2得到，可以从2位置+1+2得到，可以从4位置+1得到，即四种情况。
    int change(int amount, vector<int> &coins)
    {
        vector<int> ans(amount + 1, 0);
        ans[0] = 1;
        for (int coin:coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                ans[i] += ans[i - coin];
            }
        }
        return ans[amount];
    }

};
//leetcode submit region end(Prohibit modification and deletion)
