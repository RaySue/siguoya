// 统计一个数字在排序数组中出现的次数。
//
// 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
// Related Topics 数组 二分查找 
// 👍 81 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二分法三种模板
    // 1. 寻找一个数，[left, right]
    // 2. 寻找一个数的左边界，注意判断 left 是否右溢出及 nums[left] == target ?
    // 3. 寻找一个数的右边界，注意判断 right 是否左溢出及 nums[right] == target ?
    int search(vector<int> &nums, int target)
    {
        // search 做边界
        int leftBound, rightBound;
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else if (nums[mid] > target)
            {
                r = mid - 1;
            } else
            {
                r = mid - 1;
            }
        }
        if (l == nums.size() || nums[l] != target)
            return 0;
        leftBound = l;
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else if (nums[mid] > target)
            {
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }
        rightBound = r;
        return rightBound - leftBound + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
