//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: [1,2,2]
//输出:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//] 
// Related Topics 数组 回溯算法 
// 👍 360 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2020.12.24
    // 和简单的回溯算法类型相比略微复杂一些，就是我们需要对多个数字进行组合 for 循环 回溯
    // 这里的剪枝用到的逻辑有三个：
    // 1. 通用的 isVis 用以防止重复元素出现
    // 2. start 用以保证顺序
    // 3. i > start && nums[i - 1] == nums[i] && !isVis[i - 1] 用以保证重复元素的顺序

    // 特殊情况1： nums 为空
    // 特殊情况2： nums 的 size 为 1 的时候，我们对size为1的push_back后有对总体元素push_back 会出现重复

    vector <vector<int>> ans;

    void backtrack(vector<int> &nums, vector<bool> &isVis, vector<int> &path, int depth, int start, int n)
    {
        if (depth == n)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); ++i)
        {
            if (isVis[i]) continue;
            if (i > start && nums[i - 1] == nums[i] && !isVis[i - 1]) continue;
            path.push_back(nums[i]);
            isVis[i] = true;
            backtrack(nums, isVis, path, depth + 1, i, n);
            isVis[i] = false;
            path.pop_back();
        }
    }

    vector <vector<int>> subsetsWithDup(vector<int> &nums)
    {
        ans.push_back({});
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        // 回溯添加 size == 1 ~ size == nums.size() - 1
        for (int n = 1; n < nums.size(); ++n)
        {
            vector<bool> isVis(nums.size());
            vector<int> path;
            backtrack(nums, isVis, path, 0, 0, n);
        }

        // add size == nums.size();
        ans.push_back(nums);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
