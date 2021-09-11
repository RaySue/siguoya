//如果数组是单调递增或单调递减的，那么它是单调的。 
//
// 如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。
//
// 当给定的数组 A 是单调数组时返回 true，否则返回 false。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：[1,2,2,3]
//输出：true
// 
//
// 示例 2： 
//
// 输入：[6,5,4,4]
//输出：true
// 
//
// 示例 3： 
//
// 输入：[1,3,2]
//输出：false
// 
//
// 示例 4： 
//
// 输入：[1,2,4,5]
//输出：true
// 
//
// 示例 5： 
//
// 输入：[1,1,1]
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 50000 
// -100000 <= A[i] <= 100000 
// 
// Related Topics 数组 
// 👍 76 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.14
    // 这个题目也不可小看，我们需要判断是否有相悖的时候，所以需要一个 flag
    // 思路：
    // flag = 1 代表状态是升序状态
    // flag = 2 代表状态是降序状态
    // 遍历 A 如果 相邻元素相等，那么就continue
    // 如果不相等，那么就对 flag 赋值，如果出现flag 相悖的情况，返回 false 即可
    bool isMonotonic(vector<int> &A)
    {
        if (A.size() < 2) return true;
        int flag = 0;  // 升序 1 降序 2
        for (int i = 0; i < A.size() - 1; ++i)
        {
            if (A[i] == A[i + 1]) continue;
            else if (A[i] < A[i + 1])
            {
                if (flag == 2) return false;
                flag = 1;
            } else
            {
                if (flag == 1) return false;
                flag = 2;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
