//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。 
//
// 示例 1: 
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
// 
//
// 示例 2: 
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
// 
// Related Topics 字符串 动态规划 
// 👍 1083 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 暴力方法
    bool isValidParentheses(string &s, int start, int end)
    {
        int checker = 0;
        for (int i = start; i <= end; ++i)
        {
            if (s[i] == '(')
            {
                checker++;
            } else
            {
                if (checker <= 0) return false;
                checker--;
            }
        }
        return checker == 0;
    }

    int longestValidParentheses1(string s)
    {
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                if (j - i + 1 <= maxLen) continue;
                if (isValidParentheses(s, i, j))
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

    // -------------------------------------------------------------
    // -------------------------------------------------------------
    // -------------------------------------------------------------
    // 利用栈优化 ()()()
    // 二刷 2020.12.26
    int longestValidParentheses(string s)
    {
        int maxLen = 0;
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                sta.push(i);
            } else
            {
                sta.pop();
                if (sta.empty())
                {
                    sta.push(i);  // 需要初始化，一定是 )
                } else
                {
                    maxLen = max(maxLen, i - sta.top());
                }
            }
        }
        return maxLen;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
