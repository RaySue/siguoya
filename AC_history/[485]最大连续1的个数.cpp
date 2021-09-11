//给定一个二进制数组， 计算其中最大连续1的个数。 
//
// 示例 1: 
//
// 
//输入: [1,1,0,1,1,1]
//输出: 3
//解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
// 
//
// 注意： 
//
// 
// 输入的数组只包含 0 和1。 
// 输入数组的长度是正整数，且不超过 10,000。 
// 
// Related Topics 数组 
// 👍 136 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int maxConsecutiveOnes = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                if (count > maxConsecutiveOnes) maxConsecutiveOnes = count;
                count = 0;
                continue;
            }
            count ++;
        }
        // 解决最后遇不到 0 的问题
        return max(count, maxConsecutiveOnes);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
