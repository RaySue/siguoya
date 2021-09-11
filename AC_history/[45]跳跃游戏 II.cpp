// 给定一个非负整数数组，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。 
//
// 示例: 
//
// 输入: [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 说明: 
//
// 假设你总是可以到达数组的最后一个位置。 
// Related Topics 贪心算法 数组 
// 👍 760 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 这道题的思路就是确定每步的 最大覆盖范围，利用最小的步数到达最大的覆盖范围
    // 通过第一步的最大覆盖范围内，找到第一步覆盖范围下的 下一步的最大覆盖范围
    // 当下标 i 到达最大覆盖范围了，那么就 ans++，
    // 注意当终点在覆盖范围内，那么就不增加 ans 了， 否则增加ans，这里我们把范围缩小到 < nums.size() - 1
    // 然后不考虑边界，只要到达最大覆盖范围就 ans++，这样即便是在 边界的前一个位置 ans++ 也保证能够到达终点
    int jump(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int count = 0;
        int cur = 0;
        int next = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            next = max(next, i + nums[i]);
            if (i == nums.size() - 1) break;  // 只要到达最后一个位置就可以
            if (i == cur)
            {
                count++;
                cur = next;
            }
        }
        return count;
    }

//    bool jump(vector<int>& nums)
//    {
//
//    }

};
//leetcode submit region end(Prohibit modification and deletion)
