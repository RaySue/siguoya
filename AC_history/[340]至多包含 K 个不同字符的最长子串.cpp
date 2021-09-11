//给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。 
//
// 示例 1: 
//
// 输入: s = "eceba", k = 2
//输出: 3
//解释: 则 T 为 "ece"，所以长度为 3。 
//
// 示例 2: 
//
// 输入: s = "aa", k = 1
//输出: 2
//解释: 则 T 为 "aa"，所以长度为 2。
// 
// Related Topics 哈希表 字符串 Sliding Window 
// 👍 59 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<char, int> window;
        int l = 0, r = 0, count = 0, len = 0;
        while(r < s.size())
        {
            char a = s[r];
            r ++;
            if (!window.count(a) || window[a] == 0) count ++;
            window[a] ++;
            while(count > k)
            {
                if (r - l > len) len = r - l - 1;
                char b = s[l];
                l ++;
                window[b]--;
                if (window[b] == 0) {
                    count --;
                }
            }
        }
        if (r - l > len) len = r - l;
        return len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
