// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。 
//
// 
//
// 示例： 
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 双指针 
// 👍 647 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int l, r, closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                int temp = nums[i] + nums[l] + nums[r];

                if (abs(temp - target) < abs(closest - target))
                    closest = temp;

                if (temp > target)
                {
                    r--;
                    while (l < r && nums[r + 1] == nums[r]) r--;
                } else if (temp < target)
                {
                    l++;
                    while (l < r && nums[l - 1] == nums[l]) l++;
                } else
                {
                    return target;
                }
            }
        }
        return closest;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
