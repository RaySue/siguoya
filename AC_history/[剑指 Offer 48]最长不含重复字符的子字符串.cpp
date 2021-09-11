//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。 
//
// 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// s.length <= 40000 
// 
//
// 注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-rep
//eating-characters/ 
// Related Topics 哈希表 双指针 Sliding Window 
// 👍 124 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 滑窗法：
    // 初始 l = 0, r = 0, hash_Map 作为 window，用于缓存结果
    // 如果没有重复，那么窗口扩张，每次更新最大的无重复字符串的长度给 ans r++
    // 如果有重复，那么窗口缩减，l++
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0, ans = 0;
        unordered_map<char, int> window;
        while (r < s.size())
        {
            window[s[r]]++;
            r++;
            while (window[s[r - 1]] > 1)
            {
                if (window.count(s[l]))
                {
                    window[s[l]]--;
                }
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
