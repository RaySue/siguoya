//给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。 
//
// 示例1: 
//
// 
//输入: 5
//输出: True
//解释: 1 * 1 + 2 * 2 = 5
// 
//
// 
//
// 示例2: 
//
// 
//输入: 3
//输出: False
// 
// Related Topics 数学 
// 👍 141 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 2021.02.07
    // 双指针启发式搜索，注意大数问题即可
    bool judgeSquareSum(int c)
    {
        if (c == 0) return true;
        int maxVal = floor(sqrt(c));
        if (maxVal * maxVal == c) return true;
        int left = 1, right = maxVal;
        while(left <= right)
        {
            long long int cur = 1L * left * left + right * right;
            if (cur > c) right --;
            else if (cur < c) left ++;
            else return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
