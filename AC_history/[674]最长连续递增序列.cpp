//给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。 
//
// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那
//么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,5,4,7]
//输出：3
//解释：最长连续递增序列是 [1,3,5], 长度为3。
//尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2]
//输出：1
//解释：最长连续递增序列是 [2], 长度为1。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// 
// Related Topics 数组 
// 👍 121 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：一次遍历
    int findLengthOfLCIS1(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int p = 1, count = 1, maxCount = 1;
        while (p < nums.size())
        {
            if (nums[p] > nums[p - 1])
            {
                count++;
            } else if (count > maxCount)
            {
                maxCount = count;
                count = 1;
            } else {
                count = 1;
            }
            p++;
        }
        return (count > maxCount)? count:maxCount;
    }

    // 方法二： 滑动窗口
    int findLengthOfLCIS(vector<int> &nums)
    {
        int r = 0, maxCount = 0;
        vector<int> window;
        while(r < nums.size())
        {
            window.push_back(nums[r]);
            r++;
            // 滑动窗口注意这里 r < nums.size()， 否则容易出现数组越界
            if(!window.empty() && r < nums.size() && nums[r] <= window.back())
            {
                if (window.size() > maxCount) maxCount = window.size();
                window.clear();
            }
        }
        return window.size() > maxCount?window.size():maxCount;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
