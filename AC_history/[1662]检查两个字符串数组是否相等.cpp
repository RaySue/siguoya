//给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。 
//
// 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
//输出：true
//解释：
//word1 表示的字符串为 "ab" + "c" -> "abc"
//word2 表示的字符串为 "a" + "bc" -> "abc"
//两个字符串相同，返回 true 
//
// 示例 2： 
//
// 
//输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word1.length, word2.length <= 103 
// 1 <= word1[i].length, word2[i].length <= 103 
// 1 <= sum(word1[i].length), sum(word2[i].length) <= 103 
// word1[i] 和 word2[i] 由小写字母组成 
// 
// Related Topics 字符串 
// 👍 4 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool arrayStringsAreEqual1(vector <string> &word1, vector <string> &word2)
    {
        string s1 = "";
        string s2 = "";
        for (string w1:word1) s1 += w1;
        for (string w2:word2) s2 += w2;
        return s1 == s2;
    }

    bool arrayStringsAreEqual(vector <string> &word1, vector <string> &word2)
    {
        // [] 表示捕获
        // ->string 表示返回类型
        // {} 里面是函数体
        // () 表示调用
        return [&word1]()->string{string a = "";for (string w:word1)a += w;return a;}()
               ==
               [&word2]()->string{string a = "";for (string w:word2)a += w;return a;}();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
