//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“
//房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。 
//
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。 
//
// [2,1,3,null,4]
//    2
//   / \
//  1   3
//   \
//    4
// 示例 1: 
//
// 输入: [3,2,3,null,3,null,1]
//
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//
//输出: 7 
//解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7. 
//
// 示例 2: 
//
// 输入: [3,4,5,1,3,null,1]
//
//     3
//    / \
//   4   5
//  / \   \ 
// 1   3   1
//
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
// 
// Related Topics 树 深度优先搜索 
// 👍 633 👎 0


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

    // 二刷 2021.01.23
    // 突然有个想法，就是能不能利用层序遍历，把每层求和，然后在利用打家劫舍的动态规划来解决这个问题
    // 但是实际上并不是按层来抢的，所以这个思路行不通
    int rob_error(TreeNode* root)
    {
        if (!root) return 0;
        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            int tmpSum = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* cur = q.front();q.pop();
                tmpSum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            nums.push_back(tmpSum);
        }

        int a = 0, b = 0, c = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }


    // 思路:
    // 如果抢根节点，就可以抢孙子节点 g
    // 如果不抢根节点，就抢孩子子节点 c
    // return max(g, c);
//    int rob(TreeNode *root, unordered_map<TreeNode *, int> &memory)
//    {
//        int ans = 0;
//        if (!root) return ans;
//        if (memory.count(root)) return memory[root];
//        // 抢根，抢孙
//        int g = root->val;
//        if (root->left) g += (rob(root->left->left, memory) + rob(root->left->right, memory));
//        if (root->right) g += (rob(root->right->left, memory) + rob(root->right->right, memory));
//        // 抢孩子
//        int c = rob(root->left, memory) + rob(root->right, memory);
//        ans = max(g, c);
//        memory[root] = ans;
//        return ans;
//    }

    int rob2(TreeNode *root)
    {
        if (!root) return 0;
        unordered_map<TreeNode *, int> memory;
        return rob(root, memory);
    }


    int rob(TreeNode *root, unordered_map<TreeNode*, int> &mem)
    {
        if (!root) return 0;
        if (mem.count(root)) return mem[root];
        int g = root->val;
        if (root->left)
        {
            g += rob(root->left->left, mem);
            g += rob(root->left->right, mem);
        }
        if (root->right)
        {
            g += rob(root->right->left, mem);
            g += rob(root->right->right, mem);
        }

        int c = rob(root->left, mem) + rob(root->right, mem);
        mem[root] = max(g, c);
        return mem[root];
    }

    int rob(TreeNode *root)
    {
        if (!root) return 0;
        unordered_map<TreeNode*, int> mem;
        return rob(root, mem);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
