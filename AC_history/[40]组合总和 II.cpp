//
// 给定一个数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 说明： 
//
// 
// 所有数字（包括目标数）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//] 
// Related Topics 数组 回溯算法 
// 👍 343 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    /**
     * 难点在于如何去掉重复的结果，可以使用set，但是需要占用内存
     * 1. 存在重复的元素，每个数字只可以使用一次
     *
     */

    vector <vector<int>> ans;

    void backtrack(vector<int> &candidates, int start, int depth, int target, vector<int> path)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            // i > start, 表示下一轮迭代可以选择和上一次相等的元素，而同一轮迭代不会再出现相等的元素导致重复
            if (i > start && candidates[i] == candidates[i - 1] ) continue;
            if (target < candidates[i]) break;
            target -= candidates[i];
            path.push_back(candidates[i]);
            // 此处start = i+1 因为每个数字只可以使用一次
            backtrack(candidates, i + 1, depth + 1, target, path);
            path.pop_back();
            target += candidates[i];
        }
    }


    vector <vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, 0, 0, target, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
