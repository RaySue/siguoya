//设计一个算法，算出 n 阶乘有多少个尾随零。 
//
// 示例 1: 
//
// 输入: 3
//输出: 0
//解释: 3! = 6, 尾数中没有零。 
//
// 示例 2: 
//
// 输入: 5
//输出: 1
//解释: 5! = 120, 尾数中有 1 个零. 
//
// 说明: 你算法的时间复杂度应为 O(log n) 。 
// Related Topics 数学 
// 👍 30 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 2020.12 29, 二刷，搞懂 80%，并自己写出了比暴力解法略好的，二暴解法

    // base 解法
    // 阶乘能够产生0，说明，组成阶乘的一定有 2 和 5
    // 偶数都是包含 2 的，也就说，2是非常富裕的，所以我们只需要判断 n的阶乘 有多少个 5 即可
    // 25 是可以提供两个因子 5 的，所以每个数字，需要判断其能够提供多少个因子 5
    // Time out
    int trailingZeroes1(int n)
    {
        int ans = 0;
        if (n < 5) return ans;
        for (int i = 5; i <= n; ++i)
        {
            int cur = i;
            if (cur % 5 == 0)
            {
                // 计算能被 5 整除的数字，包含多少个因子 5
                while (cur >= 5 && cur % 5 == 0)
                {
                    ans++;
                    cur /= 5;
                }
            }
        }
        return ans;
    }

    // 改进后，每次只处理 5 的整数幂即可，因为我们不关心其他的数字
    //
    int trailingZeroes(int n)
    {
        int res = 0;
        long divisor = 5;
        while (divisor <= n)
        {
            res += n / divisor;
            divisor *= 5;
        }
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
