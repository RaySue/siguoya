//实现一个算法，确定一个字符串 s 的所有字符是否全都不同。 
//
// 示例 1： 
//
// 输入: s = "leetcode"
//输出: false 
// 
//
// 示例 2： 
//
// 输入: s = "abc"
//输出: true
// 
//
// 限制： 
// 
// 0 <= len(s) <= 100 
// 如果你不使用额外的数据结构，会很加分。 
// 
// Related Topics 数组 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 暴力方法，不讲武德
//    bool isUnique1(string astr)
//    {
//        for (int i = 0; i < astr.size(); ++i)
//        {
//            for (int j = i + 1; j < astr.size(); ++j)
//            {
//                if (astr[i] == astr[j]) return false;
//            }
//        }
//        return true;
//    }

    // 利用位运算，解决字符串是否唯一的问题
    // 思路：
    // 我们把 0 ~ 26 这26个字母映射到 bit 上
    // 利用marker 的异或运算或者 或运算积累结果，
    bool isUnique(string astr)
    {
        int marker = 0;
        for (int i = 0; i < astr.size(); ++i)
        {
            int bit = 1 << static_cast<int>(astr[i] - 'a');
            if ((marker & bit) != 0) return false;
            marker ^= bit;
        }
        return true;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
