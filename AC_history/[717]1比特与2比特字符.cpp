// 有两种特殊字符。
// 第一种字符可以用一比特0来表示。
// 第二种字符可以用两比特(10 或 11)来表示。
//
// 现给一个由若干比特组成的字符串。
// 问最后一个字符是否必定为一个 一比特字符。给定的字符串总是由0结束。
//
// 示例 1: 
//
// 
//输入: 
//bits = [1, 0, 0]
//输出: True
//解释: 
//唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
// 
//
// 示例 2: 
//
// 
//输入: 
//bits = [1, 1, 1, 0]
//输出: False
//解释: 
//唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
// 
//
// 注意: 
//
// 
// 1 <= len(bits) <= 1000. 
// bits[i] 总是0 或 1. 
// 
// Related Topics 数组 
// 👍 156 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 仔细读题 发现 1 不能单独出现，10 或 11，01不可以
    // 所以从头开始向后判断，如果1出现，后面必须是0或1，看下最后是否还有 1 没有被消化掉，如果有false，否则true
    bool isOneBitCharacter1(vector<int> &bits)
    {
        int oneFirst = false;
        for (int i = 0; i < bits.size(); ++i)
        {
            if (oneFirst && bits[i] == 0)
            {
                oneFirst = false;
            } else if (oneFirst && bits[i] == 1)
            {
                oneFirst = false;
            } else if (bits[i] == 1){
                oneFirst = true;
            } else if (i == bits.size() - 1)
            {
                return !oneFirst;
            }
        }
        return false;
    }

    // 简化版，我如果遇到 1，那么就+2 否则就 + 1， 看下到达最后一个位置的前一刻需要是 +2 还是 +1 即可
    bool isOneBitCharacter(vector<int> &bits)
    {
        int p = 0;
        while (p < bits.size() - 1)
        {
            if (bits[p] == 1) p+=2;
            else p++;
        }
        return p != bits.size();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
