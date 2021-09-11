// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//
// 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出: 2 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// 
// Related Topics 位运算 分治算法 
// 👍 96 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：利用 hash map 就非常简单了


    // 方法二：摩尔投票法
    // 先初始化第一个元素是 我们要的答案，然后，遇到这个元素，我们就对count++
    // 遇到其他元素，我们就对 count--， 当count < 0 的时候，我们把这个时刻的nums[i] 作为新的 ans
    // 知道所有的pk结束，剩下的ans一定是出现次数大于一半的
    int majorityElement(vector<int> &nums)
    {
        int count = 0, idx = 0;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == ans) count++;
            else
            {
                count--;
            }
            if (count < 0)
            {
                count = 0;
                ans = nums[i];
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
