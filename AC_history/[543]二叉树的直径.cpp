// 给定一棵二叉树，你需要计算它的直径长度。
// 一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
// 这条路径可能穿过也可能不穿过根结点。
//
// 
//
// 示例 : 
//给定二叉树 
//
//           1
//         / \
//        2   3
//       / \     
//      4   5    
// 
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。 
//
// 
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。 
// Related Topics 树 
// 👍 526 👎 0


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

    // 我的思路：
    // 做完这个题目，我突然觉得二叉树的题真的好简单
    // 你能对二叉树做什么操作，求最大深度，最小深度，求一个节点是否在一个树中，前中后序遍历，层序遍历...
    // 然后你面对的题目怎么转换到你已知的操作中，比如这道题
    // 如果直接问你，那个节点的左右子树的最大深度之和最大，那么这个题还是个题吗？听懂掌声！
    int maxDiameter = 0;
    unordered_map<TreeNode*, int> memory;

    int getMaxDepth(TreeNode* root, unordered_map<TreeNode*, int> &memory)
    {
        if (!root) return 0;
        if (memory.count(root)) return memory[root];
        memory[root] = max(getMaxDepth(root->left, memory), getMaxDepth(root->right, memory)) + 1;
        return memory[root];
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        if(!root) return 0;
        int leftDepth = getMaxDepth(root->left, memory);
        int rightDepth = getMaxDepth(root->right, memory);
        if (leftDepth + rightDepth > maxDiameter) maxDiameter = leftDepth + rightDepth;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDiameter;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
