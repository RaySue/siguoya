// 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
//
// 示例1: 
//            11101     10010
//            01111     10001   10000
//
// 输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
// 输出：2
// 
//
// 示例2: 
//
// 
// 输入：A = 1，B = 2
// 输出：2
// 
//
// 提示: 
//
// 
// A，B范围在[-2147483648, 2147483647]之间 
// 
// Related Topics 位运算 
// 👍 16 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.30
    // 比汉明距离多了负数的情况
    // 461 题不转成 unsigned int 也可以通过
    // 位运算我们都要转成 unsigned int来处理负数的情况
    // 否则 int 与 unsigned int 混用的时候，会出现问题
    int convertInteger(int A, int B)
    {
        int count = 0;
        //        int C = A ^ B;  // 错误的方式
        unsigned int C = static_cast<unsigned int>(A ^ B);
        while (C != 0)
        {
            count++;
            C &= (C - 1);
        }
        return count;
    }

    int convertInteger2(int A, int B)
    {
        return bitset<32>(A ^ B).count();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
