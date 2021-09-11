//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。 
//
// 要求时间复杂度为O(n)。 
//
// 
//
// 示例1: 
// 动态规划 自底向上 ans  [-2, 1, 1, 4, 4, 5, 6, 6, 6 ]
//              tmpSum [-2, 1,-2, 4, 3, 5, 6, 1, 5]
//         输入: nums =[-2, 1,-3, 4,-1, 2, 1,-5, 4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^5 
// -100 <= arr[i] <= 100 
// 
//
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ 
//
// 
// Related Topics 分治算法 动态规划 
// 👍 169 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 贪心算法
    int maxSubArray1(vector<int> &nums)
    {
        int ans = INT_MIN;
        int tmpSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            tmpSum = tmpSum < 0 ? nums[i] : tmpSum + nums[i];
            ans = max(ans, tmpSum);
        }
        return ans;
    }

    // 动态规划
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1) return nums.back();
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > 0)
            {
                nums[i] += nums[i - 1];
            }
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    // 分治算法


};
//leetcode submit region end(Prohibit modification and deletion)
