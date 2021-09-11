// 字符串轮转。给定两个字符串s1和s2，
// 请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
//
// 示例1: 
//
//  输入：s1 = "waterbottle", s2 = "erbottlewat" erbottlewaterbottlewat
// 输出：True
// 
//
// 示例2: 
//
//  输入：s1 = "aa", s2 = "aba"  abaaba
// 输出：False
// 
//
// 
// 
//
// 提示： 
//
// 
// 字符串长度在[0, 100000]范围内。 
// 
//
// 说明: 
//
// 
// 你能只调用一次检查子串的方法吗？ 
// 
// Related Topics 字符串 
// 👍 48 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 二刷 2020.12.19
    // aa aba
    // 唯一需要注意的是要先判断字符串的 size，可能会直接返回
    bool isFlipedString(string s1, string s2)
    {
        if (s1.size() < s2.size()) return false;
        return (s2 + s2).find(s1) != -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
