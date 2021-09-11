// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可
// 能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
//
// 
//
// 示例 1: 
//               单个翻译 + 一次两个翻译 （剩下的数字递归）
// 输入: 12258   1 2 2 5 8；12 2 5 8；1 22 5 8；1 2 25 8； 12 25 8；
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi" 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 231 
// 
// 👍 160 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 91 解码方法
    int translateNum1(int num)
    {
        string src = to_string(num);
        if (src.size() < 2) return 1;
        vector<int> dp(src.size());
        // dp 初始化
        dp[0] = 1;
        dp[1] = (src.substr(0, 2) <= "25" && src.substr(0, 2) >= "10") ? 2:1;
        for (int i = 2; i < src.size(); ++i)
        {
            dp[i] = dp[i - 1];
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10")
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }

    int translateNum(int num)
    {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
