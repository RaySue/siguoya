//给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符： 
//
// 
// 'A' : Absent，缺勤 
// 'L' : Late，迟到 
// 'P' : Present，到场 
// 
//
// 如果一个学生的出勤记录中不超过一个 'A'(缺勤) 并且 不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
//
// 你需要根据这个学生的出勤记录判断他是否会被奖赏。 
//
// 示例 1: 
//
// 输入: "PPALLP"
//输出: True
// 
//
// 示例 2: 
//
// 输入: "PPALLL"
//输出: False
// 
// Related Topics 字符串 
// 👍 56 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 1. 先理解题意，如果出现2个A说明不会被奖赏，简单计数
    // 2. 如果出现 LLL 也不会被奖赏，可以使用find("LLL")
    // 3. 其余都返回true

    bool checkRecord(string s)
    {
        int aCount = 0, lCount = 0;
        int flag = false;
        for (auto c:s)
        {
            if (c == 'L' && !flag)
            {
                flag = true;
                continue;
            }
            if (c == 'A')
            {
                flag = false;
                aCount++;
                lCount = 0;
            } else if (c == 'P')
            {
                flag = false;
                lCount = 0;
            } else if (c == 'L' && flag)
            {
                lCount++;
                if (lCount > 1) return false;
            }
        }
        return aCount < 2 && lCount < 2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
