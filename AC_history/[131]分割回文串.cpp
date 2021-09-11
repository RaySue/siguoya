//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回 s 所有可能的分割方案。 
//
// 示例: 
// [1, 2, 3]
//  1 1 1     3
//  1 2
//  2 1
//  3
// 输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//] 
// Related Topics 回溯算法 
// 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 1. 由于是回文串分割，那么就少不了回文串的判断，先写个回文串的判断， isPalindrome(string &s, int l, int r)
    // 2. 然后开始设计回溯函数backtrack，终止条件可以为当前位置变量 cur 恰好等于 s，说明已经分割完成，如果cur大于s.size（）（剪枝1）
    // 3. 选择集合是[1,2,3,...,s.size()]，每次从中选择一个长度，然后cur位置到新选择的长度得到的子串需要判断是否是回文串 （剪枝2）
    // 4. 由于cur是累加的，所以能够保证顺序，相当于组合数中的 start 变量
    // 刚看到这个问题的时候我头脑中想到的模型是硬币找零给定[1,2,3], 找到所有能够等于 3 的组合数，这个问题需要start变量来控制顺序
    // [1,2,3] 1 1 1; 1 2; 2 1; 3

    vector <vector<string>> ans;

    bool isPalindrome(string &s, int l, int r)
    {
        r += l - 1;
        while (l < r)
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int cur, vector<string> path)
    {
        if (cur == s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); ++i)
        {
            if (cur + i > s.size()) continue;
            if (!isPalindrome(s, cur, i)) continue;
            path.push_back(s.substr(cur, i));
            cur += i;
            backtrack(s, cur, path);
            cur -= i;
            path.pop_back();
        }
    }

    vector <vector<string>> partition(string s)
    {
        vector<string> path;
        backtrack(s, 0, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
