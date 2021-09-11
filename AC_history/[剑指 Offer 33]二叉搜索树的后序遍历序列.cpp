// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
//
// 
// 左 根 右
// 左 右 根
// 参考以下这颗二叉搜索树： 
//
//          5
//        /  \
//       2    7
//      / \  / \
//     1  3 6  8
//    /
//   0
// [0,1,2,3,5,6,7,8]
// [0,1,3,2,6,8,7,5]
// 示例 1： 
//
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
// 👍 146 👎 0



//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.07 和 LC 255 号题是一个题目，不过是反着的
    // 验证一个前序和后序遍历序列来判断复合二叉搜索树，就利用单调栈来解决
    // [0,1,3,2,6,8,7,5]
    // 左 右 根


    // 后续遍历序列 二刷 2020.01.13
    // 左子树->右子树->根节点
    // 逆过来就是：
    // 根节点->右子树->左子树
    // 我们判断其是否符合 BST 的时候，主要判断，其左右子树和根节点，是否符合 BST
    // 这里 根节点一定是 小于 右子树的
    // 当 左子树 出现的时候，我们要让根节点作为最大值，剩下的为左子树的值，不可以大于根节点
    // 因此我们可以使用单调栈 来解决，逆序遍历
    // 左子树 右子树 根节点,
    // 右子树的值都比根节点大，所以一旦遇到比根节点小的值我就认为是左子树开始了，所有的左子树都需要小于根节点的值
    bool verifyPostorder(vector<int> &postorder)
    {
        int rootVal = INT_MAX;
        stack<int> sta;
        for (int i = postorder.size() - 1; i >= 0; --i)
        {
            if (postorder[i] >= rootVal) return false;
            while (!sta.empty() && postorder[i] < postorder[sta.top()])
            {
                rootVal = postorder[sta.top()];
                sta.pop();
            }
            sta.push(i);
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
