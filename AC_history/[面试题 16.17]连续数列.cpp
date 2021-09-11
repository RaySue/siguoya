//给定一个整数数组，找出总和最大的连续数列，并返回总和。 
//
// 示例： 
//
// 输入： [-2,1,-3,4,-1,2,1,-5,4]
//输出： 6
//解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶： 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 60 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 四刷 2020.12.29，LC 中重复的题目真的挺多的
    // 注意 ans 的初始值，非常关键如果初始化为 0，你就败了
    // 滑窗法，如果 window < 0, 那么从下一个数字开始累加滑窗
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int window = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (window >= 0)
            {
                window += nums[i];
            } else
            {
                window = nums[i];
            }
            ans = max(ans, window);
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
