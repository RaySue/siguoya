//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
// 
//
// 示例： 
//
// 输入：nums = [1,2,3,4]
//输出：[1,3,2,4] 
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 50000 
// 1 <= nums[i] <= 10000 
// 
// 👍 62 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // vector<int> odd 记录所有的奇数
    // vector<int> even 记录所有的偶数
    // 返回 concat(odd, even)
    //
    // 思路一： 计数排序

    // 思路二：
    //
    vector<int> exchange(vector<int>& nums)
    {
        int p1 = 0, p2 = nums.size() - 1;
        while(p1 < p2)
        {
            if (nums[p1] % 2 == 0)
            {
                while(nums[p2] % 2 == 0)
                {
                    p2--;
                    // 这个位置，非常要命，要保证两点：
                    // 1. p2 不可以越界（ < 0 ）
                    // 2. p2 不可以小于 p1
                    if (p2 < 0 || p2 < p1) return nums;
                }
//                cout << nums[p1] << " " << nums[p2] << endl;
                swap(nums[p1], nums[p2]);
            }
            p1 ++;
        }
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
