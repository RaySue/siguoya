//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。 
//
// 假定 BST 有如下定义： 
//
// 
// 结点左子树中所含结点的值小于等于当前结点的值 
// 结点右子树中所含结点的值大于等于当前结点的值 
// 左子树和右子树都是二叉搜索树 
// 
//
// 例如： 
//给定 BST [1,null,2,2], 
//
//    1
//    \
//     2
//    /
//   2
// 
//
// 返回[2]. 
//
// 提示：如果众数超过1个，不需考虑输出顺序 
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内） 
// Related Topics 树 
// 👍 181 👎 0


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


    unordered_map<int,int> mp;

    void traverse(TreeNode* root)
    {
        if (!root) return;
        mp[root->val] ++;
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> findMode(TreeNode* root)
    {
        vector<int> ans;
        traverse(root);
        unordered_map<int,int>::iterator iter;
        int maxTime = 0;
        for (iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (iter->second > maxTime)
            {
                maxTime = iter->second;
            }
        }
        for (iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (iter->second == maxTime)
            {
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
