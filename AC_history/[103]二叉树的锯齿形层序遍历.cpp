//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回锯齿形层序遍历如下： 
//
// 
//[
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索 
// 👍 328 👎 0


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

    // 三刷 2020.12.22 忘记对异常空值做处理了，这个很致命
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tmp(size);
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();q.pop();
                tmp[i] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (flag) reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            flag = !flag;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
