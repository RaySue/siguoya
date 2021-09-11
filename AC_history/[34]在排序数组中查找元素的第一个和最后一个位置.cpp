//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 780 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 三刷 2020.12.24
    // 这次刷也很有收获，之前都是三分支判断找左右边界，其实可以对其中的两个分支合并
    // 注意找左边界返回的是l，需要对l做边界检测，如果l过大，或l不等于taget，说明没有找到
    // 右边界r需要检测是否左边界溢出
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // 判断左边界是否 右溢出
        if (l >= nums.size() || nums[l] != target) return {-1, -1};

        int leftBound = l;
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (r < 0 || nums[r] != target) return {-1, -1};

        int rightBound = r;
        return {leftBound, rightBound};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
