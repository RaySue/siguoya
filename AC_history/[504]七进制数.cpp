//给定一个整数，将其转化为7进制，并以字符串形式输出。 
//
// 示例 1: 
//
// 
//输入: 100
//输出: "202"
// 
//
// 示例 2: 
//
// 
//输入: -7
//输出: "-10"
// 
//
// 注意: 输入范围是 [-1e7, 1e7] 。 
// 👍 65 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 非常注意负数
    // 取模运算得到每个位置的值
    // 除法运算，类似于右移运算
    string convertToBase7(int num)
    {
        string ans = "";
        bool sign = false;
        if (num < 0)
        {
            num = -num;
            sign = true;
        }
        while (num != 0)
        {
//            ans += to_string(num % 7);
            ans = to_string(num % 7) + ans;
            num = num / 7;
        }
        ans += sign ? "-" : "";
//        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
