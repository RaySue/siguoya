// 给定一个二叉树和一个目标和，
// 判断该树中<**是否存在**根节点到叶子节点的路径>，
// 这条路径上所有节点值相加等于目标和。
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
//         /  \      \
//        7    2      1
// 
//
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。 
// Related Topics 树 深度优先搜索 
// 👍 481 👎 0


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
class Solution {
public:
    // 要求的是 根 到 叶子节点 二刷 2020.12.14
    // 上来读题，第一个想法是用回溯，所以再来一遍，我的目的是看到题，喝多的时候都能做出来，三刷 2020.12.25
    // 这个题目的意思非常简洁，就是要找到从根节点到任意叶子节点的和 等于目标和，任意路径满足就返回true
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (!root) return false;
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
