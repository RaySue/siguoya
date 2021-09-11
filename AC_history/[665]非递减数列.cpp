// 给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
//
// 我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [4,2,3]
//输出: true
//解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
// 
//
// 示例 2: 
//
// 输入: nums = [4,2,1]
//输出: false
//解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
// 
//
// 
//
// 说明： 
//
// 
// 1 <= n <= 10 ^ 4 
// - 10 ^ 5 <= nums[i] <= 10 ^ 5 
// 
// Related Topics 数组 
// 👍 368 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 1. 下降两次 不行
    // 2. [3,4,2,3]
    // https://leetcode-cn.com/problems/non-decreasing-array/solution/3-zhang-dong-tu-bang-zhu-ni-li-jie-zhe-d-06gi/
    /**
        当 nums[i] 破坏了数组的单调递增时，即 nums[i] < nums[i - 1]  时，
        为了让数组有序，我们发现一个规律（在上面三个例子中， nums[i] 都为 2， nums[i -1] 都为 4）：

        如例①的情况，当 i = 1 ，那么修改 num[i- 1] ，不要动 nums[i] ，因为nums[i]后面的元素是啥我们还不知道呢，少动它为妙。
        如例②的情况，当 i > 1 时，我们应该优先考虑把 nums[i - 1] 调小到 >= nums[i - 2] 并且 <= nums[i]。同样尽量不去修改 nums[i] ，理由同上。
        如例③的情况，当 i > 1 且 nums[i] < nums[i - 2] 时，我们无法调整 nums[i - 1] ，我们只能调整 nums[i] 到 nums[i - 1] 。
     */
    bool checkPossibility(vector<int> &nums)
    {

    }
};
//leetcode submit region end(Prohibit modification and deletion)
