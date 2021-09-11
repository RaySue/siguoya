//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。 
//
// 你找到的子数组应是最短的，请输出它的长度。 
//
// 示例 1: 
//
//     [2, 4, 6, 8, 9, 10, 15]
//输入: [2, 6, 4, 8, 10, 9, 15]
//输出: 5
//解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 
//
// 说明 : 
//
// 
// 输入的数组长度范围在 [1, 10,000]。 
// 输入的数组可能包含重复元素 ，所以升序的意思是<=。 
// 
// Related Topics 数组 
// 👍 458 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 排序比较
    // 先对数组排序，然后再左右 相向搜索，找到刚不相等的就停下
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] == sortedNums[l]) l++;
        while (l < r && nums[r] == sortedNums[r]) r--;

        return r == l? 0 :r - l + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
