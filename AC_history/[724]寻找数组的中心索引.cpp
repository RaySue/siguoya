//给定一个整数类型的数组 nums，请编写一个能够返回数组 “中心索引” 的方法。 
//
// 我们是这样定义数组 中心索引 的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。 
//
// 如果数组不存在中心索引，那么我们应该返回 -1。
//
// 重点：如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
//
// 
//
// 示例 1： 
//
// 输入：
//nums = [1, 7, 3, 6, 5, 6]
//       [1, 8,11,17,22,28]
//输出：3
//解释：
//索引 3 (nums[3] = 6) 的左侧数之和 (1 + 7 + 3 = 11)，与右侧数之和 (5 + 6 = 11) 相等。
//同时, 3 也是第一个符合要求的中心索引。
// 
//
// 示例 2： 
//
// 输入：
//nums = [1, 2, 3]
//输出：-1
//解释：
//数组中不存在满足此条件的中心索引。 
//
// 
//
// 说明： 
//
// 
// nums 的长度范围为 [0, 10000]。 
// 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。 
// 
// Related Topics 数组 
// 👍 231 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 1. 先对数组进行累加
    // 2. 先判断首位置是否是中心
    // 3. 然后计算 "当前值 - 前一个值" 是否等于 "末尾值 - 当前值"，如果等于那么返回当前位置
    // 4. 判断尾位置是否是中心
    // 5. 如果没有则返回-1
    int pivotIndex(vector<int>& nums)
    {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return 0;
        int end = nums.back(); // 记录尾位置的值
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }
        // 因为你在循环中就遗漏了首尾的位置，即首尾位置可能是中心索引会遗漏
        if (nums.back() - nums[0] == 0) return 0; // 除去首位置，剩余的做和为0，说明首位置是中心索引
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i - 1] == nums.back() - nums[i]) return i;
        }
        if (nums.back() - end == 0) return nums.size() - 1; // 除去尾位置，剩余的做和为0，说明尾位置是中心索引
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
