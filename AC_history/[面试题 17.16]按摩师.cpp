// 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
// 在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩
// 师找到最优的预约集合（总预约时间最长），返回总的分钟数。
//
// 注意：本题相对原题稍作改动 
//
// 
//
// 示例 1： 
//
// 输入： [1,2,3,1]
//输出： 4
//解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
// 
//
// 示例 2： 
//
// 输入： [2,7,9,3,1]
//输出： 12
//解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
// 
//
// 示例 3： 
//
// 输入： [2,1,4,5,3,1,1,3]
//输出： 12
//解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
// 
// Related Topics 动态规划 
// 👍 159 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2020.12.29 打家劫舍
    // 1. 视角 不在 nums[i] 而在 nums[i-1]
    // 2. dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1])
    // [1,5,3]
    // 我认为的答案，被[2,1,1,2]给破了
    // dp[i] = max(dp[i - 2] + nums[i], dp[i -1]);
    // 发现视角不对，我这个视角直接到当下，肯定是不行的，要把视角向后方，即操作的是 nums[i - 1], 上帝视角
    // 再来俯视 [2,1,1,2]
    //        [0,2,2,3,4]

    // 三刷，综合理解了一下 打家劫舍 问题，还是要从头开始推理出动态规划方程的
    // 1. 定义 dp 数组的状态
    // 2. dp 数组状态初始化
    // 3. 构建动态转移方程
    // dp[0] = nums[0]
    // dp[1] = max(nums[0], nums[1])
    // dp[2] = max(nums[0] + nums[2] , nums[1])
    // dp[3] = max(dp[1] + nums[3], dp[2])
    int massage1(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }

    ///////////////////////////////////////////////////////////////
    // 去掉 vector 的空间占用
    int massage(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int first = nums[0], second = max(nums[0], nums[1]), third = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            third = max(first + nums[i], second);
            first = second;
            second = third;
        }
        return third;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
