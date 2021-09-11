// 硬币。给定数量不限的硬币，币值为25分、10分、5分 和 1分，编写代码计算n分有几种表示法。
// (结果可能会很大，你需要将结果模上1000000007)
//
// 示例1: 
//
// 
// 输入: n = 5
// 输出：2
// 解释: 有两种方式可以凑成总金额:
//  5=5
//  5=1+1+1+1+1
// 
//
// 示例2: 
//
// 
// 输入: n = 10
// 输出：4
// 解释: 有四种方式可以凑成总金额:
//  10=10
//  10=5+5
//  10=5+1+1+1+1+1
//  10=1+1+1+1+1+1+1+1+1+1
// 
//
// 说明： 
//
// 注意: 
//
// 你可以假设： 
//
// 
// 0 <= n (总金额) <= 1000000 
// 
// Related Topics 动态规划 
// 👍 180 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 从 1 开始凑零钱 一直凑到 n， 计算总共有多少种凑法，和青蛙上台阶的问题是一样的
    //
    int waysToChange(int n)
    {
        int mod = 1000000007;
        vector<int> coins = {1, 5, 10, 25};
        vector<int> dp(n + 1);
        dp[0] = 1;

//        for (int c = 0; c < 4; ++c)
//        {
//            int coin = coins[c];
//            for (int i = coin; i <= n; ++i)
//            {
//                dp[i] = (dp[i] + dp[i - coin]) % mod;
//            }
//        }

        for (int i = 1; i <= n; ++i)
        {
            for (int coin: coins)
            {
                if (i - coin < 0) continue;
                dp[i] = (dp[i] + dp[i - coin]) % mod;
            }
        }

        return dp.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
