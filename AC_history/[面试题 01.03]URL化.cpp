// URL化。编写一种方法，将字符串中的空格全部替换为%20。
// 假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
// （注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
//
// 
//
// 示例 1： 
//
// 
//输入："Mr John Smith    ", 13
//输出："Mr%20John%20Smith"
// 
//
// 示例 2： 
//
// 
//输入："               ", 5
//输出："%20%20%20%20%20"
// 
//
// 
//
// 提示： 
//
// 
// 字符串长度在 [0, 500000] 范围内。 
// 
// Related Topics 字符串 
// 👍 25 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2020.12.19
    // 思路：
    // 遍历 从 0 到 length
    // 如果遇到空格就 对 ans 添加 "%20"
    // 如果 i > S.size() 对 ans 添加 "%20"
    string replaceSpaces(string S, int length)
    {
        string ans = "";
        for (int i = 0; i < length; ++i)
        {
            if (S[i] == ' ' || i >= S.size()) ans += "%20";
            else ans += S[i];
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
