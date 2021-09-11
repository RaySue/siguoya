//给一个 非空 字符串 s 和一个单词缩写 abbr ，判断这个缩写是否可以是给定单词的缩写。 
//
// 字符串 "word" 的所有有效缩写为： 
//
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1",
// "w1r1", "1o2", "2r1", "3d", "w3", "4"] 
//
// 注意单词 "word" 的所有有效缩写仅包含以上这些。任何其他的字符串都不是 "word" 的有效缩写。 
//
// 注意: 
//假设字符串 s 仅包含小写字母且 abbr 只包含小写字母和数字。 
//
// 示例 1: 
//
// 给定 s = "internationalization", abbr = "i12iz4n":
//
//函数返回 true.
// 
//
// 
//
// 示例 2: 
//
// 给定 s = "apple", abbr = "a2e":
//
//函数返回 false.
// 
//
// 
// Related Topics 字符串 
// 👍 22 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 1. 以 0 开头的数字是无效的
    // 2. nums = nums * 10 + next;
    // 3. ptr += nums
    bool validWordAbbreviation(string word, string abbr)
    {
        int ptr = 0;
        int nums = 0;
        if (abbr.size() > word.size()) return false;
        for (int i = 0; i < abbr.size(); ++i)
        {
            if ('0' <= abbr[i] && abbr[i] <= '9')
            {
                if (nums == 0 && abbr[i] == '0') return false;  // 以 0 开头是无效的
                // 一个变量累计字符串变为整数用法
                nums = nums * 10 + (abbr[i] - '0');
                if (i == abbr.size() - 1 && nums == word.size() - ptr) return true;
            } else {
                ptr += nums;
                if (word[ptr] != abbr[i]) return false;
                nums = 0;
                ptr ++;
            }
        }
        if (ptr != word.size()) return false;
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
