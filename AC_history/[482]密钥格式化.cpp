//有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。 
//
// 给你一个数字 K，请你重新格式化字符串，使每个分组恰好包含 K 个字符。特别地，第一个分组包含的字符个数必须小于等于 K，
// 但至少要包含 1 个字符。两个分
// 组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。
//
// 给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。 
//
// 
//
// 示例 1： 
//
// 输入：S = "5F3Z-2e-9-w", K = 4
//输出："5F3Z-2E9W"
//解释：字符串 S 被分成了两个部分，每部分 4 个字符；
//     注意，两个额外的破折号需要删掉。
// 
//
// 示例 2： 
//
// 输入：S = "2-5g-3-J", K = 2
//输出："2-5G-3J"
//解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
// 
//
// 
//
// 提示: 
//
// 
// S 的长度可能很长，请按需分配大小。K 为正整数。 
// S 只包含字母数字（a-z，A-Z，0-9）以及破折号'-' 
// S 非空 
// 
//
// 
// 👍 51 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string licenseKeyFormatting1(string S, int K)
    {
        string ans = "";
        string sClean;
        // 清除 '-'，然后对所有的小写字母转为大写
        for (auto s:S)
        {
            if (s == '-') continue;
            // 小写字母转大写字母
            if (s >= 97) s = (char) (s - 32);
            sClean.push_back(s);
        }
        // 先将头部处理好
        int first = sClean.size() % K;
        if (first != 0)
        {
            ans += sClean.substr(0, first);
            ans += '-';
        }
        if (first == sClean.size()) ans.pop_back();  //如果余数恰好等于字符串总长度，则不用加 -
        // 把剩下的字符都加入到ans中即可
        int count = 0;
        for (int i = first; i < sClean.size(); ++i)
        {
            if (count == K)
            {
                ans += '-';
                count = 0;
            }
            ans.push_back(sClean[i]);
            count++;
        }
        return ans;
    }

    // 倒骑驴
    // 1. 先将元素push到stack去除符号‘-’
    // 2. stack中元素弹出到ans中，并判断弹是否插入‘-’
    // 3. 翻转ans得到结果

    string licenseKeyFormatting(string S, int K)
    {
        stack<char> tStack;
        string ans;
        int cnt = 0;
        for (auto c : S)
            if (c != '-')
                tStack.push(c);
        while (!tStack.empty())
        {
            ans.push_back(toupper(tStack.top()));
            cnt++;
            tStack.pop();
            if (tStack.size() != 0 && cnt % K == 0)
                ans.push_back('-');
        }
        cout << cnt << endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
