//给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。 
//
// 说明：不要使用任何内置的库函数，如 sqrt。 
//
// 示例 1： 
//
// 输入：16
//输出：True 
//
// 示例 2： 
//
// 输入：14
//输出：False
// 
// Related Topics 数学 二分查找 
// 👍 168 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // Binary Search 注意大数问题
    bool isPerfectSquare(int num)
    {
        if (num < 1) return 0;
        int left = 0, right = num;
        // int * int 只能得到 int，会导致数值溢出
        long long int mid;

        while (left <= right)
        {
            mid = left + (right - left >> 1);
            long long int m2 = mid * mid;
            if (m2 > num)
            {
                right = mid - 1;
            } else if (m2 < num)
            {
                left = mid + 1;
            } else
            {
                return true;
            }
        }
        return false;
    }

    // 完全平方指用一个整数乘以自己例如1*1，2*2，3*3等，依此类推。
    // 若一个数能表示成某个整数的平方的形式，则称这个数为完全平方数。
    // x^2 = x * x 其中 x 是整数 就是完全平方数
    // 这个问题可以转化为 y = x^2 - C 是否有整数根的问题，求根问题想到牛顿法
    // 在 x0 点出进行泰勒展开
    // f(x) = f(x0) + f'(x0)(x - x0) + O(xn);
    // f(x) = 0
    // 0 = f(x0) + f'(x0)(x - x0)
    // x0^2 - C + 2x0(x - x0) = 0
    // -x0^2 - C + 2x0x = 0
    // x = 0.5(x0 + C / x0)
    bool isPerfectSquare2(int num)
    {
        double E = 1e-9;
        double x0 = num;
        double C = num;
        double x1;
        for (;;)
        {
            x1 = 0.5 * (x0 + C / x0);
            if (abs(x1 - x0) < E) break;
            x0 = x1;
        }
        return floor(x1) == x1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
