// 二叉树数据结构 TreeNode 可用来表示单向链表（其中left置空，right为下一个链表节点）。
// 实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉
// 搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
//
// 返回转换后的单向链表的头节点。 
//
// 注意：本题相对原题稍作改动 
//
//
//
// 示例： 
/*
 *                 4
 *             2      5
 *          1    3       6
 *        0
*/
// 输入： [4,2,5,1,3,null,6,0]
//输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
// 
//
// 提示： 
//
// 
// 节点数量不会超过 100000。 
// 
// Related Topics 树 二叉搜索树 递归 
// 👍 54 👎 0


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

    TreeNode* pre = nullptr;

    // 左->根->右 >>> 右->根->左
    void inverseInOrderTraverse(TreeNode* root)
    {
        if (!root) return;
        inverseInOrderTraverse(root->right);
        root->right = pre;
        pre = root;
        inverseInOrderTraverse(root->left);
        root->left = nullptr;
    }

    TreeNode* convertBiNode(TreeNode* root)
    {
        inverseInOrderTraverse(root);
        return pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
