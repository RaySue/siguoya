//实现 pow(x, n) ，即计算 x 的 n 次幂函数。 
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
// 说明: 
//
// 
// -100.0 < x < 100.0 
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 
// 
// Related Topics 数学 二分查找 
// 👍 549 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    /**
     *
    本题与前两天做过的一道题69.x的平方根.问题类似，只是将平方根换为n次方.同样的，我们可以利用指数函exp和对数函数ln来巧妙转换。
    我们将x^n用自然对数e换底，即可得到：
      x^n = e^{nlnx}
      需要注意的是x取负值的时候，需要进行判断。
      1.当x < 0 && n % 2 == 0时，只需将对数函数中的x取绝对值。
      2.当x < 0 && n % 2 == 1时，需将对数函数中的x取绝对值，同时整体取负值。
      实现代码如下：
     */

    // 二刷，2020.12.24， 底数代换
    // 遇到幂函数，首先想到底数代换
    double myPow(double x, int n)
    {
        if (x == 0) return 0;
        if (x > 0 || (x < 0 && (n & 1) == 0)) return exp(n * log(abs(x)));
        else return -exp(n * log(abs(x)));
    }

    // 三刷，2020.12.24 快速幂
    // 注意 N 的符号，注意递归的终止条件
    double myPow2(double x, int n)
    {
        if (n == 0 || x == 1) return 1;
        if (n == 1 || x == 0) return x;
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

};
//leetcode submit region end(Prohibit modification and deletion)
