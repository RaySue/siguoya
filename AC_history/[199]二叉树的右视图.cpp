//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 示例: 
//
// 输入: [1,2,3,null,5,null,4]
//输出: [1, 3, 4]
//解释:
//
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 313 👎 0


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

    void bfs(TreeNode* root, vector<int> &ans)
    {
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while(!treeQ.empty())
        {
            int sz = treeQ.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = treeQ.front();treeQ.pop();
                if (i == sz - 1)
                {
                    ans.push_back(cur->val);
                }
                if (cur->left) treeQ.push(cur->left);
                if (cur->right) treeQ.push(cur->right);
            }
        }
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        if (!root) return ans;
        bfs(root, ans);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
