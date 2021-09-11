//实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数
//问题。 
//
// 
//
// 示例 1: 
//
// 输入: 2.00000, 10
//输出: 1024.00000
// 
//
// 示例 2: 
//
// 输入: 2.10000, 3
//输出: 9.26100
// 
//
// 示例 3: 
//
// 输入: 2.00000, -2
//输出: 0.25000
//解释: 2-2 = 1/22 = 1/4 = 0.25 
//
// 
//
// 说明: 
//
// 
// -100.0 < x < 100.0 
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 
// 
//
// 注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/ 
// Related Topics 递归 
// 👍 96 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：快速幂
    // 使用递归先考虑出栈的条件 这里是 n == 1 的时候返回 x
    // 本题还需要考虑正负号的情况
    // 1. 如果n为偶数，那么返回 myPow(x*x, n/2)
    // 2. 如果n为奇数，那么返回 x * myPow(x*x, n/2)
    double myPow1(double x, int n)
    {
        if (x == 1 || n == 0) return 1;
        if (x == 0 || n == 1) return x;
        long N = n;
        if (N < 0)
        {
            N *= -1;
            x = 1 / x;
        }
        if (N % 2 == 0)
        {
            return myPow(x * x, N / 2);
        } else
        {
            return x * myPow(x * x, N / 2);
        }
    }

    // 注意： 对数函数的定义域 （0 -> inf)
    double myPow(double x, int n)
    {
        if (x == 0) return 0;
        if (x > 0 || x < 0 && (n & 1) == 0) return exp(n * log(abs(x)));
        else return -exp(n * log(abs(x)));
    }


};
//leetcode submit region end(Prohibit modification and deletion)
