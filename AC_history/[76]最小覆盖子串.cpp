// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 872 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 利用 hash map 来判断，利用 valid 来记录字符相等的个数
    // 注意更新字符串的起始位置，用于最终的返回
    string minWindow(string s, string t)
    {
        if (s.size() < t.size()) return "";
        int l = 0, r = 0, valid = 0;
        unordered_map<char, int> mem;
        unordered_map<char, int> target;
        for (char c:t) target[c]++;
        vector<int> interval = {0, INT_MAX};
        while(r < s.size())
        {
            char a = s[r];
            r ++;
            mem[a]++;
            if (target.count(a))
            {
                if (mem[a] == target[a]) valid++;
            }
            while(valid == target.size())
            {
                if (r - l < interval[1] - interval[0])
                {
                    interval = {l, r};
                }
                char b = s[l];
                if (target.count(b))
                {
                    if (mem[b] == target[b]) valid --;
                    mem[b]--;
                }
                l++;
            }
        }
        if (interval[1] == INT_MAX) return "";
        return s.substr(interval[0], interval[1] - interval[0]);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
