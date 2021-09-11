// 给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。
// 设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。
// 注意，路径不一定非得从二叉树的
// 根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。
//
// 示例: 
// 给定如下二叉树，以及目标和 sum = 22，
//
//               5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// 3
//解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7] 
//
// 提示： 
//
// 
// 节点总数 <= 10000 
// 
// Related Topics 树 深度优先搜索 
// 👍 41 👎 0


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

    // 二刷 2020.12.21

    // 知道做过相似的题，上一次做出来，这次竟然没做出来，不知道什么原因
    // 思路非常简单
    // 我们遍历整棵树，然后对每个节点都做到任意位置的路径总和看是否等于目标值

    int ans = 0;

    // target 什么时候加引用，什么时候不加引用呢？
    // 如果加了引用，说明每次都会去修改一个位置的值，函数出栈入栈都不影响改值，
    // 所以对于 target -= root->val; 要显示的回溯 target += root->val;
    // 如果不加引用，那么每次函数出栈的时候值就恢复到上一个栈的值了
    void preOrder1(TreeNode* root, int &target)
    {
        if (!root) return;
        target -= root->val;
        if (target == 0) ans++;
        preOrder(root->left, target);
        preOrder(root->right, target);
        target += root->val;
    }
    // target 不加引用， 减少一步显示的回溯计算，速度快了很多
    void preOrder(TreeNode* root, int target)
    {
        if (!root) return;
        target -= root->val;
        if (target == 0) ans++;
        preOrder(root->left, target);
        preOrder(root->right, target);
//        target += root->val;
    }


    int pathSum(TreeNode* root, int sum)
    {
        if (!root) return ans;
        preOrder(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
