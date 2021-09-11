// 给定一个单词，你需要判断单词的大写使用是否正确。
//
// 我们定义，在以下情况时，单词的大写用法是正确的： 
//
// 
// 全部字母都是大写，比如"USA"。 
// 单词中所有字母都不是大写，比如"leetcode"。 
// 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。 
// 
//
// 否则，我们定义这个单词没有正确使用大写字母。 
//
// 示例 1: 
//
// 
//输入: "USA"
//输出: True
// 
//
// 示例 2: 
//
// 
//输入: "FlaG"
//输出: False
// 
//
// 注意: 输入是由大写和小写拉丁字母组成的非空单词。 
// Related Topics 字符串 
// 👍 107 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路： (注意大小写的判断是带 = )
    // 记录大写字母和小写字母的个数
    // 如果最后小写字母或大写字母的个数和单词长度相同，那么返回true
    // 如果大写字母只有一个且出现在了首位置，那么返回true
    // 其余返回false
    // Time: O(N)
    // Space: O(1)
    bool detectCapitalUse(string word)
    {
        int upperCount = 0;
        int lowerCount = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                upperCount++;
            else
                lowerCount++;
        }
        if (lowerCount == word.size() || upperCount == word.size()) return true;
        else if ((word[0] >= 'A' && word[0] <= 'Z') && upperCount == 1) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
