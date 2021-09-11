//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法 
// 👍 140 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    vector <string> ans;

    void backtrack(string &s, vector<bool> &isVis, string &path)
    {
        if (path.size() == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (isVis[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !isVis[i - 1]) continue;
            path.push_back(s[i]);
            isVis[i] = true;
            backtrack(s, isVis, path);
            isVis[i] = false;
            path.pop_back();
        }
    }


    vector <string> permutation(string s)
    {
        sort(s.begin(), s.end());   // 排序 排序 排序
        string path;
        vector<bool> isVis(s.size());
        backtrack(s, isVis, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
