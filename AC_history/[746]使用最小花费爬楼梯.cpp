// 数组的每个索引作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。
//
// 每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续 爬一个阶梯 或者 爬两个阶梯 。
////
// 您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。 
//
// 示例 1: 
//
// 输入: cost = [10, 15, 20]
//             [10, 15, 30,15]
//输出: 15
//解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
// 
//
// 示例 2: 
//
// 输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//             [1, 100, 2, 3, 3, 103, 4, 5, 104, 6]
//输出: 6
//解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
// 
//
// 注意： 
//
// 
// cost 的长度将会在 [2, 1000]。 
// 每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999]。 
// 
// Related Topics 数组 动态规划 
// 👍 405 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 所谓动态规划，就是从头开始，一步一步的按照一个状态转移方程进行运算
    // 二维动态规划尤其直观，一维的也是一样的，你只需考虑当前位置怎么最优，然后再考虑下一个位置，...
    // cost[i] = min(cost[i-1], cost[i-2]) + cost[i];
    // 可以在空间上优化，即使用两个变量来记录中间结果


    // 值得注意的是，我们最终的时候可能会从倒数第二个数直接到终点
    int minCostClimbingStairs(vector<int>& cost)
    {
        for (int i = 2; i < cost.size(); ++i)
        {
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        return min(cost.back(), cost[cost.size() - 2]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
