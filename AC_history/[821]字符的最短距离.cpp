//
// 给定一个字符串 S 和一个字符 C。
//
// 返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
//
// 示例 1: 
//
// 
// 输入: S = "loveleetcode", C = 'e'
// 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
// 
//
// 说明: 
//
// 
// 字符串 S 的长度范围为 [1, 10000]。 
// C 是一个单字符，且保证是字符串 S 里的字符。 
// S 和 C 中的所有字母均为小写字母。 
// 
// 👍 165 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 前向： i - prev
    // 后向： prev - i
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> ret(S.size(), INT_MAX);
        int prev = S.size();
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == C)
            {
                ret[i] = 0;
                prev = i;
            } else {
                if (prev == S.size()) continue;
                ret[i] = min(ret[i], i - prev);
            }
        }
        prev = S.size();
        for (int i = S.size() - 1; i >= 0; --i)
        {
            if (S[i] == C)
            {
                prev = i;
            } else {
                if (prev == S.size()) continue;
                ret[i] = min(ret[i], prev - i);
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
