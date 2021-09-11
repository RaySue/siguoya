// 给定已经按**升序排列**、
// 由不同整数组成的数组 A，返回满足 A[i] == i 的最小索引 i。
// 如果不存在这样的 i，返回 -1。
//
// 
//
// 示例 1： 
//
// 输入：[-10,-5,0,3,7]
//输出：3
//解释：
//对于给定的数组，A[0] = -10，A[1] = -5，A[2] = 0，A[3] = 3，因此输出为 3 。
// 
//
// 示例 2： 
//
// 输入：[0,2,5,8,17]
//输出：0
//示例：
//A[0] = 0，因此输出为 0 。
// 
//
// 示例 3： 
//
// 输入：[-10,-5,3,4,7,9]
//输出：-1
//解释： 
//不存在这样的 i 满足 A[i] = i，因此输出为 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length < 10^4 
// -10^9 <= A[i] <= 10^9 
// 
// Related Topics 数组 二分查找 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 暴力求解
    int fixedPoint1(vector<int> &A)
    {
        for (int i = 0; i < A.size(); ++i)
        {
            if (i == A[i]) return i;
        }
        return -1;
    }

    // 二分查找 左边界模板 返回 最小索引 i
    int fixedPoint(vector<int> &A)
    {
        int l = 0, r = A.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (A[mid] < mid)
            {
                l = mid + 1;
            } else if (A[mid] > mid)
            {
                r = mid - 1;
            } else if (A[mid] == mid)
            {
                r = mid - 1;
            }
        }
        if (l == A.size() || A[l] != l) {
            return -1;
        }
        return l;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
