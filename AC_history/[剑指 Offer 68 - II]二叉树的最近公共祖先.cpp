// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
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
//
// 注意：本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a
//-binary-tree/ 
// Related Topics 树 
// 👍 166 👎 0


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

    // 自创的方法一，估计是全网最笨的方法，但很好理解
    bool isInTheTree(TreeNode *root, TreeNode *p)
    {
        if (!root) return false;
        if (root == p) return true;
        return isInTheTree(root->left, p) || isInTheTree(root->right, p);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p) return p;
        if (root == q) return q;
        bool lp = isInTheTree(root->left, p);
        bool rp = !lp;
        bool lq = isInTheTree(root->left, q);
        bool rq = !lq;
        if (lp && rq || rp && lq) return root;
        else if (lp && lq) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }


    // 后续遍历的办法
    // 1. 先判断左子树，再判断右子树
    // 2. 如果左右子树都不返回空，说明左右子树都搜索到了节点，那么返回root即可
    // 3. 如果左子树为空，那么说明都在右子树里面，返回的一定是右子树的刚好和p或q相等的节点，不再深入了，返回
    // 4. 如果右子树为空，同理，说明p、q都在左子树下面，返回的left就是恰好和p或q相等的节点
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 如果root为空或者为p或者为q则返回root
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 一边为空，才返回另一边，说明两个节点在一个子树中
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
