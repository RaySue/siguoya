//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。
// 返回一个包含所有深度的链表的数组。
//
// 
//
// 示例： 
//
// 输入：[1,2,3,4,5,null,7,8]
//
//        1
//       /  \ 
//      2    3
//     / \    \ 
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]
// 
// Related Topics 树 广度优先搜索 
// 👍 29 👎 0


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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    // 一刷 2020.12.20
    // 经典的广度优先搜索的应用场景
    // 值得注意的是这里使用了链表，我们需要对链表进行赋值，这就需要head节点和执行添加的ptr指针
    vector<ListNode*> listOfDepth(TreeNode* tree)
    {
        vector<ListNode*> ans;
        if (!tree) return ans;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty())
        {
            int size = q.size();
            ListNode *dummayHead = new ListNode(-1);
            ListNode *ptr = dummayHead;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();q.pop();
                ptr->next = new ListNode(cur->val);
                ptr = ptr->next;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(dummayHead->next);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
