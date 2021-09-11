// 给定一个二叉树，它的每个结点都存放着一个整数值。
//
// 找出路径和等于给定数值的路径总数。 
//
// 路径**不需要从根节点开始，也不需要在叶子节点结束**，但是**路径方向必须是向下的（只能从父节点到子节点）**。
//
// 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。 
//
// 示例： 
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3.  -3 -> 11
// 
// Related Topics 树 
// 👍 680 👎 0


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

// 思路明显就是前序遍历
// 对每个节点都进行 pathSum 即可
class Solution {
public:

    // 一刷 2020.12.14
    //
    // 思路：把每个节点都作为头结点进行前序遍历，因为方向必须是自上而下的
    // 如果出现做和等于sum的就+1，每个节点进行一次前序遍历

    // 二刷 2020.12.25
    // 清晰的记得一刷的时候，这道题是自己做出来的，但是面试的时候，如果你提前特别熟悉，和你现场去思考，呈现出来的状态是天壤之别的
    // 无他，但手熟尔

//    int ans = 0;
//
//    void preOrder(TreeNode* root, int path, int sum)
//    {
//        if (!root) return;
//        path += root->val;
//        if (path == sum) ans++;
//        preOrder(root->left, path, sum);
//        preOrder(root->right, path, sum);
//    }
//
//    int pathSum(TreeNode* root, int sum)
//    {
//        if (!root) return ans;
//        preOrder(root, 0, sum);
//        pathSum(root->left, sum);
//        pathSum(root->right, sum);
//        return ans;
//    }


    int count = 0;

    void preOrder(TreeNode* root, int sum)
    {
        if (!root) return;
        sum -= root->val;
        if (sum == 0) count++;
        preOrder(root->left, sum);
        preOrder(root->right, sum);
    }

    int pathSum(TreeNode* root, int sum)
    {
        if (!root) return count;
        preOrder(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return count;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
