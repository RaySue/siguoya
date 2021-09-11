//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。 
//
// 示例: 
//
// 输入: [0,1,0,3,12]
//输出: [1,3,12,0,0] 
//
// 说明: 
//
// 
// 必须在原数组上操作，不能拷贝额外的数组。 
// 尽量减少操作次数。 
// 
// Related Topics 数组 双指针 
// 👍 732 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 三刷：2020.12.24 圣诞节前夕，winter is coming.
    // 四刷：2021.02.02 除夕前， Spring is coming.
    void moveZeroes(vector<int> &nums)
    {
        int nonZerosIdx = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[nonZerosIdx++]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
