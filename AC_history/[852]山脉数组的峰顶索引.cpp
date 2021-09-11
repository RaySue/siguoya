//我们把符合下列属性的数组 A 称作山脉： 
//
// 
// A.length >= 3 
// 存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[
//A.length - 1] 
// 
//
// 给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.leng
//th - 1] 的 i 的值。 
//
// 
//
// 示例 1： 
//
// 输入：[0,1,0]
//输出：1
// 
//
// 示例 2： 
//
// 输入：[0,2,1,0]
//输出：1 
//
// 
//
// 提示： 
//
// 
// 3 <= A.length <= 10000 
// 0 <= A[i] <= 10^6 
// A 是如上定义的山脉 
// 
//
// 
// Related Topics 二分查找 
// 👍 124 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


//    int peakIndexInMountainArray(vector<int>& arr)
//    {
//        int l = 0, r = arr.size() - 1, mid;
//        while(l <= r)
//        {
//            mid = l + (r - l >> 1);
//            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
//            {
//                l = mid;
//            } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
//            {
//                r = mid;
//            } else if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
//            {
//                return mid;
//            }
//        }
//    }



    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0, r = arr.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);

            if (arr[mid] < arr[mid + 1]) // 判断上坡
            {
                l = mid + 1;
            } else if (arr[mid - 1] > arr[mid])  // 判断下坡
            {
                r = mid - 1;
            } else
            {
                return mid;
            }
        }
        return mid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
