//给定一个二叉树和一个目标和，找到所有从**根节点到叶子节点**路径总和等于给定目标和的路径。
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//给定如下二叉树，以及目标和 sum = 22， 
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
//]
// 
// Related Topics 树 深度优先搜索 
// 👍 309 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:

    // 二刷 2020.12.14
    // 由于路径总和的思路略微生疏，所以连坐，1，2，3都再刷一遍
    // 三刷 2020.12.25
    // 路径总和 相比这道题而言就是其中的一种情况，而这道题摆明了就是要使用回溯算法
    // 终止条件，target == sum，且当前节点为叶子节点

    // 每一次的刷题是带着思考，重新编码，这样才有意义，比如这一次我写的回溯算法就和之前的回溯算法的模板不一样，并且更加高效

    // 无他，但手熟尔
    vector<vector<int>> ans;

    void backtrack(TreeNode *root, int target, int sum, vector<int> &path)
    {
        if (!root) return;
        target += root->val;
        path.push_back(root->val);

        if (target == sum && !root->left && !root->right)
        {
            ans.push_back(path);
        }

        backtrack(root->left, target, sum, path);
        backtrack(root->right, target, sum, path);

        path.pop_back();
        target -= root->val;
    }

    vector <vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root) return ans;
        vector<int> path;
        backtrack(root, 0, sum, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
