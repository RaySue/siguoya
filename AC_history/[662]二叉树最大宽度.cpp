//给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节
//点为空。 
//
// 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。 
//
// 示例 1: 
//
// 
//输入: 
//
//           1
//         /   \
//        3     2
//       / \     \  
//      5   3     9 
//
//输出: 4
//解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
// 
//
// 示例 2: 
//
// 
//输入: 
//
//          1
//         /  
//        3    
//       / \       
//      5   3     
//
//输出: 2
//解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
// 
//
// 示例 3: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2 
//       /        
//      5      
//
//输出: 2
//解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
// 
//
// 示例 4: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2
//       /     \  
//      5       9
//     /         \
//    6           7
//输出: 8
//解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
// 
//
// 注意: 答案在32位有符号整数的表示范围内。 
// Related Topics 树 
// 👍 163 👎 0


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

    // 思路：
    // 利用 BFS ~~记录每一层的 节点 和 空节点 到 vector<TreeNode*> 中~~
    // 满二叉树每层的节点个数是 2^(n-1)
    // 可以记录每层非空的开始节点和结束节点的位置，做差就是这层的宽度
    // 遍历取最大值
    // TLE
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root) return 0;
        queue < TreeNode * > q;
        q.push(root);
        int ret = 0;
        while (!q.empty())
        {
            int sz = q.size();
            bool flag = false;
            int start = sz, end = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur == nullptr)
                {
                    q.push(nullptr);
                    q.push(nullptr);
                } else
                {
                    if (start == sz) start = i; else end = i;
                    flag = true;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            ret = max(ret, end - start + 1);
            if (!flag) break;
        }
        return ret;
    }

    //
    int widthOfBinaryTree(TreeNode *root)
    {

    }

};
//leetcode submit region end(Prohibit modification and deletion)
