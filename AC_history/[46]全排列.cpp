//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法 
// 👍 897 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int> &nums, int depth, vector<bool> &isVis, vector<int> &path)
    {
        if (depth == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (isVis[i]) continue;
            path.push_back(nums[i]);
            isVis[i] = true;
            backtrack(nums, depth + 1, isVis, path);
            isVis[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> isVis(nums.size());
        vector<int> path;
        backtrack(nums, 0, isVis, path);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
