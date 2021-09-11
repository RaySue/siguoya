//给定一棵二叉搜索树，请找出其中第k大的节点。 
//
// 
//
// 示例 1: 
//
// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4 
//
// 示例 2: 
//
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4 
//
// 
//
// 限制： 
//
// 1 ≤ k ≤ 二叉搜索树元素个数 
// Related Topics 树 
// 👍 93 👎 0


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


    // 方法二 利用 count 来记录当前是第几大的值
    // 中序遍历（左->根->右）得到的是升序排列的结果
    // 逆中序遍历（右->根->左）得到的则是降序排列的结果
    // 所以，根据题意，这里我们直接从大向小找即可
    int count = 0, ans;

    void reverseInOrderTraverse(TreeNode* root, int k)
    {
        if (!root) return;
        reverseInOrderTraverse(root->right, k);
        // 下到最下边的最右边，拿到最大值，然后是次大值，...
        if (++count == k)
        {
            ans = root->val;
            return;
        }
        reverseInOrderTraverse(root->left, k);
    }

    int kthLargest(TreeNode* root, int k)
    {
        if (!root) return -1;
        reverseInOrderTraverse(root, k);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
