// 字符串有三种编辑操作:
// 插入一个字符
// 删除一个字符
// 替换一个字符
//
// 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
//
// 
//
// 示例 1: 
//
// 输入: 
//first = "pale"
//second = "ple"
//输出: True 
//
// 
//
// 示例 2: 
//
// 输入: 
//first = "pales"
//second = "pal"
//输出: False
// 
// Related Topics 字符串 动态规划 
// 👍 45 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 计算最小编辑次数
    bool oneEditAway(string first, string second)
    {
        if (first == second) return true;
        int n1 = first.size() + 1, n2 = second.size() + 1;
        if (abs(n1 - n2) > 1) return false;

        vector<vector<int> > dp(n1, vector<int>(n2, 0));
        // 增加
        for (int i = 1; i < n1; ++i) dp[i][0] = i;
        // 删除
        for (int i = 1; i < n2; ++i) dp[0][i] = i;

        for (int i = 1; i < n1; ++i)
        {
            for (int j = 1; j < n2; ++j)
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                if (first[i - 1] == second[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
//        cout << dp.back().back() << endl;
        return dp.back().back() <= 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
