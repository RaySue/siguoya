//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上
//被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 2： 
//
// 输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
// Related Topics 动态规划 
// 👍 1225 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 三刷 2020.12.30
    // [1,2,3,1]
    // dp[i] 抢到第 i 家最大的收益
    // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    // dp数组的意义 dp数组中的每个值都是在当前只有那么多房子的情况下的最好的选择
    // 比如数组的初始化本身就是一种当前状态下的最好的选择dp[0] = nums[0];当只有一间房子可以偷的时候，最好的选择就是偷这间房子
    // dp[1] = max(nums[0],nums[1]);当有两间房子可以偷的时候，因为题意， 偷了两间连续的房子就会被抓，所以只能选择一件最贵的房间偷了
    // dp[2] = max(dp[1],dp[0] + nums[2]);当有三间房子可以偷的情况下，总共只有两种选择，一种是选择第二间，一种是选择第一间和第三件，这个时候肯定选择这两种情况中最大 的一种
    // dp[3] = max(dp[2], dp[1] + nums[3]);当有四间房子可以偷的情况下，可以在前面三间 的选择下，对第四间房子是否进行选择进行判断；
    int rob1(vector<int> &nums)
    {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }

    // 模型是 [1,2,2] 取 0、2 位置还是取 1 位置
    // 动态规划 取0、2位置和1位置中较大的，所以要更新 first 和 second
    // 去掉空间复杂度的解法
    int rob2(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int first = 0;
        int second = 0;
        int third = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            third = max(first + nums[i], second);
            first = second;
            second = third;
        }
        return third;

    }

    // 好理解的解法
//    int rob(vector<int>& nums)
//    {
//        int sumOdd = 0;
//        int sumEven = 0;
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i % 2 == 0)
//            {
//                sumEven += nums[i];
//                sumEven = max(sumOdd, sumEven);
//            }
//            else
//            {
//                sumOdd += nums[i];
//                sumOdd = max(sumOdd, sumEven);
//            }
//        }
//        return max(sumOdd, sumEven);
//    }

};
//leetcode submit region end(Prohibit modification and deletion)
