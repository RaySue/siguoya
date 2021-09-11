//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6 
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
// 
//
// 示例 2: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉搜索树中。 
// 
//
// 注意：本题与主站 235 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a
//-binary-search-tree/ 
// Related Topics 树 
// 👍 74 👎 0


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
    // 普通树的解法：
    // 遍历找到等于节点 p 和 节点 q 的返回
    // 三种情况：
    // 1. p 是 q 的子树在左边 或 q 是 p的子树在左边， if (!left) return right;
    // 2. p 是 q 的子树在左边 或 q 是 p的子树在右边， if (!right) return left;
    // 3. p 和 q 分别在两个子树下，返回当时的 root
    // 程序具体的运行逻辑：
    // 先一直向左找
    // 如果在->left找到了，在此节点->right向右找，如果没找到，返回此时等于p或q的左子树，如果找到了就返回此时的root
    // 如果没找到 left = nullptr ，回溯到根节点，向右找
    TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;
        if (!right) return left;
        return root;
    }

    // 充分利用 BST 的性质，有选择的递归，而不是盲目的递归
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q) return root;
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        } else
        {
            return root;
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
