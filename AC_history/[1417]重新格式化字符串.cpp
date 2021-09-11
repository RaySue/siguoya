// 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。
//
// 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。 
//
// 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。 
//
// 
//
// 示例 1： 
//
// 输入：s = "a0b1c2"
//输出："0a1b2c"
//解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
// 
//
// 示例 2： 
//
// 输入：s = "leetcode"
//输出：""
//解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
// 
//
// 示例 3： 
//
// 输入：s = "1229857369"
//输出：""
//解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
// 
//
// 示例 4： 
//
// 输入：s = "covid2019"
//输出："c2o0v1i9d"
// 
//
// 示例 5： 
//
// 输入：s = "ab123"
//输出："1a2b3"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 500 
// s 仅由小写英文字母和/或数字组成。 
// 
// Related Topics 字符串 
// 👍 10 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 思路：
    // 思路很简单，没想到写了这么多代码，有点不讲码德了，我大意了啊
    // 方法一：
    // 计数排序的思想
    // 初始化：数字计数桶(isdigit) numBucket, 字母计数桶 charBucket
    //
    string reformat(string s)
    {
        vector<int> numBucket(10);
        vector<int> charBucket(26);
        int nNum = 0, nChar = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                numBucket[s[i] - '0']++;
                nNum++;
            } else
            {
                charBucket[s[i] - 'a']++;
                nChar++;
            }
        }
        if (abs(nNum - nChar) > 1) return "";

        int p = 0;
        if (nNum > nChar)
        {
            for (int i = 0; i < s.size(); i += 2)
            {
                while (p < 10 && numBucket[p] == 0) p++;
                s[i] = p + '0';
                numBucket[p]--;
            }
            p = 0;
            for (int i = 1; i < s.size(); i += 2)
            {
                while (p < 26 && charBucket[p] == 0) p++;
                s[i] = p + 'a';
                charBucket[p]--;
            }
        } else
        {
            for (int i = 0; i < s.size(); i += 2)
            {
                while (p < 26 && charBucket[p] == 0) p++;
                s[i] = p + 'a';
                charBucket[p]--;
            }
            p = 0;
            for (int i = 1; i < s.size(); i += 2)
            {
                while (p < 10 && numBucket[p] == 0) p++;
                s[i] = p + '0';
                numBucket[p]--;
            }
        }
        return s;
    }

    // 方法二：
    // 分离+重组思想
    string reformat(string s)
    {
        string ans = "", tmp1 = "", tmp2 = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i])) tmp1 += s[i];
            else tmp2 += s[i];
        }

        int n1 = tmp1.size(), n2 = tmp2.size();
        if (abs(n1 - n2) > 1) return ans;

        int n = min(n1, n2);
        for (int i = 0; i < n; ++i)
            ans = ans + tmp1[i] + tmp2[i];
        if (n1 > n2) ans += tmp1.back();  // 加到尾部
        else if (n1 < n2) ans = tmp2.back() + ans;  // 加到头部

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
