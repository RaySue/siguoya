//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 2364 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 动态规划
    // sum > 0 继续累加，否则停止累加赋值为nums[i]
    int maxSubArray(vector<int>& nums)
    {
        int maxVal = INT_MIN;
        int window = INT_MIN;
        vector<int> ret;
        vector<int> tmp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (window < 0)
            {
                window = nums[i];
                tmp = {nums[i]};
            } else {
                window += nums[i];
                tmp.push_back(nums[i]);
            }
            if (window > maxVal)
            {
                maxVal = window;
                ret = tmp;
            }
        }
//        for (int i = 0; i < ret.size(); ++i)
//        {
//            cout << ret[i] << " " ;
//        }

        return maxVal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
