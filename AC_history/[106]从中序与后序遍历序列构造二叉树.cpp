//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组 
// 👍 296 👎 0


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

    TreeNode *helper(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        if (il > ir || pl > pr) return nullptr;
        int rootVal = postorder[pr];
        TreeNode *root = new TreeNode(rootVal);
        int idx = find(inorder.begin() + il, inorder.begin() + ir, rootVal) - inorder.begin();
        cout << idx << endl;
        // inorder = [9,3,15,20,7]
        // postorder = [9,15,7,20,3]
        int left = idx - il;
        int right = ir - idx;
        cout << left << " " << right << endl;
        root->left = helper(inorder, il, idx - 1, postorder, pl, pl + left - 1);
        root->right = helper(inorder, idx + 1, ir, postorder, pr - right, pr - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
