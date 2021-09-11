//给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。 
//
// 
//
// 示例 1: 
//
// 输入: [1,2,0]
//输出: 3
// 
//
// 示例 2: 
//
// 输入: [3,4,-1,1]
//输出: 2
// 
//
// 示例 3: 
//
// 输入: [7,8,9,11,12]
//输出: 1
// 
//
// 
//
// 提示： 
//
// 你的算法的时间复杂度应为O(n)，并且只能使用**常数级别的额外空间**。
// Related Topics 数组 
// 👍 896 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // O(n) 级别的额外空间，即利用 hash_map
    // 1. 把所有的正数放入到 hash_map 并计算正数，出现的个数，
    // 2. 从 1 开始一直到nums.size() 如果有没出现的就返回 最小没出现的正数
    // 3. 否则就返回最大的整数 + 1
    int firstMissingPositive(vector<int>& nums)
    {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
