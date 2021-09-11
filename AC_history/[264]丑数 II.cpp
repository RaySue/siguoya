//编写一个程序，找出第 n 个丑数。 
//
// 丑数就是质因数只包含 2, 3, 5 的正整数。 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
// Related Topics 堆 数学 动态规划 
// 👍 453 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 利用堆对生成的丑数进行排序，每次选择最小的添加到set中
    // 利用 set 来有序的存储丑数的个数
    // 当 set 的 size 达到 n 之后就可以返回最后一个位置的值了
    int nthUglyNumber1(int n)
    {
        set<long long> values;
        priority_queue<long long, vector<long long>, greater<long long>> smallHeap;
        smallHeap.push(1L);
        for(;;)
        {
            int cur = smallHeap.top();
            smallHeap.pop();
            if (!values.count(cur))
            {
                values.insert(cur);
                smallHeap.push(cur * 2L);
                smallHeap.push(cur * 3L);
                smallHeap.push(cur * 5L);
            }
            if (values.size() == n)
            {
                return *values.rbegin();
            }
        }
        return -1;
    }

    // 二刷 2021.01.21
    // 动态规划
    // 什么是丑数？
    // 质因数只包含 2  3  5
    // 我们可以利用一个 dp 数组来顺序存储所有的丑数
    // 我们知道第一个丑数是 1
    // 那么第二个丑数 肯定是 2 = 1 * 2
    // 我们可以利用三个指针(p2、p3、p5)指向 2 3 5 对应 dp 数组中由 2 3 5 质因数得到的数字
    // dp[i] = min(dp[p2]*2, dp[p3] * 3, dp[p5] * 5)
    int nthUglyNumber(int n)
    {
        vector<int> dp(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2) p2 ++;
            if (dp[i] == dp[p3] * 3) p3 ++;
            if (dp[i] == dp[p5] * 5) p5 ++;
        }
        return dp.back();
    }

};
//leetcode submit region end(Prohibit modification and deletion)
