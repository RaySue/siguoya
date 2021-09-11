// 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法 
// 👍 874 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.24
    /**
        Success:
        Runtime:0 ms, faster than 100.00% of C++ online submissions.
        Memory Usage:7.5 MB, less than 25.17% of C++ online submissions.
     */
    // 无他，但手熟尔
    // 三刷 2021.02.01， 无他，但手熟尔
    vector <vector<int>> ans;

    void backtrack(vector<int> &nums, int depth, int start, vector<int> &path, int n)
    {

        if (depth == n)
        {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtrack(nums, depth + 1, i + 1, path, n);
            path.pop_back();
        }


    }

    vector <vector<int>> subsets(vector<int> &nums)
    {
        vector<int> path;
        for (int n = 0; n <= nums.size(); ++n)
        {
            backtrack(nums, 0, 0, path, n);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
