//实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：
// 任意一个节点，**其两棵子树的高度差不超过 1**。
// 示例 1: 给定二叉树 [3,9,20,null,null,15,7]
// 3
// / \
// 9  20
// /  \
// 15   7 返回 true 。示例 2: 给定二叉树 [1,2,
//2,3,3,null,null,4,4]       1      / \     2   2    / \   3   3  / \ 4   4
// 返回 fal
//se 。 Related Topics 树 深度优先搜索 
// 👍 37 👎 0


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

    int getDepth(TreeNode *root)
    {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root) return true;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
