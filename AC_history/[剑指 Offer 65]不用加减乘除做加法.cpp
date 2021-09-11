//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。 
//
// 
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
// 👍 90 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷
    // 需要注意的地方：
    // 1. & 运算的优先级 弱于 << 位移运算
    // 2. C++ 不支持负值左移，需要转为 unsigned int
    int add(int a, int b)
    {
//        b = -10;
//        cout << static_cast<unsigned int>(b) << endl;
        while (b != 0) //运算到没进位为止
        {
            int carry = (unsigned int)(a & b) << 1;  // C++不支持负值左移！！这里要加上unsigned int
            a ^= b;   // 用异或运算求无进位和
            b = carry;
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
