//给你一个字符串 S，请你删去其中的所有元音字母（ 'a'，'e'，'i'，'o'，'u'），并返回这个新字符串。 
//
// 
//
// 示例 1： 
//
// 输入："leetcodeisacommunityforcoders"
//输出："ltcdscmmntyfrcdrs"
// 
//
// 示例 2： 
//
// 输入："aeiou"
//输出：""
// 
//
// 
//
// 提示： 
//
// 
// S 仅由小写英文字母组成。 
// 1 <= S.length <= 1000 
// 
// Related Topics 字符串 
// 👍 10 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool isVowel(char c)
    {
        switch (c)
        {
            case 'a':
                return true;
            case 'e':
                return true;
            case 'i':
                return true;
            case 'o':
                return true;
            case 'u':
                return true;
            default:
                return false;
        }
    }

    string removeVowels(string S)
    {
        string ans = "";
        for (char c:S)
        {
            if (isVowel(c)) continue;
            ans += c;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
