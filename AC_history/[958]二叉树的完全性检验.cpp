//给定一个二叉树，确定它是否是一个完全二叉树。 
//
// 百度百科中对完全二叉树的定义如下： 
//
// 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：
//第 h 层可能包含 1~ 2h 个节点。） 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[1,2,3,4,5,6]
//输出：true
//解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
// 
//
// 示例 2： 
//
// 
//
// 输入：[1,2,3,4,5,null,7]
//输出：false
//解释：值为 7 的结点没有尽可能靠向左侧。
// 
//
// 
//
// 提示： 
//
// 
// 树中将会有 1 到 100 个结点。 
// 
// Related Topics 树 
// 👍 98 👎 0


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

    // 一刷 2021.01.09
    // 先搞清楚什么是完全二叉树？
    // base 方法是利用 BFS
    // 满二叉树的第 n 层的节点数是 2^(n-1)
    // 这个题目不是一个特别简单的题目
    // 思路，完全二叉树要满足下面两个条件：
    // A. 要保证的是除了最后一层，其余的层都是满二叉树
    // B. 需要最后一层是靠左边紧挨着的
    // 利用 二叉树的 层序遍历
    // 1. 记录每层的 空指针 的个数，如果空指针后面出现的值，违反了 B，那么返回 false
    // 2. 记录每层的 非空节点的 个数，如果某层的非空节点的个数不等于 2^(n-1)，那么下一层如果有非空节点，就违反了 A
    bool isCompleteTree1(TreeNode *root)
    {
        if (!root) return true;
        queue < TreeNode * > q;
        q.push(root);
        int depth = 1;
        bool flag = false;
        while (!q.empty())
        {
            int sz = q.size();
            int nullCount = 0; // 记录空指针的个数，如果某个节点前出现的空指针，一定不是完全二叉树
            int nodeCount = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (!cur)
                {
                    nullCount++;
                    continue;
                } else
                {
                    if (nullCount > 0 || flag) return false;
                    nodeCount++;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
            if (nodeCount != pow(2, depth - 1)) flag = true;  // 如果第 n 层的节点数不是 2^(n-1) 需要看是否是最后一层
            depth++;
        }
        return true;
    }

    // 利用 BFS 简化思路，确实是一道简单的题，想复杂了
    // 思路：
    // 记录空指针是否出现，如果出现过，两种情况：
    // 1. 可能是上层有空指针，在下层被判断到，那么就违反了完全性的前 n-1 层是满二叉树的情况
    // 2. 可能是同一层的前面有空指针，那么也是违反了完全性
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *cur = q.front();q.pop();
            if (!cur)
            {
                flag = true;
                continue;
            } else if (flag) return false;
            q.push(cur->left);
            q.push(cur->right);
        }
        return true;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
