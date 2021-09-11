//给定一个由正整数组成且 **不存在重复数字** 的数组，找出和为给定目标正整数的组合的个数。
//
// 示例: 
//
// 
//nums = [1, 2, 3]
//target = 4
//
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//请注意，顺序不同的序列被视作不同的组合。
//
//因此输出为 7。
// 
//
// 进阶： 
//如果给定的数组中含有负数会怎么样？ 
//问题会产生什么变化？ 
//我们需要在题目中添加什么限制来允许负数的出现？ 
//
// 致谢： 
//特别感谢 @pbrother 添加此问题并创建所有测试用例。 
// Related Topics 动态规划 
// 👍 256 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 一刷，回溯算法 Time out
    int res = 0;

    void backtrack(vector<int> &nums, int target, int &path)
    {
        if (path == target)
        {
            res++;
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (path > target) return;
            path += nums[i];
            backtrack(nums, target, path);
            path -= nums[i];
        }
    }

    int combinationSum41(vector<int> &nums, int target)
    {
        int path = 0;
        backtrack(nums, target, path);
        return res;
    }

    // ------------------------ 动态规划 --------------------------------------

    int combinationSum4(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector <int> d(target + 1, 0);
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i > nums[j])
                {
                    d[i] += d[i - nums[j]];
                } else if (i == nums[j])
                {
                    d[i] += 1;
                }
            }
        }
        return d[target];
    }


};
//leetcode submit region end(Prohibit modification and deletion)
