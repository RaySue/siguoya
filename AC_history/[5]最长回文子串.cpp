//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划 
// 👍 2913 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 返回的是最大距离的 idx - 字符串的左右位置
    //
    void isPalindrome(string &s, int l, int r, vector<int> &idx)
    {
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
            if (r - l - 2 > idx[1] - idx[0]) idx = {l + 1, r - 1};
        }
        if (r - l - 2 > idx[1] - idx[0]) idx = {l + 1, r - 1};
    }

    // 思路：
    // 最长回文子串或者是奇数串，或者是偶数串
    // 从一个位置向两端找，从一对位置向两端找，取最长的回文串
    string longestPalindrome(string s)
    {
        if (s.empty()) return "";
        vector<int> idx = {0, 0};
        for (int i = 0; i < s.size(); ++i)
        {
            isPalindrome(s, i, i, idx);
            isPalindrome(s, i, i + 1, idx);
        }
        return s.substr(idx[0], idx[1] - idx[0] + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
