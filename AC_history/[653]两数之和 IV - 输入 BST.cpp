//给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。 
//
// 案例 1: 
//
// 
//输入: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//输出: True
// 
//
// 
//
// 案例 2: 
//
// 
//输入: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//输出: False
// 
//
// 
// Related Topics 树 
// 👍 196 👎 0


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

    // 思路：
    // 中序遍历得到数组，双指针 two sum
    void inOrderedTraverse(TreeNode* root, vector<int> &treeVec)
    {
        if (!root) return;
        inOrderedTraverse(root->left, treeVec);
        treeVec.push_back(root->val);
        inOrderedTraverse(root->right, treeVec);
    }

    bool findTarget(TreeNode* root, int k)
    {
        vector<int> treeVec;
        inOrderedTraverse(root, treeVec);
        int l = 0, r = treeVec.size() - 1;
        while (l < r)
        {
            int tmpSum = treeVec[l] + treeVec[r];
            if (tmpSum < k) l++;
            else if (tmpSum > k) r--;
            else {return true;}
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
