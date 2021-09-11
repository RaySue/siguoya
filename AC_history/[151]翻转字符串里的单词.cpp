//给定一个字符串，逐个翻转字符串中的每个单词。 
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
// 
//
// 进阶： 
//
// 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。 
// Related Topics 字符串 
// 👍 216 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 遇到" "有两种情况，一种需要略过，一种需要对之前的字符串入库
    // 注意" "的情况
    string reverseWords(string s)
    {
        string ans;
        if (s.empty()) return ans;
        vector <string> buffer;
        bool flag = true;
        string tmp = "";
        for (auto a:s)
        {
            if (a == ' ' && flag)
            {
                continue;
            } else if (a == ' ')
            {
                buffer.push_back(tmp);
                tmp = "";
                flag = true;
            } else
            {
                flag = false;
                if (a != ' ') tmp.push_back(a);
            }
        }
        if (!tmp.empty()) buffer.push_back(tmp);
        if (buffer.empty()) return "";
        reverse(buffer.begin(), buffer.end());
        for (auto b :buffer)
        {
            ans += b;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
