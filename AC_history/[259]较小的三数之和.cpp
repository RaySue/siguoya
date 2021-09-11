// 给定一个长度为 n 的整数数组和一个目标值 target，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三
// 元组 i, j, k 个数（0 <= i < j < k < n）。
//
// 示例： 
//
// 输入: nums = [-2,0,1,3], target = 2
//输出: 2 
//解释: 因为一共有两个三元组满足累加和小于 2:
//     [-2,0,1]
//     [-2,0,3]
// 
//
// 进阶：是否能在 O(n2) 的时间复杂度内解决？ 
// Related Topics 数组 双指针 
// 👍 66 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 较小的三数之和 与 三数之和还是不一样的
    // 类似于 等式 和 不等式 的关系一样
    // 这个就不需要去重了
    int threeSumSmaller(vector<int> &nums, int target)
    {
        int count = 0;
        if (nums.size() < 3) return count;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
//            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] < target)
                {
                    count += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return count;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
