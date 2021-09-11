//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 注意数组中可能存在重复的元素。 
//
// 示例 1： 
//
// 输入: [1,3,5]
//输出: 1 
//
// 示例 2： 
//
// 输入: [2,2,2,0,1]
//输出: 0 
//
// 说明： 
//
// 
// 这道题是 寻找旋转排序数组中的最小值 的延伸题目。 
// 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？ 
// 
// Related Topics 数组 二分查找 
// 👍 173 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 二刷 2020.12.31
    // 三刷 2021.01.01
    // 四刷 2021.02.01
    int findMin(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int l = 0, r = nums.size() - 1, mid;
        int minVal = nums[0];
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[l] < nums[mid])
            {
                minVal = min(minVal, nums[l]);
                l = mid + 1;
            } else if (nums[l] > nums[mid])
            {
                minVal = min(minVal, nums[mid]);
                r = mid - 1;
            } else {
                for (int i = 0; i <= r; ++i)
                {
                    minVal = min(minVal, nums[i]);
                }
                return minVal;
            }
        }
        return minVal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
