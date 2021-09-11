// 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
//
// 示例 1: 
//
//     [-1,0,1,2,3,4,8]
//     [-1,-1,0,0,1,1,2] [0,1,1,2,2]
//输入: [-1,-1,0,0,1,1,2,3,3,4,4,8,8]
//输出: 2
// 
//
// 示例 2: 
//
//
//
//输入: [3,3,7,7,10,11,11]
//输出: 10
// 
//
// 注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。 
// Related Topics 二分查找 
// 👍 186 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // base 方法 O(N) 复杂度
    int singleNonDuplicate1(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            ret ^= nums[i];
        }
        return ret;
    }

    // 复合题意的二分法 O(logN)复杂度
    // 这个题目需要构建的二分法相对隐晦，能够使用二分法的前提是，我们能够根据条件来判断：收缩边界
    // 1. 什么时候返回 2. 什么时候收缩左边界 3. 什么时候收缩右边界
    //
    // 观察发现：
    // 单个数字出现之前，每个数字都大于前一个相邻的数字，此时收缩左边界
    // 单个数字出现之后，每个数字都等于前一个相邻的数字，此时收缩右边界
    // [1,1,2,3,*3,4,4,8,8]  9 / 2 = 4
    // [2,3,3,*4,4,8,8] 7 / 2 = 3
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            // 判读相等的情况
            bool cond1 = mid == 0 && nums[mid] < nums[mid + 1];
            if (cond1) return nums[mid];
            bool cond2 = (nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]);
            if (cond2) return nums[mid];
            // 判断收缩边界
            // 判断 mid 是奇数的情况
            if (mid % 2 != 0)
            {
                // 是偶数要和相邻的前一位作对比
                if (nums[mid - 1] == nums[mid])
                {
                    l = mid + 1;
                } else
                {
                    r = mid - 1;
                }
            }
            // 判断 mid 是偶数的情况
            if (mid % 2 == 0)
            {
                if (nums[mid - 1] == nums[mid])
                {
                    r = mid - 1;
                } else
                {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
