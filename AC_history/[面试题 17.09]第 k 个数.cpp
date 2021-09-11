//有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，
//5，7，9，15，21。 
//
// 示例 1: 
//
// 输入: k = 5
//
//输出: 9
// 
// Related Topics 堆 队列 数学 
// 👍 41 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 一刷 2021.01.19
    // 怎么感觉是丑数题呢
    // 使用动态规划
    // dp[i] = min(dp[three], dp[five], dp[seven])
    int getKthMagicNumber(int k)
    {
        vector<int> dp(k);
        dp[0] = 1;
        int three = 0, five = 0, seven = 0;
        for (int i = 1; i < k ; ++i)
        {
            dp[i] = min(min(dp[three] * 3, dp[five] * 5), dp[seven] * 7);
            // 这里可能会存在相等的情况，如果相等(3 * 5, 5 * 3)，那么就都向后走就可以
            if (dp[three] * 3 == dp[i]) three++;
            if (dp[five] * 5 == dp[i]) five++;
            if (dp[seven] * 7 == dp[i]) seven++;
        }
        return dp.back();
    }

    // 方法二，使用堆来完成
    // 利用 tree set 来维护顺序
    // 利用 小顶堆 堆来每次添加三个数，取最小的再 挨个乘 因子


};
//leetcode submit region end(Prohibit modification and deletion)
