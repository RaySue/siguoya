//给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。 
//
// 如果两个结点在同一行和列，那么顺序则为 从左到右。 
//
// 示例 1： 
//
// 输入: [3,9,20,null,null,15,7]
//
//   3
//  /\
// /  \
//9   20
//    /\
//   /  \
//  15   7 
//
//输出:
//
//[
//  [9],
//  [3,15],
//  [20],
//  [7]
//]
// 
//
// 示例 2: 
//
// 输入: [3,9,8,4,0,1,7]
//
//            3                  [#,#,3,#,#]
//           / \                 [#,9,#,8,#]
//          /   \               [4,#,0,1,#,7]
//         9     8
//        /\    /\
//       /  \  /  \
//      4    01    7
// 1 - 1
// 2 - 3
// 3 - 5
// 4 - 7
// n - 2n-1
//输出:
//
//[
//  [4],
//  [9],
//  [3,0,1],
//  [8],
//  [7]
//]
// 
//
// 示例 3: 
//
// 输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）
//
//     3
//    /\
//   /  \
//   9   8
//  /\  /\
// /  \/  \
// 4  01   7
//    /\
//   /  \
//   5   2
//
//输出:
//
//[
//  [4],
//  [9,5],
//  [3,0,1],
//  [8,2],
//  [7]
//]
// 
// Related Topics 深度优先搜索 广度优先搜索 
// 👍 71 👎 0


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

    // 一刷 2021.01.15
    // 思路：
    // 基于 BFS 的层序遍历
    // 但需要添加一些逻辑，让不同层的节点能够匹配上，那就是对root节点赋值为 0
    // 左节点 -1， 右节点 +1
    // 根据节点对应的值 放入到 tree map 中并利用 tree map 来保证从小到大的顺序
    // 最终将 tree map 插入到返回结果中
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        vector<vector<int> > ret;
        if (!root) return ret;
        map<int, vector<int>> treeMap;
        queue<TreeNode*> treeQ;
        queue<int> rank;
        treeQ.push(root);
        rank.push(0);
        while(!treeQ.empty())
        {
            TreeNode *curNode = treeQ.front();treeQ.pop();
            int curRank = rank.front();rank.pop();
            treeMap[curRank].push_back(curNode->val);
            if (curNode->left)
            {
                treeQ.push(curNode->left);
                rank.push(curRank - 1);
            }
            if (curNode->right)
            {
                treeQ.push(curNode->right);
                rank.push(curRank + 1);
            }
        }
        for (auto [k, v] : treeMap) ret.push_back(v);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
