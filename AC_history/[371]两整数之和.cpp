//不使用运算符 + 和 - ，计算两整数 a 、b 之和。 
//
// 示例 1: 
//
// 输入: a = 1, b = 2
//输出: 3
// 
//
// 示例 2: 
//
// 输入: a = -2, b = 3
//输出: 1 
// Related Topics 位运算 
// 👍 304 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // a & b 是进位后的非进位结果
    // a ^= b 是不进位的结果
    //
    int getSum(int a, int b)
    {
        while (b)
        {
            // 计算进位的结果
            auto carry = ((unsigned int) (a & b)) << 1;
            // 计算不进位的结果
            a ^= b;
            // 记录进位的结果
            b = carry;
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
