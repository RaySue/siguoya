//给定一个整数 n，返回 n! 结果尾数中零的数量。 
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
// 👍 346 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 阶乘后的零，别想着先阶乘，再计算0，那样就太蠢了，而且阶乘是比指数运算更恐怖的运算量
    // 能够产生 0 的一定是 2 * 5
    // 由于偶数都是带有2的，所以我们只需要考虑阶乘中有几个 5 即可
    // 25 / 5 说明有 5 个 5 ： 10， 15， 20， 25（5 * 5）
    // 而 5 本身是一个 所以 5、10、15、20、25 （5 * 5） = 6 个 5 即6个0
    int trailingZeroes1(int n)
    {
        int ans = 0;
        for (int i = n; i / 5 > 0; i /= 5)
        {
            ans += i / 5;
        }
        return ans;
    }

    // -------------------------------------------

    // 三刷 2021.01.04
    // 朴素思路:
    // 计算从 1 到 n 包含多少个因子5，那么阶乘就有多少个 0
    // 从 1 开始遍历，如果这个数能被5整除，那么就是ans++，直到其不能被5整除
    int trailingZeroes2(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int tmp = i;
            while (tmp % 5 == 0)
            {
                tmp /= 5;
                ans ++;
            }
        }
        return ans;
    }

    // 从 5 开始找，每次 i + 5，这样就省掉了很多遍历的次数
    int trailingZeroes3(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i += 5)
        {
            int tmp = i;
            while (tmp % 5 == 0)
            {
                tmp /= 5;
                ans ++;
            }
        }
        return ans;
    }

    // 推演出 最优解法
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = n; i > 0; i /= 5)
        {
//            cout << i << endl;
            ans += i / 5;
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
