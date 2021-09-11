//给定一个二叉树，返回所有从根节点到叶子节点的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 输入:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3 
// Related Topics 树 深度优先搜索 
// 👍 312 👎 0


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
//
//    vector <string> helper(TreeNode *root, string path, vector <string> &pathList)
//    {
//        path = path + to_string(root->val) + "->";
//        // 分左右子树考虑的情况，完全可以只考虑根节点
//        if (root->left)
//        {
//            helper(root->left, path, pathList);
//        }
//        if (root->right)
//        {
//            helper(root->right, path, pathList);
//        }
//        if (!root->left && !root->right) {
//            path.pop_back();
//            path.pop_back();
//            pathList.push_back(path);
//        }
//        return pathList;
//    }

    void dfs(TreeNode *root, string path, vector <string> &pathList)
    {
        if (!root) return;
        path = path + to_string(root->val);
        if (!root->left && !root->right)
        {
            pathList.push_back(path);
        } else {
            path += "->";
        }
        dfs(root->left, path, pathList);
        dfs(root->right, path, pathList);
    }

    void bfs(TreeNode *root, vector<string> &pathList)
    {
        queue<TreeNode*> treeQ;
        queue<string> pathQ;
        treeQ.push(root);
        pathQ.push(to_string(root->val));
        while(!treeQ.empty())
        {
            TreeNode *cur = treeQ.front();treeQ.pop();
            string path = pathQ.front();pathQ.pop();
            if (!cur->left && !cur->right)
            {
                pathList.push_back(path);
                continue;
            }
            if (cur->left)
            {
                string left_path = path + "->" + to_string(cur->left->val);
                treeQ.push(cur->left);
                pathQ.push(left_path);
            }
            if (cur->right)
            {
                string right_path = path + "->" + to_string(cur->right->val);
                treeQ.push(cur->right);
                pathQ.push(right_path);
            }
        }
    }

    vector <string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root) return ans;
        string path;
//        dfs(root, path, ans);
        bfs(root, ans);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
