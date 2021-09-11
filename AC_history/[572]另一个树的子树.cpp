//给定两个非空二叉树 s 和 t，
// 检验 s 中是否包含和 t 具有相同结构和节点值的子树。
// s 的一个子树包括 s 的一个节点和这个节点的所有子孙。
// s 也可以看做它自身的一棵子树。
//
// 示例 1: 
//给定的树 s: 
//
// 
//     3
//    / \
//   4   5
//  / \
// 1   2
// 
//
// 给定的树 t： 
//
// 
//   4 
//  / \
// 1   2
// 
//
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。 
//
// 示例 2: 
//给定的树 s： 
//
// 
//     3
//    / \
//   4   5
//  / \
// 1   2
//    /
//   0
// 
//
// 给定的树 t： 
//
// 
//   4
//  / \
// 1   2
// 
//
// 返回 false。 
// Related Topics 树 
// 👍 382 👎 0


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
class Solution
{
public:


    // 思路很直观：
    // 1. 如果一个 t 是的子树，那么 t 一定与 s 中同高度的子树相同 isSameTree
    // 2. 求取 s 的每个节点的高度（可优化），然后找到与t的高度相同的所有子树
    // 3. 把 s 中与 t 同高度的子树 isSameTree 结束
    bool isSameTree(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2) return true;
        if ((!t1 && t2) || (t1 && !t2)) return false;
        if (t1->val != t2->val) return false;
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }

    int getTreeDepth(TreeNode *root)
    {
        if (!root) return 0;
        return max(getTreeDepth(root->left), getTreeDepth(root->right)) + 1;
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && t) return false;
        int tDepth = getTreeDepth(t);
        int sDepth = getTreeDepth(s);
        if (sDepth == tDepth)
        {
            return isSameTree(s, t);
        } else if (sDepth > tDepth)
        {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        } else
        {
            return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
