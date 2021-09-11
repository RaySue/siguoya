//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索 
// 👍 745 👎 0


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
    // naive by myself
    int minVal(TreeNode* root)
    {
        if (!root) return INT_MAX;
        int left = minVal(root->left);
        int right = minVal(root->right);
        return min(min(root->val, left), right);
    }

    int maxVal(TreeNode* root)
    {
        if (!root) return INT_MIN;
        int left = maxVal(root->left);
        int right = maxVal(root->right);
        return max(max(root->val, left), right);
    }

    bool isValidBST1(TreeNode* root)
    {
        if (!root) return true;
        if (root->left && maxVal(root->left) >= root->val) return false;
        if (root->right && minVal(root->right) <= root->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }

    // ----------------------------------------------------------------------

    bool helper(TreeNode* root, long long lower, long long upper)
    {
        if (root == nullptr) return true;
        if (root -> val <= lower || root -> val >= upper) return false;
        // 每次判断都和父节点进行判断
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST2(TreeNode* root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    // -----------------------------------------------

    TreeNode* pre = nullptr;

    bool ans = true;

    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        if (pre != nullptr)
        {
            if (pre->val >= root->val) ans = false;
        }
        pre = root;
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        dfs(root);
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
