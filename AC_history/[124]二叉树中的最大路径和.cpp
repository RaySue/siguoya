// 给定一个非空二叉树，返回其最大路径和。
//
// 本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。
// 该路径至少包含一个节点，且不一定经过根节点。
//
// 
//
// 示例 1： 
//
// 输入：[1,2,3]
//
//       1
//      / \
//     2   3
//
//输出：6
// 
//
// 示例 2： 
//
// 输入：[-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//输出：42 
// Related Topics 树 深度优先搜索 
// 👍 688 👎 0


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


    //  遍历子树有以下三种情况：

    //  路径停在当前子树的根节点，收益：root->val
    //  走入左子树，最大收益：max(root->val, root->val + dfs(root->left))
    //  走入右子树，最大收益：max(root->val, root->val + dfs(root->right))
    //
    //  规避掉 负数 之后，节点的最大收益是 root->val + left + right
    //
    //  遍历获取最大收益 max(maxSum, root->val + left + right);

    // 抽象思考递归问题：
    // 先考虑一个由三个节点构成的二叉树
    //      1
    //     / \
    //   -1   2
    // 很明显最大路径和就是 1->2
    // 我们对这个过程计算一下
    // 1. 计算每个节点的最大值（从左节点或右节点选择一个最大值相加），如果小于0，那么就是设置为 0 ：
    //      3 = max(1, 1 + max(0, 2))
    //     / \
    //    0   2
    // 2. 遍历求和，题目让你求和，没让你给出路径，所以相加即可，那有人说了， 你这样做，如果 左子树下面有更大的值呢？
    //
    // 再考虑一个三层的子树

    /*  1. 先计算最大和的路径，每个节点都选取其左右子树的最大值(root->val + max(left, right))，
     *  那么备选路径自然就有了，左二图所示，花括号表示选择的路径
     *
     *  2. 在遍历求取最大和的过程中，通过一个全局变量来维护一个最大值即可，每个节点的最大值为 root->val + left + right
     *
     *  上面提到的 left 和 right 是左右子树的最优值（root->val + max(left, right）
     *
     *        1                      12(19)
     *      /  \                   {    }
     *    -1    2            (12) 7     11(18)
     *   / \   / \              /  }    /   }
     *  5  8  7   9        (5)5  (8)8  7(7) 9(9)
     *
     *  这个就复杂了，一眼看不出结果的，但是我们还是自底向上先计算每个节点的最大路径和
     *
     */

    int ans = INT_MIN;

    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
