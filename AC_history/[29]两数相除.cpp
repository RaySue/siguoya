// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
// 返回被除数 dividend 除以除数 divisor 得到的商。 
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2 
//
// 
//
// 示例 1: 
//
// 输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3 
//
// 示例 2: 
//
// 输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2 
//
// 
//
// 提示： 
//
// 
// 被除数和除数均为 32 位有符号整数。 
// 除数不为 0。 
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 
// 
// Related Topics 数学 二分查找 
// 👍 470 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 两数相除
    int divide(int dividend, int divisor)
    {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        if (sign > 0)return res > INT_MAX ? INT_MAX : res;
        return -res;
    }

    int div(long a, long b)
    {  // 似乎精髓和难点就在于下面这几句
        if (a < b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while ((tb + tb) <= a)
        {
            count = count + count; // 最小解翻倍
            tb = tb + tb; // 当前测试的值也翻倍
        }
        return count + div(a - tb, b);
    }


    // --------------------------------------------------------------
    // --------------------------------------------------------------
    // --------------------------------------------------------------

    void divide(long int &dividend, long int &divisor, long int &times)
    {
        if (dividend > divisor + divisor) return;
        times += times;
        divisor += divisor;
        divide(dividend, divisor, times);
    }

    // // 注意 INT_MIN 的溢出的情况
    // // 边界情况 1 abs(divisions) < (divisor) 的情况
    int divide(int dividend, int divisor)
    {
        int ans = 0;
        if (divisor == 1) return dividend;
        // 负数情况处理
        bool flag1 = false;
        if (dividend > 0)
        {
            dividend = -dividend;
            flag1 = true;
        }
        bool flag2 = false;
        if (divisor > 0)
        {
            divisor = -divisor;
            flag2 = true;
        }
        if (dividend > divisor) return ans;
        long int times = 1;
        long int dividend_ptr = dividend;
        long int divisor_ptr = divisor;

        while (dividend_ptr <= divisor)
        {
            // 对 divisor 的累加要和 dividend 减去 分开
            divide(dividend_ptr, divisor_ptr, times);
            dividend_ptr -= divisor_ptr;
            ans += times;
            times = 1;
            divisor_ptr = divisor;
        }
        if (ans == INT_MIN) return INT_MAX;
        return flag1 ^ flag2 ? -ans : ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
