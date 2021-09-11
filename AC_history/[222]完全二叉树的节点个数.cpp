//给出一个完全二叉树，求出该树的节点个数。 
//
// 说明： 
//
// 完全二叉树的定义如下：
// 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为
// 第 h 层，则该层包含 1~ 2h 个节点。
//
// 示例: 
//
// 输入: 
//    1                1
//   / \
//  2   3              2
// / \  /
//4  5 6               4
//
//输出: 6 
// Related Topics 树 二分查找 
// 👍 302 👎 0


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
    // 这是针对普通二叉树的做法，没有利用到完全二叉树的特点
    int count = 0;
    int countNodes1(TreeNode* root)
    {
        if (!root) return 0;
        count ++;
        countNodes(root->left);
        countNodes(root->right);
        return count;
    }

    // 利用完全二叉树的特点的解法，和树的深度挂钩，如果树的深度为n的满二叉树，那么节点数目就是 2^n - 1
    // 由此我们来计算左右节点的高度
    // 1. 如果左右节点的高度相同（怕右边不满）， 那么说明左子树是全满的，节点个数就是 2^n - 1，再单独计算右节点的个数，相加即可
    // 2. 如果高度不相同，一定是左边高，那么说明右子树是全满的，节点个数也是 2^n - 1， 再单独计算左子树节点的个数
    int getMaxDepth(TreeNode* root)
    {
        if (!root) return 0;
        return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
    }

    int countNodes(TreeNode* root)
    {
        int cur = 0;
        if(!root) return cur;
        int left = getMaxDepth(root->left);
        int right = getMaxDepth(root->right);
        if (left == right)
        {
            cur += 1 << left;  // 根节点不加1，那么这里就用位运算，记住，如果想用pow的2的几次方的时候记得使用位移运算
            cur += countNodes(root->right);
        } else {
            cur += 1 << right;
            cur += countNodes(root->left);
        }
        return cur;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
