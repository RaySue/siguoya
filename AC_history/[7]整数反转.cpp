//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。 
//
// 示例 1: 
//
// 输入: 123
//输出: 321
// 
//
// 示例 2: 
//
// 输入: -123
//输出: -321
// 
//
// 示例 3: 
//
// 输入: 120
//输出: 21
// 
//
// 注意: 
//
// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231, 231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。 
// Related Topics 数学 
// 👍 2415 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.24
    // 需要注意的地方是 如果数值溢出，那么就返回 0
    // 还有负数的情况，也需要考虑一下
    // 无他，但手熟尔
    int reverse(int x)
    {
        int ans = 0;
        bool sign = true;
        if (x < 0)
        {
            sign = false;
            x = abs(x);
        }
        while (x > 0)
        {
            if (ans > INT_MAX / 10 || ans * 10 > INT_MAX - x % 10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return sign ? ans : -ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
