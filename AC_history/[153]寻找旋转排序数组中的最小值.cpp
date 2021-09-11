// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 你可以假设数组中不存在重复元素。 
//
// 示例 1: 
//
// 输入: [3,4,5,1,2]
//输出: 1 
//
// 示例 2: 
//
// 输入: [4,5,6,7,0,1,2]
//输出: 0 
// Related Topics 数组 二分查找 
// 👍 248 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 二分法
    // 1. 如果 nums[l] <= nums[r] return nums[r]， 说明此时[l,r]区间是有序的，一定是 l 最小
    // 2. 判断 mid 在 左部分 or 右部分 if (nums[mid] >= nums[l])
    // 3. if 左部分 l = mid + 1; 判断 [mid + 1, r]
    // 4. if 右部分 r = mid; 判断 [l, mid] 因为在右部分的话 nums[l] > nums[mid], 我们还需要判断一下mid才行

    // 二刷 2020.12.31 牛年要来了
    // 思路：
    // 1. 我们先考虑不旋转的情况，那么最小值无疑是 nums[l]
    // 2. 如果出现了旋转，那么我们只能通过 nums[mid] 与 nums[l] 来判断如何进行边界收缩
    //    举例：如果用 nums[mid] 与 nums[r] 来判断，nums[mid] <= nums[r]，说明 mid 在右部分，而且mid可能就是最小值，l = mid
    //         如果 nums[mid] > nums[r] 说明mid在左部分，而最小值一定在右部分，所以 l = mid + 1 就会有问题，r = mid + 1 也不对
    // 3. nums[l] <= nums[mid] 应该收缩左区间 l = mid + 1
    // 4. nums[l] > nums[mid] 说明 mid 在右部分 r = mid; 因为可能 mid 就是最小值

    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[l] <= nums[r]) return nums[l];
            else if (nums[l] <= nums[mid])
            {
                l = mid + 1;
            } else
            {
                r = mid;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
