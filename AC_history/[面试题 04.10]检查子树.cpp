// 检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。
//
// 如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。 
//
// 示例1: 
//
//  输入：t1 = [1, 2, 3], t2 = [2]
// 输出：true
// 
//
// 示例2: 
//
//  输入：t1 = [1, null, 2, 4], t2 = [3, 2]
// 输出：false
// 
//
// 提示： 
//
// 
// 树的节点数目范围为[0, 20000]。 
// 
// Related Topics 树 
// 👍 23 👎 0


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

    int getDepth(TreeNode *root)
    {
        if (!root) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left, right) + 1;
    }

    bool isSame(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 && t2 || !t2 && t1) return false;
        if (t1->val != t2->val) return false;
        return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    }

    bool checkSubTree(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && t2) return false;
        if (t1 && !t2 || !t1 && !t2) return true;
        int d1 = getDepth(t1);
        int d2 = getDepth(t2);
        if (d1 == d2)
        {
            return isSame(t1, t2);
        } else if (d1 > d2)
        {
            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        } else {
            return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
