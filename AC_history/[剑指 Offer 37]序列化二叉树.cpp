//请实现两个函数，分别用来序列化和反序列化二叉树。 
//
// 示例: 
//
// 你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]" 
//
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-b
//inary-tree/ 
// Related Topics 树 设计 
// 👍 94 👎 0


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

// 二刷 2021.01.13
// 先记录一下感受，做这个题之前，我觉得这个题给我的感觉很复杂，有思路，但没有特别清晰的思路
// 边做边找，后来又参考之前写的题解，解决了这个题目，完成了二刷，二刷的时候，明显代码和思路都比一刷要简洁一些
// 对我而言的难点分析
// 1. 反序列化（字符串 -> 二叉树）的时候，我总想着在外面定义一个全局TreeNode*变量， 然后对这个节点进行赋值，实际上直接返回TreeNode*的函数，
// 更方便且更好理解
// 2. string2num，这个函数很简单，但是我总忘记考虑负数的情况

// 思路整理：
// encode -> string
// 1. 先利用前序遍历，将 root 存入到 string 中，空指针存为 nullptr，节点间用 " " 来隔开（方便后面使用 stringstream）
// decode -> TreeNode*
// 2. 先将string 变为 vector<string> stringstream
// 3. string2num， 还原节点值，这里一定要注意负数的情况
// 4. 前序遍历，生成 TreeNode*
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string enCodeStr = "";
        preOrder(root, enCodeStr);
//        cout << enCodeStr << endl;
        return enCodeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector <string> values;
        stringstream ss(data);
        string item;
//        while (ss >> tmp)  // 默认是对空格分割
        while (getline(ss, item, '_'))
        {
            values.push_back(item);
        }
        int idx = 0;
        TreeNode *root = preOrder(values, idx);
        return root;
    }


private:
    void preOrder(TreeNode *root, string &enCodeStr)
    {
        if (!root)
        {
            enCodeStr += "#";
            enCodeStr += "_";
            return;
        }

        enCodeStr += to_string(root->val);
        enCodeStr += "_";

        preOrder(root->left, enCodeStr);
        preOrder(root->right, enCodeStr);
    }


    // 注意负数的情况
    int string2num(string &data)
    {
        int ret = 0;
        bool sign = true;
        if (data[0] == '-') sign = false;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] == '-') continue;
            ret = ret * 10 + (data[i] - '0');
        }
        return sign ? ret : -ret;
    }

    // decoder
    // 由于是递归，首个递归栈已经存储了 root 的位置，所以直接返回 root 即可
    TreeNode *preOrder(vector <string> &data, int &idx)
    {
        if (idx >= data.size() || data[idx] == "#") return nullptr;
        TreeNode *root = new TreeNode(string2num(data[idx]));
        idx++;
        root->left = preOrder(data, idx);
        idx++;
        root->right = preOrder(data, idx);
        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
