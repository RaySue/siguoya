//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的
//房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 动态规划 
// 👍 449 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 思路：
    // dp[i] 第 i 个房子的最大收益
    // 一个房子的时候 dp[0] = nums[0]；
    // 两个房子的时候 dp[1] = max(dp[0], nums[1]);
    // 三 0 1 2     dp[2] = max(dp[0] + nums[2], dp[1]);
    // 四 0 1 2 3   dp[3] = max(dp[1] + nums[3], dp[2]);
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    // 0 1 2 3 4
    int rob(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        int res1 = c;
        a = 0, b = 0, c = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return max(res1, c);
    }







    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int a1 = 0, b1 = 0, c1 = 0;
        int a2 = 0, b2 = 0, c2 = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            c1 = max(a1 + nums[i], b1);
            a1 = b1;
            b1 = c1;

            c2 = max(a2 + nums[i + 1], b2);
            a2 = b2;
            b2 = c2;
        }
        return max(c1, c2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
