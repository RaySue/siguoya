//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的
//
// 每隔 2k 个字符的前 k 个字符进行反转。
// 如果剩余字符少于 k 个，则将剩余字符全部反转。 
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。 
// 
//
// 
//
// 示例: 
//
// 输入: s = "abcdefg", k = 2
//输出: "bacdfeg"
// 
//
// 
//
// 提示： 
//
// 
// 该字符串只包含小写英文字母。 
// 给定字符串的长度和 k 在 [1, 10000] 范围内。 
// 
// Related Topics 字符串 
// 👍 101 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 思路：
    // 按照题目要求进行即可
    // 1. 从头开始 p=0, 对前k个字符进行翻转，翻转函数 rev
    // 2. 如果剩余字符少于 k 个，则将剩余字符全部反转, break
    // 3. 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样, break

    // Complexity:
    // Time: O(N)
    // Space: O(1)
    void rev(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start++], s[end--]);
        }
    }

    string reverseStr(string s, int k)
    {
        int p = 0;
        while (p < s.size())
        {
            if (s.size() - p < 2 * k && s.size() - p >= k)
            {
                rev(s, p, p + k - 1);
                break;
            } else if (s.size() - p < k)
            {
                rev(s, p, s.size() - 1);
                break;
            } else
            {
                rev(s, p, p + k - 1);
                p += 2 * k;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
