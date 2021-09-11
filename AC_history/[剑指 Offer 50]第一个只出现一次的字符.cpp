// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
//
// 示例: 
//
// s = "abaccdeff"
//返回 "b"
//
//s = "" 
//返回 " "
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 哈希表 
// 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    //  s 只包含小写字母, 计数排序思想
    // Complexity:
    // Time: O(N)
    // Space: O(1)
    char firstUniqChar(string s)
    {
        if (s.empty()) return ' ';
        vector<int> bucket(26);
        for (char c:s)
        {
            bucket[c - 'a']++;
        }
        for (char c:s)
        {
            if (bucket[c - 'a'] == 1) return c;
        }
        return ' ';
    }
};
//leetcode submit region end(Prohibit modification and deletion)
