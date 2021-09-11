// 在一个给定的数组nums中，总是存在一个最大元素 。
//
// 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。 
//
// 如果是，则返回最大元素的索引，否则返回-1。 
//
// 示例 1: 
//
// 输入: nums = [3, 6, 1, 0]
//输出: 1
//解释: 6是最大的整数, 对于数组中的其他整数,
//6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
// 
//
// 
//
// 示例 2: 
//
// 输入: nums = [1, 2, 3, 4]
//输出: -1
//解释: 4没有超过3的两倍大, 所以我们返回 -1.
// 
//
// 
//
// 提示: 
//
// 
// nums 的长度范围在[1, 50]. 
// 每个 nums[i] 的整数范围在 [0, 100]. 
// 
// Related Topics 数组 
// 👍 77 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.12
    // base 解法：
    // 一趟找到最大值，和次大值，判断最大值是否是次大值的二倍
    // 注意，second 不可以等于 INT_MIN， 因为返回的时候 * 2 来判断
    int dominantIndex(vector<int> &nums)
    {
        if (nums.empty()) return -1;
        int ret = 0;
        int second = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[ret])
            {
                second = nums[ret];
                ret = i;
            } else if (nums[i] > second)
            {
                second = nums[i];
            }
        }
        return nums[ret] >= second * 2 ? ret : -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
