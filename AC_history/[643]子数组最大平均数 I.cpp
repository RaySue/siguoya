//给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。 
//
// 示例 1: 
//
// 输入: [1,12,-5,-6,50,3], k = 4
//输出: 12.75
//解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
// 
//
// 
//
// 注意: 
//
// 
// 1 <= k <= n <= 30,000。 
// 所给数据范围 [-10,000，10,000]。 
// 
// Related Topics 数组 
// 👍 115 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 滑窗法
    // 滑窗法要点：
    // 1. 初始化 l，r，window
    // 2. 先移动r，在移动l，r - l 是窗口的size
    // 3. 滑窗法复合条件的记录一般在内层while
    double findMaxAverage(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        double window = 0.0, ans = INT_MIN;
        while (r < nums.size())
        {
            window += nums[r];
            ++r;
            while (r - l >= k)
            {
                if (window / k > ans) ans = window / k;
                window -= nums[l];
                ++l;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
