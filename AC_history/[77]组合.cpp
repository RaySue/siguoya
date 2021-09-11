//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法 
// 👍 460 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 二刷 2020.12.24
    // 这种组合问题非常简单，不需要使用 isVis
    // 我们只需使用 start 来控制先后顺序即可。
    vector<vector<int>> ans;

    void backtrack(int n, int depth, int start, vector<int> &path, int k)
    {
        if (depth == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i)
        {
            path.push_back(i);
            backtrack(n, depth + 1, i + 1, path, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> path;
        backtrack(n, 0, 1, path, k);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
