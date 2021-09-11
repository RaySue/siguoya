// 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
//
// 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。 
//
// 你可以返回任何满足上述条件的数组作为答案。 
//
// 
//
// 示例： 
//
// 输入：[4,2,5,7]
//输出：[4,5,2,7]
//解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= A.length <= 20000 
// A.length % 2 == 0 
// 0 <= A[i] <= 1000 
// 
//
// 
// Related Topics 排序 数组 
// 👍 147 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：
    // 利用 双指针 和 swap 直接修改A即可
    // 1. 当奇数指针指向的数字不是奇数的时候，那么就交换奇偶指针对应的数字
    // 2. 否则就一直将奇数指针向后移动两位
    // 这里的思想就是，如果奇数位置都是奇数，那么偶数位置必然都是偶数

    // Complexity:
    // Time: O(N)
    // Space: O(1)
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int oddPtr = 1;
        int evenPtr = 0;
        while (oddPtr < A.size() && evenPtr < A.size())
        {
            if (A[oddPtr] % 2 == 0)
            {
                swap(A[evenPtr], A[oddPtr]);
                evenPtr += 2;
            } else
            {
                oddPtr += 2;
            }
        }
        return A;
    }

    // 暴力解法
    // 新开一个等长度数组（注意在这里我们不考虑输出数组的空间占用）
    // 1. 遍历 A 检测所有的奇数，放在新数组的奇数位置
    // 2. 遍历 A 检测所有的偶数，放在新数组的偶数位置

};
//leetcode submit region end(Prohibit modification and deletion)
