//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 805 👎 0


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd)
    {
        if (pStart > pEnd) return nullptr;
        int pivot = preorder[pStart];
        TreeNode *root = new TreeNode(pivot);
        if (pStart == pEnd) return root; // important
        int idx = find(inorder.begin(), inorder.end(), pivot) - inorder.begin();
        int leftPart = idx - iStart;
        root->left = buildTree(preorder, inorder, pStart + 1, pStart + leftPart, iStart, idx - 1);
        root->right = buildTree(preorder, inorder, pStart + leftPart + 1, pEnd, idx + 1, iEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty()) return nullptr;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
