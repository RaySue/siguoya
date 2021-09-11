//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 105] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 422 👎 0


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

    // 二刷 2020.12.22
    // DFS
    // 只需要处理根节点只有一个叶子的情况
    int minDepth(TreeNode* root)
    {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 || right == 0)
        {
            return max(left, right) + 1;  // 如果只剩下一个子叶，那么去左右的最大值 + 1
        } else {
            return min(left, right) + 1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
