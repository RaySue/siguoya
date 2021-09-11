// 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
// 
//
// 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,5,6,7,0,1,2], target = 0
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,5,6,7,0,1,2], target = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：nums = [1], target = 0
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5000 
// -10^4 <= nums[i] <= 10^4 
// nums 中的每个值都 独一无二 
// nums 肯定会在某个点上旋转 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 二分查找 
// 👍 1114 👎 0



/**
 *
 *
 *
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.26
    // 思路：
    // 利用二分法
    // 1. 先判断 nums[mid] 在左半边，还是在右半边
    // 2. 如果在左半边，那么 target 是否在 l mid之间  l <= target < mid，
    // 3. 如果在右半边，那么 target 是否在 mid r之间  mid < target <= r，
    // 4. 相等返回mid，否则返回 -1




    // 三刷 2020.12.31
    // 找到有序区间就可以使用二分法
    // 1. 先判断 mid 在左半部分还是右半部分 找有序区间
    // 2. 如果在右半部分，判断是否在 mid 与 r 之间
    // 3. 如果在左半部分，判断是否在 l 与 mid 之间


    // 四刷 2021.02.01 阿里二面前4天
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && nums[mid] > target)
                {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] > nums[mid])
            {
                if (nums[mid] < target && nums[r] >= target)
                {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
