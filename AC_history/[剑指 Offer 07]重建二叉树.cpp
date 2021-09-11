// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//
// 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]     9   20 15 7
//中序遍历 inorder = [9,3,15,20,7]       9   15 20 7
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归 
// 👍 261 👎 0


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

    // 三刷 2021.01.22
    // 根据二叉树的前序遍历和中序遍历重构二叉树
    // 1. 先利用前序遍历第一个元素是根节点 r ，来创建根节点
    // 2. 在中序遍历的结果中寻找 r,将中序遍历的结果分为两个部分
    // 3. 根据中序遍历的左子树的长度，回到前序遍历的序列中拿到对应的左子树的长度，构成新的前序遍历序列和中序遍历序列，递归构建 root->left
    // 4. 同理，递归构建 root->right
    // 根节点->左子树->右子树  // 左子树，右子树都是前序遍历的序列
    // 左子树->根节点->右子树  // 左子树，右子树都是中序遍历的序列

    TreeNode *buildTree(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd)
    {
        if (pStart > pEnd) return nullptr;
        int rootVal = preorder[pStart];
        TreeNode *root = new TreeNode(rootVal);
        if (pStart == pEnd)
        {
            return root;
        }
        int index = find(inorder.begin() + iStart, inorder.begin() + iEnd, rootVal) - inorder.begin();
        root->left = buildTree(preorder, pStart + 1, pStart + index - iStart, inorder, iStart, index - 1);
        root->right = buildTree(preorder, pStart + index - iStart + 1, pEnd, inorder, index + 1, iEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty()) return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
