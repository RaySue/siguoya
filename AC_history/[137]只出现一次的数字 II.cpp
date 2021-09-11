// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//
// 说明： 
//
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？ 
//
// 示例 1: 
//
// 输入: [2,2,3,2]
//输出: 3
// 
//
// 示例 2: 
//
// 输入: [0,1,0,1,0,1,99]
//输出: 99 
// Related Topics 位运算 
// 👍 483 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 二刷 2021.01.08
    // 我们可以对32位中的每一位，遍历所有的数字，记录为1的个数
    // 如果所有的数字都出现 3 次，那么这个位对应的 1 累加起来一定可以被 3 整除
    // 如果第 i 位不能被 3 整除，那么我们就将这个位加到要返回的结果中
    // 遍历 32 位之后答案浮出水面
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            int count = 0;
            for (int n : nums)
            {
                if ((n & (1 << i)) == 0) continue;
                count++;
            }
            if (count % 3 == 0) continue;
            ret |= (1 << i);
        }
        return ret;
    }

    // ------------------- 待研究的思路 --------------------
    int singleNumber(vector<int> &nums)
    {
        int once = 0, twice = 0;
        for (auto x : nums)
        {
            once = (once ^ x) & (~twice);
            twice = (twice ^ x) & (~once);
        }
        return once;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
