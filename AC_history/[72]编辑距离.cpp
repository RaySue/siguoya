//
// 给你两个单词 word1 和 word2，**请你计算出将 word1 转换成 word2 所使用的最少操作数** 。
//
//
// 你可以对一个单词进行如下三种操作： 
//
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 1296 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 编辑距离
    // 1. 增加 2. 删除 3. 替换
    // dp table
    int minDistance(string word1, string word2)
    {
        int s1 = word1.size() + 1;
        int s2 = word2.size() + 1;
        vector <vector<int>> dp(s1, vector<int>(s2));

        // init
        for (int i = 0; i < s1; ++i) dp[i][0] = i;
        for (int i = 0; i < s2; ++i) dp[0][i] = i;

        // dp
        for (int i = 1; i < s1; ++i)
        {
            for (int j = 1; j < s2; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) +1;
                }
            }
        }
        return dp.back().back();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
