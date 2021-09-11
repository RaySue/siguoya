//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。 
//
// 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。 
//
// 示例 1: 
//
// 输入: nums = [2,5,6,0,0,1,2], target = 0
//输出: true
// 
//
// 示例 2: 
//
// 输入: nums = [2,5,6,0,0,1,2], target = 3
//输出: false 
//
// 进阶: 
//
// 
// 这是 搜索旋转排序数组 的延伸题目，本题中的 nums 可能包含重复元素。 
// 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？ 
// 
// Related Topics 数组 二分查找 
// 👍 267 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.31
    // 二分法的核心找到有序区间，然后在有序区间中判断每次搜索去掉哪一半
    // 和 33 题唯一的区别是 nums[mid] 等于边界值时候的处理，退化为了线性的搜索
    //
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] == target) return true;
            else if (nums[l] < nums[mid])
            {
                if (nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] > nums[mid])
            {
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else
            {
                for (int i = mid; i <= r; ++i)
                {
                    if (nums[i] == target) return true;
                }
                r = mid - 1;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
