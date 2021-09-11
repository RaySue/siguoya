//设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。 
//
// 示例: 
//
// 输入: a = 1, b = 1
//输出: 2 
//
//
//
// 提示： 
//
// 
// a, b 均可能是负数或 0 
// 结果不会溢出 32 位整数 
// 
// Related Topics 位运算 
// 👍 17 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 五刷 2020.12.29
    // 0 1
    // 1 1
    // & : 0 1  所以进位的结果为 a & b << 1     1 0
    // ^ : 1 0  所以不进位的结果为 a ^= b       1 0
    //
    int add(int a, int b)
    {
        while (b != 0) // 考虑为负数的情况
        {
            // 负数没法 位移运算
            auto carry = (unsigned int) (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
