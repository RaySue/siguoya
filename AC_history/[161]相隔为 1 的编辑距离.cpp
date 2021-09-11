//给定两个字符串 s 和 t，判断他们的编辑距离是否为 1。 
//
// 注意： 
//
// 满足编辑距离等于 1 有三种可能的情形： 
//
// 
// 往 s 中插入一个字符得到 t 
// 从 s 中删除一个字符得到 t 
// 在 s 中替换一个字符得到 t 
// 
//
// 示例 1： 
//
// 输入: s = "ab", t = "acb"
//输出: true
//解释: 可以将 'c' 插入字符串 s 来得到 t。
// 
//
// 示例 2: 
//
// 输入: s = "cab", t = "ad"
//输出: false
//解释: 无法通过 1 步操作使 s 变为 t。 
//
// 示例 3: 
//
// 输入: s = "1203", t = "1213"
//输出: true
//解释: 可以将字符串 s 中的 '0' 替换为 '1' 来得到 t。 
// Related Topics 字符串 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        int sz1 = s.size() + 1;
        int sz2 = t.size() + 1;

        vector<vector<int>> dp(sz1, vector<int>(sz2, 0));

        // init
        for (int i = 0; i < sz1; ++i) dp[i][0] = i;
        for (int i = 0; i < sz2; ++i) dp[0][i] = i;

        // dp
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp.back().back() == 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
