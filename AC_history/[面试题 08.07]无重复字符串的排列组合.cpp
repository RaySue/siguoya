//无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。 
//
// 示例1: 
//
// 
// 输入：S = "qwe"
// 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
// 
//
// 示例2: 
//
// 
// 输入：S = "ab"
// 输出：["ab", "ba"]
// 
//
// 提示: 
//
// 
// 字符都是英文字母。 
// 字符串长度在[1, 9]之间。 
// 
// Related Topics 回溯算法 
// 👍 35 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    vector <string> ans;

    // 一刷 2021.01.06
    // start + 1 适用于 一长串中找 固定 子长度的所有字符串 比如 qwe 中找到 无重复的 2个元素的组合
    // isVis 适用于组合问题
    void backtrack(string &S, vector<bool> isVis, int depth, string &path)
    {
        if (depth == S.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < S.size(); ++i)
        {
            if (isVis[i]) continue;
            path.push_back(S[i]);
            isVis[i] = true;
            backtrack(S, isVis, depth + 1, path);
            isVis[i] = false;
            path.pop_back();
        }
    }

    vector <string> permutation(string S)
    {
        string path = "";
        vector<bool> isVis(S.size());
        backtrack(S, isVis, 0, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
