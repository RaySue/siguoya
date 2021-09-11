// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 
//给定的树 A: 
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//给定的树 B： 
//
// 4 
// / 
// 1 
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
// Related Topics 树 
// 👍 151 👎 0


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

    // 一刷

    bool isContainTree(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2) return true;
        if (!t2 && t1) return true;
        if (!t1 && t2) return false;
        if (t1->val != t2->val) return false;
        return isContainTree(t1->left, t2->left) && isContainTree(t1->right, t2->right);
    }


    int getDepth(TreeNode *root)
    {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }

    // 思路：
    // 如果 A 中存在子结构 B， 那么 A 的深度肯定大于等于 B
    // 找到 A 中所有深度和 B 相等的节点，再判断改节点组成的树是否包含 B
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if(!B) return false;
        if(!A && B) return false;
        int depthA = getDepth(A);
        int depthB = getDepth(B);
//        cout << depthA << " " << depthB << endl;
        if (depthA < depthB) return false;
        else if (depthA == depthB) return isContainTree(A, B);
        else return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
