//有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。 
//
// 示例1:

//             qwe  qwe qew weq
//             qqe  qqe qeq qeq
//  输入：S = "qqe"
// 输出：["eqq","qeq","qqe"]
// 
//
// 示例2: 
//
//  输入：S = "ab"
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
// 👍 32 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.06
    vector <string> ans;

    void backtrack(string &S, vector<bool> isVis, int depth, string &path)
    {
        if (depth == S.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < S.size(); ++i)
        {
            // 利用 isVis 保证顺序来去重复
            if (i > 0 && S[i] == S[i - 1] && !isVis[i-1]) continue;
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
        sort(S.begin(), S.end());
        vector<bool> isVis(S.size());
        string path;
        backtrack(S, isVis, 0, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
