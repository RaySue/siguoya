// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。
//
// 
//
// 示例 1： 
//
// 输入: "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 说明： 
//
// 
// 无空格字符构成一个单词。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
//
//
// 注意：此题对比原题有改动 
// Related Topics 字符串 
// 👍 51 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 思路：
    // 遍历每一个字符，如果字符是空，而且 wordFirst 为 false，那么 continue
    // 如果 wordFirst 为 true，那么就向 ans中添加新的字符，注意了，要么你在给定的s后面添加一个" "，要不就循环结束后处理剩下的一个word
    // 由于每次 ans 添加 word 需要加空格，所以第一次添加的空格会保存到最后，需要pop_back()掉
    string reverseWords1(string s)
    {
        string ans = "";
        string word = "";
        bool wordFirst = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && !wordFirst) continue;
            else if (s[i] == ' ' && wordFirst)
            {
                ans = word + " " + ans;
                word.clear();
                wordFirst = false;
            } else
            {
                word += s[i];
                wordFirst = true;
            }
        }
        if (!word.empty()) ans = word + " " + ans;
        ans.pop_back();
        return ans;
    }

    // 直接利用 stringstream，哪有那么多闹心事啊
    string reverseWords(string s)
    {
        stringstream ss(s);
        string tmp;
        string ans;
        while (ss >> tmp)
        {
            ans = tmp + " " + ans;
        }
        ans.pop_back();
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
