//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1530 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // "()"
    // "(())" "()()"
    // Wrong Answer
    vector <string> generateParenthesis(string s, bool flag = false)
    {
        vector <string> ret;
        ret.push_back("()" + s);
        if (flag)
        {
            ret.push_back(s + "()");
        }
        ret.push_back("(" + s + ")");
        return ret;
    }

    vector <string> generateParenthesis1(int n)
    {
        vector <string> ans;
        if (n == 0) return ans;
        ans = {"()"};
        vector <string> buffer = {"()"};
        for (int i = 2; i <= n; ++i)
        {
            ans.clear();
            for (int j = 0; j < buffer.size(); ++j)
            {
                vector <string> tmp = (j != 0) ? generateParenthesis(buffer[j], true) : generateParenthesis(buffer[j],
                                                                                                            false);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            }
            buffer = ans;
        }
        return ans;
    }


    // -------------------------------------------------------------

    vector <string> ans;

    vector <string> generateParenthesis(int n)
    {
        string path;
        backtrack(path, 0, 0, n);
        return ans;
    }

    // 如果左括号数量不大于 n，我们可以放一个左括号。
    // 如果右括号数量小于左括号的数量，我们可以放一个右括号。
    // 最终的结果一定是 n 个左括号，和 n 个右括号
    // 每次有两个选择，或者是左括号，或者是右括号，但是右括号必须要出现在左括号的后面才行
    // 可使用 isValid 进行有效括号判断，然后转化为 左括号 一定在右括号之后，而且左括号的数量一定是 n，右括号的数量一定等于左括号的数量
    void backtrack(string &path, int left, int right, int n)
    {
        if (path.size() == n * 2)
        {
            ans.push_back(path);
            return;
        }
        if (left < n)
        {
            path.push_back('(');
            backtrack(path, left + 1, right, n);
            path.pop_back();
        }
        if (right < left)
        {
            path.push_back(')');
            backtrack(path, left, right + 1, n);
            path.pop_back();
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)
