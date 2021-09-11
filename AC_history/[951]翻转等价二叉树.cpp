// 我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。
//
// 只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。 
//
// 编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。 
//
// 
//
// 示例： 
//
// 输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,n
//ull,null,null,8,7]
//输出：true
//解释：我们翻转值为 1，3 以及 5 的三个节点。
//
// 
//
// 
//
// 提示： 
//
// 
// 每棵树最多有 100 个节点。 
// 每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数。 
// 
//
// 
// Related Topics 树 
// 👍 67 👎 0


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
class Solution
{
public:

    // 昨晚模拟的时候没有做出来，但是思路是对的，只是没有想清楚后面的逻辑
    // 本题其实很简单，我们只需要关注的就是当前两个根节点的情况即可，不要展开讨论其左右子树，否则就陷进去了
    // 思路：
    // 1. root1 和 root2 都为空那么返回true
    // 2. 如果一方为空，那么返回false （这里有同学想，那是不是还得考虑翻转之后行不行呀，别急后面有，这里只是递归的终止条件而已）
    // 3. 如果root1->val 不等于 root2->val 那么说明肯定不翻转等价了 返回 false
    // 4. 如果根节点值相等，那么我们就分别再判断两种情况：
    //     4.1 两个左子树和两个右子树相应的都是翻转等价 ok
    //     4.2 root1 左子树和 root2 右子树等价并且 root1 的右子树和 root2 的左子树翻转等价也 ok
    // 5. 每一步的逻辑都是1~4 递归
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2) return true;
        if (!root1 && root2 || root1 && !root2) return false;
        if (root1->val != root2->val)
        {
            return false;
        } else
        {
            bool flag1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            bool flag2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            return flag1 || flag2;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
