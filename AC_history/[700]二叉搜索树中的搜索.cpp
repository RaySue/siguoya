//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。 
//
// 例如， 
//
// 
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和值: 2
// 
//
// 你应该返回如下子树: 
//
// 
//      2     
//     / \   
//    1   3
// 
//
// 在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。 
// Related Topics 树 
// 👍 105 👎 0


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

    // 一刷 2020.01.09
    // BST 的问题要充分利用一下其性质，直接遍历也可以解决，可能会直接面挂
    TreeNode *dfs(TreeNode *root, int val)
    {
        if (!root) return nullptr;
        if (root->val == val) return root;
        return root->val > val ? dfs(root->left, val) : dfs(root->right, val);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        return dfs(root, val);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
