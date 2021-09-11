//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。 
//
// 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。 
//
// 示例 1: 
//
// 
//输入: 二叉树: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /    
//  4     
//
//输出: "1(2(4))(3)"
//
//解释: 原本将是“1(2(4)())(3())”，
//在你省略所有不必要的空括号对之后，
//它将是“1(2(4))(3)”。
// 
//
// 示例 2: 
//
// 
//输入: 二叉树: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \  
//      4 
//
//输出: "1(2()(4))(3)"
//
//解释: 和第一个示例相似，
//除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
// 
// Related Topics 树 字符串 
// 👍 160 👎 0


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

// 不带null
//       1
//     /   \
//    2     3
//   /
//  4

// 带null
//       1
//     /   \
//    2     3
//     \
//      4

class Solution
{
public:

    // 思路：
    // 切记不要涉及 left->val 或 right->val 否则很复杂
    // 讨论当前位置的情况：
    // 1. 当前为空，那么返回""
    // 2. 当前的左子树和右子树为空，那么返回 "t->val"
    // 3. 如果当前的左子树不为空，右子树为空，那么返回 "t->val" + "(" + tree2str(t->left) + ")";
    // 4. 如果当前的左子树为空，右子树不是空，那么返回 "t->val" + "()(" + tree2str(t->right) + ")";
    // 5. 都不为空，那么就返回 "t->val" + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    // end
    string tree2str(TreeNode *t)
    {
        if (!t) return "";
        if (!t->left && !t->right) return to_string(t->val);
        if (t->left && !t->right) return to_string(t->val) + "(" + tree2str(t->left) + ")";
        if (!t->left && t->right) return to_string(t->val) + "()(" + tree2str(t->right) + ")";
        return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};
//leetcode submit region end(Prohibit modification and deletion)
