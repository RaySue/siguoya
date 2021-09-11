//给定一个无序的整数数组，找到其中最长上升子序列的长度。 
//
//    // dp[i] 表示第 i 个元素结尾的最长上升子序列的长度（包含nums[i]）
//    // dp[i] = max(dp[j]) + 1,  0 <= j < i 且 nums[j] < nums[i]
//    // 最后，整个数组的最长上升子序列即所有 dp[i] 中的最大值。
//
// 示例: 
//
// 输入: [10,9,2,5,3,7,101,18]
//输出: 4 
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。 
//
// 说明: 
//
// 
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。 
// 你算法的时间复杂度应该为 O(n2) 。 
// 
//
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
// Related Topics 二分查找 动态规划 
// 👍 1206 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 定义 dp[i] 表示第 i 个位置的LIS
    // dp[i] = max(dp[j]) + 1, (0 <= j < i && nums[j] < nums[i] );
    // return dp[] 中的最大值
    int lengthOfLIS(vector<int>& nums)
    {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int maxVal = dp[i];
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] >= nums[i]) continue;
                if (dp[j] > maxVal) maxVal = dp[j];
            }
            dp[i] = maxVal + 1;
            if (dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
