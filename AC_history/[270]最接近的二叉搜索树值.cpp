//给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。 
//
// 注意： 
//
// 
// 给定的目标值 target 是一个浮点数 
// 题目保证在该二叉搜索树中只会存在一个最接近目标值的数 
// 
//
// 示例： 
//
// 输入: root = [4,2,5,1,3]，目标值 target = 3.714286
//
//    4
//   / \
//  2   5
// / \
//1   3
//
//输出: 4
// 
// Related Topics 树 二分查找 
// 👍 40 👎 0


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

    // 方法一： 利用中序遍历把二叉搜索树转为有序数组，然后线性搜索或二分搜索



    // 利用 BST 这个条件进行二分查找-> dfs
    int closestValue2(TreeNode *root, double target)
    {
        double d = fabs(root->val - target * 1.0);
        if (d == 0) return root->val;
        int l, r;
//        cout << root->val << endl;
        if (root->val > target)
        {
            if (root->left)
            {
                l = closestValue(root->left, target);
                double ld = abs(l * 1.0 - target);
                return ld < d ? l : root->val;

            } else
            {
                return root->val;
            }
        } else
        {
            if (root->right)
            {
                r = closestValue(root->right, target);
                double rd = abs(r * 1.0 - target);
                return rd < d ? r : root->val;
            } else
            {
                return root->val;
            }
        }
    }

    // 不使用递归，使用迭代
    int closestValue3(TreeNode *root, double target)
    {
        int val, closest = root->val;
        while (root)
        {
            val = root->val;
            closest = abs(val * 1.0 - target) < abs(closest * 1.0 - target) ? val : closest;
            root = target < val ? root->left : root->right;
        }
        return closest;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
