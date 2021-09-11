// 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
//
// 
//
// 示例 1： 
//
// 
//输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
//输出：32
// 
//
// 示例 2： 
//
// 
//输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 2 * 104] 内 
// 1 <= Node.val <= 105 
// 1 <= low <= high <= 105 
// 所有 Node.val 互不相同 
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 146 👎 0


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

//    int sum = 0;
//

//    加这些判断，完全没意义
//    void dfs(TreeNode *root, int low, int high)
//    {
//        if (!root) return;
//        if (root->val < low)
//        {
//            dfs(root->right, low, high);
//        } else if (root->val > high)
//        {
//            dfs(root->left, low, high);
//        } else
//        {
//            sum += root->val;
//            dfs(root->left, low, high);
//            dfs(root->right, low, high);
//        }
//    }
//
//    int rangeSumBST(TreeNode *root, int low, int high)
//    {
//        dfs(root, low, high);
//        return sum;
//    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root) return 0;
        if (root->val >= low && root->val <= high)
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
        else return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
