//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
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
// 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这
//个问题。 
//
// 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。 
// Related Topics 树 设计 
// 👍 432 👎 0


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

// 一刷 2020.12.25
// 思路，利用前序遍历就可以实现，比较简单
// 1. 前序遍历，序列化生成字符串，利用 ',' 分开，用 "#" 来记录空指针的位置，如果没有空指针记录，
// 就需要前序和中序等来恢复二叉树了，或者前序和后序遍历
// 2. 解析字符串到 vector<string>， 从 string 到 int，要注意负数的情况
// 3. 前序遍历，反序列化生成一颗树，利用 idx 从前向后来获取 tmp 中的值
class Codec
{
private:
    char SEP = ',';
    string null = "#";

private:
    // 写反序列化的前序遍历
    // 生成二叉树，一定是在函数里面初始化 root
    // 最终返回 root，因为是递归所以root节点在第一个函数栈中保存了
    TreeNode *preOrder(vector <string> &tmp, int &idx)
    {
        if (tmp[idx] == null) return nullptr;
        TreeNode *root = new TreeNode(stringToInt(tmp[idx]));
        idx++;
        root->left = preOrder(tmp, idx);
        idx++;
        root->right = preOrder(tmp, idx);
        return root;
    }

    void preOrder(TreeNode *root, string &res)
    {
        if (!root)
        {
            res += null;
            res += SEP;
            return;
        }
        res += to_string(root->val);
        res += SEP;
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    void deserialize(string &data, vector <string> &res)
    {
        string tmp = "";
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] == SEP)
            {
                res.push_back(tmp);
                tmp.clear();
            } else
            {
                tmp += data[i];
            }
        }
    }

    // 注意负数的情况
    int stringToInt(string &s)
    {
        int res = 0;
        int sign = 1;
        if (s[0] == '-') sign = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '-') continue;
            res = res * 10 + s[i] - '0';
        }
        return res * sign;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        preOrder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
//        cout << data << endl;
        vector <string> tmp;
        deserialize(data, tmp);
        int idx = 0;
        TreeNode *root = preOrder(tmp, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
