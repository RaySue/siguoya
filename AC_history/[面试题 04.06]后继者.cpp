//设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。 
//
// 如果指定节点没有对应的“下一个”节点，则返回null。 
//
// 示例 1: 
//
// 输入: root = [2,1,3], p = 1
//
//  2
// / \
//1   3
//
//输出: 2 
//
// 示例 2: 
//
// 输入: root = [5,3,6,2,4,null,null,1], p = 6
//
//      5
//     / \
//    3   6
//   / \
//  2   4
// /   
//1
//
//输出: null 
// Related Topics 树 深度优先搜索 
// 👍 38 👎 0


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


    // 一刷 2020.12.21

    // base line 利用 vector<int> 中序遍历，存储所有的节点，然后找到和 p 相等的节点的下一个即可

    // 略好的解法：利用额外的变量 flag 和 ans 来辅助
    // 深度优先搜索
    // flag 用于标识前一个节点和p是否相等，如果相等，则 ans赋值为当前节点，别忘了把 flag改为false，否则出栈的时候flag一直是 true， ans的值会被改
    // ans 用于全局存储 后继节点
    bool flag = false;
    TreeNode *ans;

    TreeNode *inorderSuccessor1(TreeNode *root, TreeNode *p)
    {
        if (!root) return nullptr;
        inorder(root, p);
        return ans;
    }

    void inorder(TreeNode *root, TreeNode *p)
    {
        if (!root) return;
        inorder(root->left, p);
        if (flag)
        {
            ans = root;
            flag = false;
            return;
        }
        if (root == p)
        {
            flag = true;
        }
        inorder(root->right, p);
    }


    // 最优的解法，充分考虑到 BST 的特性，用以启发式搜索
    /**
     *
     * 所谓 p 的后继节点，就是这串升序数字中，比 p 大的下一个。
        + 如果 p 大于当前节点的值，说明后继节点一定在 RightTree
        + 如果 p 等于当前节点的值，说明后继节点一定在 RightTree
        + 如果 p 小于当前节点的值，说明后继节点一定在 LeftTree 或自己就是
        + 递归调用 LeftTree，如果是空的，说明当前节点就是答案
        + 如果不是空的，则说明在 LeftTree 已经找到合适的答案，直接返回即可
     */
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root) return root;
        if (root->val <= p->val)
        {
            return inorderSuccessor(root->right, p);
        } else
        {
            TreeNode *cur = inorderSuccessor(root->left, p);
            return !cur ? root : cur;
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
