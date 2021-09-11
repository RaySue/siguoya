// 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须 原地 修改，只允许使用额外常数空间。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[1,2,3]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1,5]
//输出：[1,5,1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
//
// step1: [1,2,6,3,5,4]
// step2: [1,2,6,3,4,5]
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
// Related Topics 数组 
// 👍 837 👎 0

// [1,3,2] [2,3,1] [2,1,3]
// [3,1,2]
// [2,1,3]
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    //    [1,2,3,6,5,4]
    // 思路: 就是找到大于目前排列数的最小数
    // 可以把排列数看成是一个整数，调换他们的顺序，找到大于目前
    void nextPermutation1(vector<int> &nums)
    {
        // 1. 从后向前找到第一次出现前一个元素小于自身的位置 i - 1
        // 2. 然后从后向前找到大于 nums[i-1] 的数与其 swap
        // 3. 然后对 i 后面逆序即可
        int loc = -1;
        // 1. 从后向前找到第一次出现前一个元素小于自身的位置 i - 1
        for (int i = nums.size() - 1; i >= 1; --i)
        {
            if (nums[i] > nums[i - 1])
            {
                loc = i - 1;
                break;
            }
        }
        if (loc == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        // 2. 然后从后向前找到大于 nums[i-1] 的数与其 swap
        for (int i = nums.size() - 1; i >= 1; --i)
        {
            if (nums[i] > nums[loc])
            {
                swap(nums[i], nums[loc]);
                break;
            }
        }
        // 3. 然后对 i 后面逆序即可
        reverse(nums.begin() + loc + 1, nums.end());
    }

    //    [1,2,3,6,5,4]
    // 1. 先从后向前找到第一个顺序对 找到了 3, 6
    // 2. 再从后向前找到第一个大于逆序对靠前的数字 4
    // 3. 交换两个数字，然后对 3 后面的数字逆序
    // [3, 2, 1]
    // [1, 2]
    void nextPermutation(vector<int> &nums)
    {
        int p = nums.size() - 1;
        while (p > 0 && nums[p] <= nums[p - 1]) p--;
        --p;  // p 指向的是要替换的数字
//        cout << p << endl;
        if (p >= 0)
        {
            int p2 = nums.size() - 1;
            while(p2 > p && nums[p2] <= nums[p]) p2 --;
//            cout << p2 << endl;
            swap(nums[p], nums[p2]);
        }
        reverse(nums.begin() + p + 1, nums.end());
    }


};
//leetcode submit region end(Prohibit modification and deletion)
