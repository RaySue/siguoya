//实现一个函数，检查一棵二叉树是否为二叉搜索树。
// 示例 1:
// 输入:
//   2
//  / \
// 1   3
// 输出: true
//
// 示例 2:
// 输入:
//     5
//    / \
//   1   4  
//      / \  
//     3   6
// 输出: false 解释: 输入为: [5,1,4,null,null,3,6]。  
// 根节点的值为 5 ，但是其右子节点值为 4 。
//
// Related Topics 树 深度优先搜索
// 👍 34 👎 0


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

    // 方法一：
    // 思路：和二叉搜索树判断最小节点值间距一样的思路，不需要额外的 vector 空间
    //
    bool flag = false;
    int prev = 0;

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (flag)
        {
            if (root->val <= prev) return false;
        }
        flag = true;
        prev = root->val;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
