// 给定一个有序整数数组，
// 元素各不相同且按升序排列，
// 编写一个算法，创建一棵高度最小的二叉搜索树。
// 示例: 给定有序数组: [-10,-3,0,5,9],
// 一个可能的答案是：[0,-3,9,-10,null,5]，
// 它可以表示下面这个高度平衡二叉搜索树：
//            0
//          / \
//        -3  9
//        /   /
//      -10  5
//
// Related Topics 树 深度优先搜索
// 👍 65 👎 0


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

//    TreeNode *root;
    // 唯一的误区就是不能使用全局变量的 root
    // 因为全局变量的 root
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end - start == 0) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty()) return nullptr;
        TreeNode* root = sortedArrayToBST(nums, 0, nums.size());
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
