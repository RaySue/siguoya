//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。 
//
// 
//
// 示例： 
//
// 输入："Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
// 
//
// 
//
// 提示： 
//
// 
// 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。 
// 
// Related Topics 字符串 
// 👍 253 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 1. 对整个字符串倒序遍历
    // 2. buffer 缓存每个字符
    // 3. 遇到空格后就把 buffer 存到ans中
    // O(N)
    // O(k)
    string reverseWords(string s)
    {
        string ans = "";
        string buffer = "";
        for (int i = s.size() - 1; i >= 0 ; --i)
        {
            if (s[i] == ' ' && !buffer.empty())
            {
                ans = buffer + " " + ans;  // 倒序相加
                buffer.clear();
            } else if (s[i] != ' ')
            {
                buffer += s[i];
            }
        }
        if (!tmp.empty()) ans = tmp + " " + ans;
        ans.pop_back();
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
