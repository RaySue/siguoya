//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 深度优先搜索 递归 字符串 回溯算法 
// 👍 1079 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<string> ans;

    void backtrack(string &digits, int depth, string &path)
    {
        if (depth == digits.size())
        {
            ans.push_back(path);
            return;
        }
        string choices = letterMap(digits[depth]);

        for (int i = 0; i < choices.size(); ++i)
        {
            path.push_back(choices[i]);
            backtrack(digits, depth + 1, path);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        string path = "";
        backtrack(digits, 0, path);
        return ans;
    }


private:

    /**
     *   put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
     */
    string letterMap(char a)
    {
        switch (a)
        {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default:
                return "";
        }
        return "";
    }
};
//leetcode submit region end(Prohibit modification and deletion)
