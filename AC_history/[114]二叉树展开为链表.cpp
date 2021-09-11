//给定一个二叉树，原地将它展开为一个单链表。 
//
// 
//
// 例如，给定二叉树 
//
//     1
//   / \
//  2   5
// / \   \
//3   4   6 
//
// 将其展开为： 
//
// 1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6 
// Related Topics 树 深度优先搜索 
// 👍 641 👎 0


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

    // 朴素解法：利用 vector<TreeNode*> 存储root前序遍历的结果，
    // 然后再沿着root的右子树赋值展开，每个位置new一个 TreeNode，然后left = nullptr，right = root->val;
    void dfs(TreeNode* root, vector<int> &ret)
    {
        if (!root) return;
        ret.push_back(root->val);
        dfs(root->left, ret);
        dfs(root->right, ret);
    }


    void flatten(TreeNode* root)
    {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }

    // 二刷，2020.12.28
    // 根->左->右 >>> 右->左->根 ***
    // 反向后续遍历
    // 先下后上；
    // 先右后左；

    TreeNode* pre = nullptr;
    void flatten2(TreeNode* root)
    {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
