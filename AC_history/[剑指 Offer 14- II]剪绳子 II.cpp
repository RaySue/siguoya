// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
// 每段绳子的长度记为 k[0],k[1]...k[m - 1]。
// 请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
// 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
//
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 
//
// 提示： 
//
// 
// 2 <= n <= 1000 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划 
// 👍 52 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 四刷 2021.01.13
    // 自底向上的动态规划
    // 想清楚每一步要做什么，定义 dp 数组
    // 定义 dp 数组
    // dp[i] 表示 第 i 个数可拆分的乘积最大值
    // 动态转移方程：
    // dp[i] = max (dp[1] * dp[i - 1], dp[2] * dp[i - 2], ... dp[i / 2] * dp[i - i / 2])
    // dp 状态初始化
    // dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4
    // dp[5] = max(dp[1] * dp[4], dp[2] * dp[3])
    // 遇到大数问题，利用 python3 解决吧
    int cuttingRope(int n)
    {
        if (n < 3) return 1;
        if (n == 3) return 2;
        vector<long long int> dp(n + 1, 1);
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i)
        {
            int half = i / 2;
            for (int j = 1; j <= half; ++j)
            {
                dp[i] = max(dp[i], (dp[j] * dp[i - j]) % e);
            }
        }
        return dp[n] % e;
    }

private:
    long long int  e = 1000000007;
//    1e9 + 7 中的任意两个数相加不冒出int，任意两个数相乘不冒出 LongLong
};
//leetcode submit region end(Prohibit modification and deletion)
