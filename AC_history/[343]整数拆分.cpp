//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划 
// 👍 408 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 刷题我的建议是
    // 1. 每道题至少读三遍，让自己完全理解后，思考5~10分钟，建议用笔画一画
    // 2. 一定要看题解，不管你做的怎么样，如果超过50行代码，你的写法一定是冗余的
    // 3.刷过的题你要重新做好多遍，你会发现，你每次写的代码都不一样，而且越来越简单、清晰、明了

    // 首先要明确一个问题的暴力解法，比如这道题，求 n 的整数拆分，
    // 那就必须遍历计算 (i * n - i) 中的所有的结果，然后求取最大值
    // 自顶向下的思路是比较好理解的
    // 比如 n = 10，我们所以的选择是 {(9,1), (8,2), ... , (5,5)}
    // 那么 max（maxProduct（9） * maxProduct（1）,..., maxProduct（5）* maxProduct（5））就是其最大拆分结果
    // 所以递归的公式就有了 n = max{maxProduct（n - i） * i}
    // 为了去除重复的运算，我们就需要利用记忆化递归即 unordered_map
    // -----------------------------------------------------------------------
    //                            自顶向下 自研
    // -----------------------------------------------------------------------
    int integerBreak(int n, unordered_map<int, int> &mp)
    {
        if (mp.count(n)) return mp[n];
        int left, right, half = n / 2, maxVal = 0;
        for (int i = 2; i <= half; ++i)
        {
            left = integerBreak(i, mp);
            right = integerBreak(n - i, mp);
            if (left * right > maxVal) maxVal = left * right;
        }
        mp[n] = maxVal;
        return maxVal;
    }
    int integerBreak(int n)
    {
        if (n <= 1) return 0;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        unordered_map<int, int> mem;
        for (int i = 1; i < 5; ++i) mem[i] = i;
        return integerBreak(n, mem);
    }


    // 根据上面介绍的思路，我们
    // -----------------------------------------------------------------------
    //                            自底向上 自研
    // -----------------------------------------------------------------------
    int integerBreak2(int n)
    {
        if (n <= 1) return 0;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < 5; ++i) dp[i] = i;
        for (int i = 5; i <= n; ++i)
        {
            int half = i / 2;
            for (int j = i - 1; j >= half; --j)
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp.back();
    }


};
//leetcode submit region end(Prohibit modification and deletion)
