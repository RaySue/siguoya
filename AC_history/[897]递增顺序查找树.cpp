//给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。 
//
// 
//
// 示例 ： 
//
// 输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \ 
//1        7   9
//
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9  
//
// 
//
// 提示： 
//
// 
// 给定树中的结点数介于 1 和 100 之间。 
// 每个结点都有一个从 0 到 1000 范围内的唯一整数值。 
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 131 👎 0


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
private:

    void inOrderTraverse(TreeNode *root, vector<int> &data)
    {
        if (!root) return;
        inOrderTraverse(root->left, data);
        data.push_back(root->val);
        inOrderTraverse(root->right, data);
    }

public:

    // 一刷 2021.01.14
    // 这个题目是非常接近链表相关操作的一道题目
    // 朴素解法：
    // 对 root 中序遍历，然后存成一个 vector<int>
    // 然后利用 vector<int> 生成一颗树
    // Time: O(N)
    // Space: O(N)
    TreeNode *increasingBST1(TreeNode *root)
    {
        vector<int> data;
        inOrderTraverse(root, data);
        // 二叉树添加节点，类似链表一样，我们需要一个 dummyHead
        TreeNode *dummyHead = new TreeNode(-1);
        TreeNode *p = dummyHead;
        for (int i = 0; i < data.size(); ++i)
        {
            p->left = nullptr;
            p->right = new TreeNode(data[i]);
            p = p->right;
        }
        return dummyHead->right;
    }

    // 不需要额外数组存储的解法，思想来自于链表逆序的思想：
    // pre 指向 nullptr，cur->next = pre， pre = cur, 一步一步的完成链表的逆序
    // 中序遍历的顺序是：左子树，根节点，右子树
    // 逆过来就是：右子树，根节点，左子树
    // 递归左子树之后，在让 root->left 为 nullptr，
    // 考虑一个两层满二叉树，我们先遍历右子树得到最大值，然后逆序找到根节点（次大值），最后遍历左子树，得到最小值，
    // 遍历之后, root 还是原来的 root，所以避免节外生枝，将左子树砍掉 = nullptr
    //
    TreeNode* pre = nullptr;

    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->right);
        root->right = pre;
        pre = root;
        dfs(root->left);
        root->left = nullptr;
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        dfs(root);
        return pre;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
