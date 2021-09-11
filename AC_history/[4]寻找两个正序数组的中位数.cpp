// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
//
// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？ 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 示例 3： 
//
// 输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
// 
//
// 示例 4： 
//
// 输入：nums1 = [], nums2 = [1]
//输出：1.00000
// 
//
// 示例 5： 
//
// 输入：nums1 = [2], nums2 = []
//输出：2.00000
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
// Related Topics 数组 二分查找 分治算法 
// 👍 3466 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // 方法一： 归并排序，将两个数组合成一个数组，然后再求中位数
    // Complexity:
    // O(M + N)
    // O(M + N)
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums(nums1.size() + nums2.size());
        if (nums.empty()) return 0;
        int p1 = nums1.size() - 1;
        int p2 = nums2.size() - 1;
        int p = nums.size() - 1;
        while (p1 >= 0 || p2 >= 0)
        {
            if (p1 < 0)
            {
                nums[p--] = nums2[p2--];
            } else if (p2 < 0)
            {
                nums[p--] = nums1[p1--];
            } else
            {
                if (nums1[p1] < nums2[p2])
                {
                    nums[p--] = nums2[p2--];
                } else
                {
                    nums[p--] = nums1[p1--];
                }
            }
        }

        if (nums.size() % 2 != 0)
        {
            return nums[nums.size() / 2];
        } else
        {
            return (nums[nums.size() / 2 - 1] * 1.0 + nums[nums.size() / 2] * 1.0) / 2;
        }
    }


    // 二刷： 2020.12.25 代码更简练，更易懂
    // 方法二：可以不归并排序，只是在 nums1 和 nums2 中找到中位数的位置
    // O(M + N)， O(1)
    // 思路：
    // 我们需要两个指针p1 和 p2 分别指向 nums1和 nums2，我们的目的是为了找到两个数组长度相加除以2的数
    // 我们利用 pre 和 cur 两个变量(double)来记录寻找 target 过程的值，cur表示当前值，pre 是当前数的前一个数，用于偶数求中位数使用
    // 当 p1 和 p2 相加等于 target的时候，如果是奇数那么cur就是我们要找的中位数，如果是偶数，那么(pre + cur) /2就是中位数
    // 里面的判断条件就是归并排序的判断条件，千万不要想复杂，遵循以下思路：
    // 1. 如果 nums2 遍历完了即 p2 >= nums2.size()，那么就只能遍历 nums1
    // 2. 如果 nums1 遍历完了即 p1 >= nums1.size()，那么就只能遍历 nums2
    // 3. 剩下的情况是两者都没有遍历完，那么就比较大小来判断即可
    // 不需要进行 真正的归并合并， 我们只需找到 总长度 一般的位置的数，及其前一个位置的数（处理偶数情况）
    // 第 K 个元素
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
    {
        int p1 = 0, p2 = 0;
        int target = (nums1.size() + nums2.size()) / 2;
        int cur = 0, pre = 0;
        while (p1 + p2 < target)
        {
            pre = cur;
            if (p1 >= nums1.size())
            {
                cur = nums2[p2++];
            } else if (p2 >= nums2.size())
            {
                cur = nums1[p1++];
            } else
            {
                cur = nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
            }
        }
        return ((nums1.size() + nums2.size()) % 2 == 0) ? (cur * 1.0 + pre * 1.0) / 2 : cur;
    }

    // --------------------------------------------------------------------------------------------

    // 方法三：都是排序的数组，二分法找第k个大的数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        // 中位数 = （left + right）/2, left 和 right 可能是相等的
        // m + n 如果是奇数的话，那么下面两个值是相等的，偶数时候不相等
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    //在两个有序数组中找到第k个元素（例如找第一个元素，k=1，即nums[0]）
    //i: nums1的起始位置 j: nums2的起始位置（i，j都是从0开始）
    int findKth(vector<int>& nums1, int p1, vector<int>& nums2, int p2, int k)
    {
        //若nums1为空（或是说其中数字全被淘汰了）
        //在nums2中找第k个元素，此时nums2起始位置是j，所以是j+k-1
        if(p1 >= nums1.size()) return nums2[p2 + k - 1];
        //nums2同理
        if(p2 >= nums2.size()) return nums1[p1 + k - 1];

        //递归出口，就是求两个有序数组的最小值
        if(k == 1) return min(nums1[p1], nums2[p2]);

        //这两个数组的第K/2小的数字，若不足k/2个数字则赋值整型最大值，以便淘汰另一数组的前k/2个数字
        int midVal1 = (p1 + k/2 - 1 < nums1.size()) ? nums1[p1 + k/2 - 1] : INT_MAX;
        int midVal2 = (p2 + k/2 - 1 < nums2.size()) ? nums2[p2 + k/2 - 1] : INT_MAX;
        //二分法核心部分
        if(midVal1 < midVal2)
            return findKth(nums1, p1 + k/2, nums2, p2, k - k/2);
        else
            return findKth(nums1, p1, nums2, p2 + k/2, k - k/2);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
