//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// 👍 51 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 1. 先统计空格的个数 count
    // 2. resize s 为 s.size() + count * 2
    // 3. 双指针从后向前添加
    string replaceSpace(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                ans += "%20";
            } else {
                ans += s[i];
            }
        }
        return ans;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
