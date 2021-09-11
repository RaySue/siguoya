// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
//
// 
//
// 示例 1: 
//
// 输入: [1,2,3,4,5]
//输出: True 
//
// 
//
// 示例 2: 
//
// 输入: [0,0,1,2,5]
//输出: True 
//
// 
//
// 限制： 
//
// 数组长度为 5 
//
// 数组的数取值为 [0, 13] . 
// 👍 81 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 能蹦出来5个大王来，不讲武德
    // 思路：
    // 先排序
    // 记录 0 的个数
    // 记录 gap 的个数，顺便check 是否有重复
    // 遍历 nums，如果遇到0 就记录 zeroCount++
    // 如果遇到其他的数字，就计算 gap
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int zeroCount = nums.back() == 0;
        int gap = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == 0) zeroCount++;
            else
            {
                int tmp = nums[i + 1] - nums[i] - 1;
                if (tmp < 0) return false;  // 出现重复数字
                gap += tmp;
            }
        }
        return zeroCount - gap >= 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
