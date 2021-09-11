// 给定一个范围在 1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，
// 数组中的元素一些出现了两次，另一些只出现一次。
//
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。 
//
// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。 
//
// 示例: 
//
// 
//输入:
//[4,3,2,7,8,2,3,1]
//
//[4,3,2,7,8,2,3,1]
//[-4,-3,-2,-7,8,2,-3,-1]
//[]
//输出:
//[5,6]
// 
// Related Topics 数组 
// 👍 530 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
    题目要求不能由额外的空间开销，所以不能用哈希表 要求时间复杂度为 O(n)，所以不能排序
    故考虑对原数组进行操作处理 充分利用数组下标信息 作为标志

    第一次对数组进行遍历，取数组中当前元素nums[i]，
    把对应第 nums[i] 个元素置为负数 因为下标的原因，同时可能数组中元素有重复，比如已经变为负数了，所以要加绝对值。
    即第 nums[ abs(nums[i])-1 ] 元素变为负 最后，
    第二次对修改后的数组进行操作，如果数组中第i位的数字还是正数，说明 原来的数组里面没有数字i，即没有改成负数，则加入结果中即可。
     */
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> ret;
        // 从 1 开始所以需要对绝对值 -1
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[abs(nums[i]) - 1] > 0)
            {
                nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0) ret.push_back(i + 1);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
