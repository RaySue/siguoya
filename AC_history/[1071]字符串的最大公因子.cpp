// 对于字符串 S 和 T，只有在 S = T + ... + T（T 自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
//
// 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。 
//
// 
//
// 示例 1： 
//
// 
//输入：str1 = "ABCABC", str2 = "ABC"
//输出："ABC"
// 
//
// 示例 2： 
//
// 
//输入：str1 = "ABABAB", str2 = "ABAB"
//输出："AB"
// 
//
// 示例 3： 
//
// 
//输入：str1 = "LEET", str2 = "CODE"
//输出：""
// 
//    "ABAABA" "ABAB"
//    "AAA" "AAA"
//
// 提示： 
//
// 
// 1 <= str1.length <= 1000 
// 1 <= str2.length <= 1000 
// str1[i] 和 str2[i] 为大写英文字母 
// 
// Related Topics 字符串 
// 👍 184 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 2021.01.05
    // 1. 如果 str1 != str2 并且，在str1 找不到 str2，在str2也找不到str1，肯定是不存在相同的因子 返回 ""
    // 2. 先找到 str1 和 str2 中较小字符串的因子
    // 3.
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 != str2 && str2.find(str1) == -1 && str1.find(str2) == -1) return "";
        if (str1.size() > str2.size())
        {

        }

        return "A";
    }
};
//leetcode submit region end(Prohibit modification and deletion)
