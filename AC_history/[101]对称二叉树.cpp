//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 1222 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    bool isSymmetric(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2) return true;
        if ((!t1 && t2) || (!t2 && t1) || t1->val != t2->val) return false;
        bool l = isSymmetric(t1->left, t2->right);
        bool r = isSymmetric(t1->right, t2->left);
        return l && r;
    }

    bool isSymmetric(TreeNode* root)
    {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
