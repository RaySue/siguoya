//给你一个单词序列，判断其是否形成了一个有效的单词方块。 
//
// 有效的单词方块是指此由单词序列组成的文字方块的 第 k 行 和 第 k 列 (0 ≤ k < max(行数, 列数)) 所显示的字符串完全相同。 
//
// 注意： 
//
// 
// 给定的单词数大于等于 1 且不超过 500。 
// 单词长度大于等于 1 且不超过 500。 
// 每个单词只包含小写英文字母 a-z。 
// 
//
// 
//
// 示例 1： 
//
// 输入：
//[
//  "abcd",
//  "bnrt",
//  "crmy",
//  "dtye"
//]
//
//输出：
//true
//
//解释：
//第 1 行和第 1 列都是 "abcd"。
//第 2 行和第 2 列都是 "bnrt"。
//第 3 行和第 3 列都是 "crmy"。
//第 4 行和第 4 列都是 "dtye"。
//
//因此，这是一个有效的单词方块。
// 
//
// 
//
// 示例 2： 
//
// 输入：
//[
//  "abcd",
//  "bnrt",
//  "crm",
//  "dt"
//]
//
//输出：
//true
//
//解释：
//第 1 行和第 1 列都是 "abcd"。
//第 2 行和第 2 列都是 "bnrt"。
//第 3 行和第 3 列都是 "crm"。
//第 4 行和第 4 列都是 "dt"。
//
//因此，这是一个有效的单词方块。
// 
//
// 
//
// 示例 3： 
//
// 输入：
//[
//  "ball",
//  "area",
//  "read",
//  "lady"
//]
//
//输出：
//false
//
//解释：
//第 3 行是 "read" ，然而第 3 列是 "lead"。
//
//因此，这 不是 一个有效的单词方块。
// 
//
// 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    bool validWordSquare1(vector <string> &words)
    {
        if (words.empty()) return true;
        if (words.size() != words[0].size()) return false;
        for (int i = 0; i < words.size(); ++i)
        {
            string col = "";
            for (int j = 0; j < words[i].size(); ++j)
            {
                if (words[j].size() <= i) return false;
                col += words[j][i];
            }
            if (words[i] != col) return false;
        }
        return true;
    }

    // 只需要对比 word[i][j] 和 word[j][i] 是否相等即可
    // 注意长度不同的情况，可能会导致 下标越界
    bool validWordSquare2(vector <string> &words)
    {
        if (words.empty()) return true;
        if (words.size() != words[0].size()) return false;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                if (words[j].size() <= i || words[j][i] != words[i][j]) return false;
            }
        }
        return true;
    }


    bool validWordSquare(vector <string> &words)
    {
        int m = words.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (j >= m || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
