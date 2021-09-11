// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
//
// 
//
// 示例 1: 
//
// 输入: [0,1,3]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [0,1,2,3,4,5,6,7,9]
//输出: 8 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 10000 
// Related Topics 数组 二分查找 
// 👍 79 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        if (nums.back() == nums.size() - 1) return nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i <= nums.size(); ++i)
        {
            ans ^= i;
        }
        for (int num:nums)
        {
            ans ^= num;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
