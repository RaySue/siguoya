//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: [1,2,3,4,5,6,7] 和 k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
// 
//
// 示例 2: 
//
// 输入: [-1,-100,3,99] 和 k = 2
//输出: [3,99,-1,-100]
//解释: 
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100] 
//
// 说明: 
//
// 
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。 
// 要求使用空间复杂度为 O(1) 的 原地 算法。 
// 
// Related Topics 数组 
// 👍 758 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 二刷 2020.12.27
    // 1. 利用额外的 o(k) 的空间
    // 2. 存储 nums 后面的三个元素
    // 3. 插入到 nums 的 begin
    void rotate1(vector<int> &nums, int k)
    {
        if (k == 0) return;
        k %= nums.size();
        vector<int> buffer(k);
        for (int i = 0; i < k; ++i)
        {
            buffer[k - i - 1] = nums.back();
            nums.pop_back();
        }
        nums.insert(nums.begin(), buffer.begin(), buffer.end());
    }

    // 终极解法
    // 原地反转，三次 reverse
    // [1,2,3,4,5,6,7]    [5,6,7,1,2,3,4]
    // [7,6,5,4,3,2,1]
    //
    void rotate2(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.end() - (nums.size() - k), nums.end());
    }









    // 三刷 2021.01.08
    // 这个题目如果要求不使用额外的数组，如果没做过，现场很难反应过来，怀庆面试拍立淘遇到了这个问题，他没有给出答案
    // 输入: [1,2,3,4,5,6,7] 和 k = 3
    //      [7,6,5,4,3,2,1]
    // 输出: [5,6,7,1,2,3,4]
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }



};
//leetcode submit region end(Prohibit modification and deletion)
