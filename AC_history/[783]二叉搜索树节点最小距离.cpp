//给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。 
//
// 
//
// 示例： 
//
// 输入: root = [4,2,6,1,3,null,null]
//输出: 1
//解释:
//注意，root是树节点对象(TreeNode object)，而不是数组。
//
//给定的树 [4,2,6,1,3,null,null] 可表示为下图:
//
//          4
//        /   \
//      2      6
//     / \    
//    1   3  
//
//最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。 
//
// 
//
// 注意： 
//
// 
// 二叉树的大小范围在 2 到 100。 
// 二叉树总是有效的，每个节点的值都是整数，且不重复。 
// 本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 
//相同 
// 
// Related Topics 树 递归 
// 👍 101 👎 0


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

    // 方法一，可以中序遍历得到数组，然后再做差分

    // 方法二，保存前一个节点的值 prev
    int prev = 0, ans = INT_MAX;
    bool flag = false;
    void Inorder(TreeNode *root)
    {
        if (root == NULL) return;
        Inorder(root->left);
        // 若前置节点值不为空，则计算当前最小距离
        if (flag) ans = min(ans, root->val - prev);
//        cout << root->val << " " << prev << " " << ans << endl;
        // 更新前置节点值
        prev = root->val;
        flag = true;
        Inorder(root->right);
    }

    int minDiffInBST(TreeNode *root)
    {
        Inorder(root);
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
