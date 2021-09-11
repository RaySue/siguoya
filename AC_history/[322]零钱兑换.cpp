// 给定不同面额的硬币 coins 和一个总金额 amount。
// 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：coins = [1], amount = 1
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：coins = [1], amount = 2
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics 动态规划 
// 👍 915 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // Failed 方法一 贪心算法：
    // 每次都除以coins中最大的数，然后记录需要硬币的个数
    // [2,5] 11 此方法无法通过
    int coinChange_tx(vector<int>& coins, int amount)
    {
        int count = 0;
        sort(coins.begin(), coins.end(), [](int x1, int x2){return x1 > x2;});
        int p = 0;
        while(p < coins.size())
        {
            if (amount >= coins[p])
            {
                count += amount / coins[p];
                amount %= coins[p];
            }
            p++;
        }
        return amount == 0? count : -1;
    }

    // 方法二 自顶向下
//    int coinChange(vector<int>& coins, int amount)
//    {
//
//    }

    // 给定不同面额的硬币 coins 和一个总金额 amount，最小硬币的个数
    // 方法三 自底向上
    // 设 dp[i] 表示第 i 个总值的钱币最少需要多少个硬币来兑换
    // dp[i] = min(dp[i], 1 + dp[i - coin])
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for(int coin:coins)
            {
                if (coin <= i)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp.back();
    }


};
//leetcode submit region end(Prohibit modification and deletion)
