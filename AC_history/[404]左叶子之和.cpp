//计算给定二叉树的所有左叶子之和。 
//
// 示例： 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 
//
// 
// Related Topics 树 
// 👍 211 👎 0


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

    int sum = 0;

    int sumOfLeftLeaves(TreeNode* root)
    {
        if (!root) return 0;
        // 找到左叶子，遍历即可
        if (root->left && !root->left->left && !root->left->right)
        {
            sum += root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
