//给定一个Excel表格中的列名称，返回其相应的列序号。 
//
// 例如， 
//
//     A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 
//    ...
// 
//
// 示例 1: 
//
// 输入: "A"
//输出: 1
// 
//
// 示例 2: 
//
// 输入: "AB"
//输出: 28
// 
//
// 示例 3: 
//
// 输入: "ZY"
//输出: 701 
//
// 致谢： 
//特别感谢 @ts 添加此问题并创建所有测试用例。 
// Related Topics 数学 
// 👍 171 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int titleToNumber(string s)
    {
        int ans = 0;
        if (s.empty()) return ans;
        for (int i = 0; i < s.size(); ++i)
        {
            ans = ans * 26 + (s[i] - 'A' + 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
