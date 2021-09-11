// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值
// 与 target 相等？找出所有满足条件且不重复的四元组。
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针 
// 👍 699 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 二刷 2020.12.23
    // 原理和三数之和一样
    // 注意：
    // 1. 异常情况处理
    // 2. for 循环后的重复元素剔除
    // 3. while 循环的重复元素剔除，while循环的条件 l < r & 8888
    vector <vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector <vector<int>> ans;
        if (nums.size() < 4) return ans; // #
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                // 注意这里的重复元素去除，一定是第一轮结束之后再开始去除，否则会漏掉情况
                // 因为 每个数字都会和后面的数字组成符合要求的元组，如果开始就去除，
                // 那么在第一个元素和后面开始组成的时候就会因为缺失元素而漏掉一些情况
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    int cur = nums[i] + nums[j] + nums[l];
                    if (cur > target - nums[r])
                    {
                        r--;
                    } else if (cur < target - nums[r])
                    {
                        l++;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l - 1] == nums[l]) l++;
                        while(l < r && nums[r + 1] == nums[r]) r--;
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
