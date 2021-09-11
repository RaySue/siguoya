//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 输入："abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 输入："aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 输入的字符串长度不会超过 1000 。 
// 
// Related Topics 字符串 动态规划 
// 👍 458 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 回文子串的个数
    int palindromicCount(string s, int left, int right)
    {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            count += palindromicCount(s, i, i);
            count += palindromicCount(s, i, i + 1);
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
