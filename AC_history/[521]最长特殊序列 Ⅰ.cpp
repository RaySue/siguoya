// 给你两个字符串，请你从这两个字符串中找出最长的特殊序列。
//
// 「最长特殊序列」定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。 
//
//  子序列 可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。
//  空序列为所有字符串的子序列，任何字符串为其自身的子序列。
//
//  输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。
//
// 
//
// 示例 1： 
//
// 输入: "aba", "cdc"
//输出: 3
//解释: 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。 
//
// 示例 2： 
//
// 输入：a = "aaa", b = "bbb"
//输出：3
// 
//
// 示例 3： 
//
// 输入：a = "aaa", b = "aaa"
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 两个字符串长度均处于区间 [1 - 100] 。 
// 字符串中的字符仅含有 'a'~'z' 。 
// 
// Related Topics 脑筋急转弯 字符串 
// 👍 72 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 这道题如果把题意理解清楚，真的很简单
    // 思路：
    // 如果一个序列大于另一个序列，那么这个序列必然是 "最长的特殊序列"
    // 如果两个序列不相等，那么其中任意序列就是 "最长的特殊序列"
    // 如果两个序列相等，那么返回 -1
    int findLUSlength(string a, string b)
    {
        if (a.size() != b.size())
        {
            return a.size() > b.size() ? a.size():b.size();
        } else if (a != b){
            return a.size();
        } else {
            return -1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
