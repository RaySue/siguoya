//请完成一个函数，输入一个二叉树，该函数输出它的镜像。 
//
// 例如输入： 
//
//    4
//   / \
//  2   7
// / \ / \ 
//1  3 6  9
//镜像输出： 
//
//    4
//   / \
//  7   2
// / \ / \ 
//9  6 3  1
//
// 
//
// 示例 1： 
//
// 输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/ 
// Related Topics 树 
// 👍 84 👎 0


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

    // 基于 DFS
    TreeNode* mirrorTree1(TreeNode* root)
    {
        if (!root) return nullptr;
        // 1
//        swap(root->left, root->right);
        // 2
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        return root;
    }

    // 基于 BFS
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (!root) return nullptr;
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while(!treeQ.empty())
        {
            TreeNode *cur = treeQ.front(); treeQ.pop();
            if (cur == nullptr) continue;
            if (!cur->left && !cur->right) continue;  // 注意 [1, 2] 非对称的情况
            swap(cur->left, cur->right);
            treeQ.push(cur->left);
            treeQ.push(cur->right);
        }
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
