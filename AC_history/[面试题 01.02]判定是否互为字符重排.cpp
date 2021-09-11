//给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。 
//
// 示例 1： 
//
// 输入: s1 = "abc", s2 = "bca"
//输出: true 
// 
//
// 示例 2： 
//
// 输入: s1 = "abc", s2 = "bad"
//输出: false
// 
//
// 说明： 
//
// 
// 0 <= len(s1) <= 100 
// 0 <= len(s2) <= 100 
// 
// Related Topics 数组 字符串 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (auto a1:s1) mp1[a1] ++;
        for (auto a2:s2) mp2[a2] ++;
        for (auto a1:s1)
        {
            if (mp1[a1] != mp2[a1]) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
