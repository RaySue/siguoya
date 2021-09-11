// 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
//
// 如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。 
//
// 我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。 
//
// 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。 
//
// 
//
// 示例 1： 
// 
//
// 输入：root = [1,2,3,4], x = 4, y = 3
//输出：false
// 
//
// 示例 2： 
// 
//
// 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
//输出：true
// 
//
// 示例 3： 
//
// 
//
// 输入：root = [1,2,3,null,4], x = 2, y = 3
//输出：false 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点数介于 2 到 100 之间。 
// 每个节点的值都是唯一的、范围为 1 到 100 的整数。 
// 
//
// 
// Related Topics 树 广度优先搜索 
// 👍 114 👎 0


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
public:

    // 2021.01.05 一刷 广度优先搜索
    // 提交 7 次才过，这绝对不是一道特别简单的题
    // 思路：
    // 广度优先搜索，类似于层序遍历
    // 1. depth 大于 1 的时候，也就是第3层开始，才可能出现堂兄弟节点
    // 2. 堂兄弟节点一定出现在同一层中
    // 3. 要盘点堂兄弟节点不能在同一个节点下，所以 nullptr 节点也需要保存，用于占位
    // 4. 如果一层出现了两个节点分别等于x和y，要判断两个节点是否相邻，如果不相邻一定是兄弟节点，如果相邻那么较小位置的节点不能是偶数才行
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (!root) return false;
        queue < TreeNode * > q;
        q.push(root);
        int depth = 1;
        int idx = -1;
        int idy = -1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur == nullptr) continue;
                if (depth > 2)
                {
                    if (cur->val == x) idx = i;
                    if (cur->val == y) idy = i;
                    if ((idx >= 0 && cur->val == y) || (idy >= 0 && cur->val == x))
                    {
                        if (abs(idx - idy) > 1)
                            return true;
                        else
                        {
                            idx = min(idx, idy);
                            return idx % 2 != 0;
                        }
                    }
                }
                if (cur->left) q.push(cur->left);
                else q.push(nullptr);
                if (cur->right) q.push(cur->right);
                else q.push(nullptr);
            }
            if (idx >= 0 || idy >= 0) return false;
            depth++;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
