//我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
// Related Topics 数学 
// 👍 85 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 暴力法 time out
    bool isUglyNumber(int n)
    {
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }

    int nthUglyNumber1(int n)
    {
        int count = 0;
        int start = 0;
        while (count < n)
        {
            start++;
            if (isUglyNumber(start))
                count++;
        }
        return start;
    }

    // 动态规划，只考虑丑数的情况
    // 1 是丑数，那么我们就令 dp[0] = 1，求第 n 个丑数，从位置 0 开始就是 n-1 位置对应的丑数，
    //
    // 初始 two， three， five 为 0，都指向 1
    // 我们需要保证丑数的从小到大的顺序, 每次都选择最小的数字位于第 i 个
    // dp[i] = min(dp[two] * 2, dp[three] * 3, dp[five] * 5)
    // 每次判断：
    // (dp[i] == dp[two] * 2) two++;
    // (dp[i] == dp[three] * 3) three++;
    // (dp[i] == dp[five] * 5) five++;
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        int two = 0, three = 0, five = 0;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = min(min(dp[two] * 2, dp[three] * 3), dp[five] * 5);
            if (dp[i] == dp[two] * 2) two++;
            if (dp[i] == dp[three] * 3) three++;
            if (dp[i] == dp[five] * 5) five++;
        }
        return dp.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
