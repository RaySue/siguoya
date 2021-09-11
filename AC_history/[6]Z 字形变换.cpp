//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。 
//
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下： 
//
// L   C   I   R
//E T O E S I I G
//E   D   H   N
// 
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。 
//
// 请你实现这个将字符串进行指定行数变换的函数： 
//
// string convert(string s, int numRows); 
//
// 示例 1: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 3
//输出: "LCIRETOESIIGEDHN"
// 
//
// 示例 2: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 4
//输出: "LDREOEIIECIHNTSG"
//解释:
//
//L     D     R
//E   O E   I I
//E C   I H   N
//T     S     G 
// Related Topics 字符串 
// 👍 852 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 三刷 2021.01.14
    // 思路：
    // 1. 先判断特殊的情况，s为空的时候直接返回空，s.size() <= numRows 的时候，numRows == 1 的时候 直接返回 s
    // 2. 定义一个 vector<string> zigzag(numRows), 按列存 s
    // 3. 定义一个 direction 和 行指针 rowIdx 用于遍历 s， 当 rowIdx == 0 或 rowIdx == numRows - 1 的时候改变方向，继续zigzag添加
    // 4. 将 zigzag 的每一行汇总到 ret 中
    string convert(string s, int numRows)
    {
        string ret = "";
        if (s.empty()) return ret;
        if (s.size() <= numRows || numRows == 1) return s;
        vector<string> zigZag(numRows, "");
        bool direction = true;
        int rowIdx = 0;
        for (auto c:s)
        {
            zigZag[rowIdx].push_back(c);
            rowIdx += direction? 1:-1;
            if (rowIdx == 0 || rowIdx == numRows - 1) direction = !direction;
        }
        for(string a:zigZag) ret += a;
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
