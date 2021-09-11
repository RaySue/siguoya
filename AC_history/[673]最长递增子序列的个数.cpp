//给定一个未排序的整数数组，找到最长递增子序列的个数。 
//
// 示例 1: 
//
// 
//输入: [1,3,5,4,7]
//输出: 2
//解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
// 
//
// 示例 2: 
//
// 
//输入: [2,2,2,2,2]
//输出: 5
//解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
// 
//
// 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。 
// Related Topics 动态规划 
// 👍 261 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // dp[i] 表示第 i 个位置的最长递增序列的个数
    // 动态转移方程:
    // dp[i] = max(dp[j]) + 1 (0 <= j < i && nums[j] < nums[i])
    // [1,3,5,4,7]
    // 我们需要做的是将 i 前面的比 nums[i] 小的数字的最大个数记录下来
    //
    int findNumberOfLIS(vector<int>& nums)
    {
        int ret = 0;
        int maxVal = 0;
        map<int, int> record;
        vector<int> dp(nums.size());
        for (int i = 0; i < dp.size(); ++i)
        {
            maxVal = dp[i];
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] >= nums[i]) continue;
                if (dp[j] > maxVal) maxVal = dp[j];
            }
            dp[i] = maxVal + 1;
            ret = max(ret, dp[i]);
            record[ret] ++;
            cout << ret << " " << record[ret] << endl;
        }
        return record.rbegin()->second;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
