//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？ 
//
// 示例: 
//
// 输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3 
// Related Topics 树 动态规划 
// 👍 922 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 自底向上的动态规划，和割绳子比较像
    int numTrees1(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        // init
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        // dp[i] = dp[0] * dp[i-1] + dp[1] * dp[i - 2] + ... + dp[i - 1] * dp[0]
        for (int i = 3; i <= n; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < i; ++j)
            {
                tmp += dp[j] * dp[i - j - 1];
            }
            dp[i] = tmp;
        }
        return dp.back();
    }

    // 二刷 2021.02.01
    // 就从给定的例子 n = 3 开始分析
    // 1 作为根节点的时候 2, 3 可以分布在一变有两种排布     2 * 1
    // 2 作为根节点的时候 1, 3 只能分布在两边             1 * 1
    // 3 作为根节点的时候 1, 2  可以分布在一变有两种排布    1 * 2

    // dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0];
    // dp[i] = dp[0] * dp[n - i - 1] + ... (0 <= i < n)
    int numTrees(int n)
    {
        if (n < 3) return n;
        // 初始化为 1
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < i; ++j)
            {
                tmp += dp[j] * dp[i - j - 1];
            }
            dp[i] = tmp;
        }
        return dp.back();
    }


};
//leetcode submit region end(Prohibit modification and deletion)
