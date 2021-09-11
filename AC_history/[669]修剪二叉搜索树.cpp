// 给你二叉搜索树的根节点 root ，同时给定最小边界 low 和最大边界 high。
// 通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
// 修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
//
// 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,0,2], low = 1, high = 2
//输出：[1,null,2]
// 
//
// 示例 2： 
//
//               3
//            0    4
//              2
//           1
// 
//输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
//输出：[3,2,null,1]
// 
//
// 示例 3： 
//
// 
//输入：root = [1], low = 1, high = 2
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,null,2], low = 1, high = 3
//输出：[1,null,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2], low = 2, high = 4
//输出：[2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数在范围 [1, 104] 内 
// 0 <= Node.val <= 104 
// 树中每个节点的值都是唯一的 
// 题目数据保证输入是一棵有效的二叉搜索树 
// 0 <= low <= high <= 104 
// 
// Related Topics 树 
// 👍 309 👎 0


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

    // 思路：
    // 前序遍历
    // 先判断一下根节点
    // 如果 根节点 < low, 那么就只可能右子树满足要求
    // 如果 根节点 > high, 那么就只可能左子树满足要求
    // 对左右子树都卡一遍
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root) return root;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
