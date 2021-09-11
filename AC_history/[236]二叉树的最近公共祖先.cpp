//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 
//
// 示例 2: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉树中。 
// 
// Related Topics 树 
// 👍 727 👎 0


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

    bool isInTheTree(TreeNode* root, TreeNode* aim)
    {
        if (!root) return false;
        if (root == aim) return true;
        bool l = isInTheTree(root->left, aim);
        bool r = isInTheTree(root->right, aim);
        return l || r;
    }

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        bool lp, lq, rp, rq;

        lp = isInTheTree(root->left, p);
        rp = !lp;
        lq = isInTheTree(root->left, q);
        rq = !lq;

        if (lp && rq || rp && lq) return root;
        if (rp && rq) return lowestCommonAncestor(root->right, p, q);
        if (lp && lq) return lowestCommonAncestor(root->left, p, q);
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || p == root || q == root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        else if (!right) return left;
        else return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
