// 统计所有 **小于** 非负整数 n 的质数的数量。
// 自然数由 0 开始，自然数是指用以计量事物的件数或表示事物次序的数。
// 质数是指在大于 1 的自然数中，除了 1 和 它本身 以外不再有其他因数的自然数。
//
// 示例: 
//
// 输入: 10
//输出: 4
//解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
// Related Topics 哈希表 数学 
// 👍 429 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 暴力解法
    // 思路： 如果一个数 n 有因数，那么这个因数一定是由 <= sqrt(n) 和 >= sqrt(n) 两部分相乘组成，即一定有因数小于 sqrt(n)
    // 所以我们只需要遍历到 sqrt(n) 来判断一个数是否有因数


    // 思路二
    // 筛法：
    // 1. 质数的平方肯定不是质数
    // 2. 任何数的2倍及以上肯定不是质数，
    // 题目要求求解 小于 给定 n 的质数的个数
    // 注意题意，要求是小于 n 的所有数，即不包括 n

    // 埃氏筛法
    /**
     *
    埃氏筛的原理：
    从 2 开始，将每个质数的倍数都标记为合数。
    同样的，标记到 sqrt(n)  停止。

    假设一个数 i 为质数时，那么此时大于 i 且是 i 的倍数的数一定不是质数，
    例如 2i，3i...。那么我们将这些不是质数的数进行标记。

    这里需要注意，标记应该从 i * i 开始，而不是 2 * i 开始。因为对于每个数 i 来说，枚举是从小到大的，此时前面数字的倍数都已经进行了标记。对于 i 而言，2 * i 也肯定会被在枚举数字 2 时进行标记，[2, i) 区间的数同理。
     */
    int countPrimes1(int n)
    {
        int count = 0;
        if (n < 3) return count;

        vector<bool> isPrim(n, true);
        // 从 2 开始遍历到 sqrt(n)
        for (int i = 2; i * i < n; ++i)
        {
            if (isPrim[i])  // 如果第 i 个数字是素数，就把从 i * i 开始 把小于 n 的 所有 i 的倍数都设置为 false
            {
                for (int j = i * i; j < n; j += i)  // 4、6、8 | 9 12 15
                {
                    isPrim[j] = false;
                }
            }
        }
        for (int i = 2; i < n; ++i)
            count += isPrim[i];
        return count;
    }

    // 二刷 2021.01.04
    // 质数是指大于 1 的自然数中，因子只有 1 和其 自身的数 素数
    // 把大于等于2素数的倍数都标记为合数
    int countPrimes(int n)
    {
        int count = 0;
        if (n < 3) return count;
        vector<bool> isPrime(n, true);
        for(int i = 2; i * i < n; ++i)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; ++i)
        {
            if (isPrime[i]) count ++;
        }
        return count;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
