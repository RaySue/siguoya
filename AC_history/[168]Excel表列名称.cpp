//给定一个正整数，返回它在 Excel 表中相对应的列名称。 
//
// 例如， 
//
//     1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
//    ...
// 
//
// 示例 1: 
//
// 输入: 1
//输出: "A"
// 
//
// 示例 2: 
//
// 输入: 28
//输出: "AB"
// 
//
// 示例 3: 
//
// 输入: 701
//输出: "ZY"
// 
// Related Topics 数学 
// 👍 261 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 这个题真的很欠打，我的思路总有漏洞
    // 说到底还是理解的有问题，并不是进制数的问题
    // 应该先在纸上运算一些数，就知道具体的规律了，然后在coding
    // 先取余数，然后把余数减去，再除以26，如果结果大于等于26，那么在取余数，循环
    string convertToTitle(int n)
    {
        string ans;
        if (n == 0) return ans;
        unordered_map<int, char> match;
        match[0] = 'Z';
        for (int i = 1; i < 27; ++i)
        {
            match[i] = (char)(i - 1 + 'A');
        }
        char tail = match[n % 26];
        n = n % 26 == 0 ? n - 26 :n - (n % 26);
        while(n >= 26)
        {
            n = n / 26;
            ans += match[n % 26];
            n = n % 26 == 0 ? n - 26 :n - (n % 26);
        }
        reverse(ans.begin(), ans.end());
        ans.push_back(tail);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
