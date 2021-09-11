//给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。 
//
// 示例 1: 
//
// 输入: [5,7]
//输出: 4 
//
// 示例 2: 
//
// 输入: [0,1]
//输出: 0 
// Related Topics 位运算 
// 👍 253 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0) return 0;
        long int ans = INT_MAX;
        while (m <= n)
        {
            ans &= (m & n);
            if (ans == 0) return 0;
            m--;
            n++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
