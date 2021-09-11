//
// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法 
// 👍 837 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<vector<int> > ans;

    /**
     *
     * 1. 注意题目说的是无重复的数字，每个数字可以无限次的使用
     * 2. 我们需要先对数组进行排序
     * 3. 我们需要 start 变量来控制去重复的结果
     * 4. target - candidates[i] 的时候注意负数的情况
     *
     * @param candidates
     * @param start
     * @param depth
     * @param target
     * @param path
     */
    void backtrack(vector<int> &candidates, int start, int depth, int target, vector<int> path)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            if (target < candidates[i]) break;
            target -= candidates[i];
            path.push_back(candidates[i]);
            // 此处start是i，因为每个数字可以使用无限次
            backtrack(candidates, i, depth + 1, target, path);
            path.pop_back();
            target += candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, 0, 0, target, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
