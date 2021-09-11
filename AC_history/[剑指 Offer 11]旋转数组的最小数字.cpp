//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。
//
// 示例 1： 
//
// 输入：[3,4,5,1,2]
//输出：1
// 
//
// 示例 2： 
//
// 输入：[2,2,2,0,1]
//输出：0
// 
//
// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sor
//ted-array-ii/ 
// Related Topics 二分查找 
// 👍 185 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 二刷 2020.12.31 明天就是牛年啦
    // 带有重复数字的有序旋转数组的最小值
    int minArray1(vector<int> &numbers)
    {
        if (numbers.empty()) return 0;
        int minVal = numbers[0];
        int l = 0, r = numbers.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (numbers[l] < numbers[mid]) // 左半部分
            {
                minVal = min(minVal, numbers[l]);
                l = mid + 1;
            } else if (numbers[l] > numbers[mid])
            {
                minVal = min(minVal, numbers[mid]);
                r = mid - 1;
            } else
            {
                // [2,2,2,0,1]
                minVal = min(minVal, numbers[mid]); // 这里或者 nums[l] 与 nums[mid] 相等，或者 nums[r] 与 nums[mid] 相等
                numbers[l] == numbers[mid] ? l++ : r--;
            }
        }
        return minVal;
    }













    int minArray(vector<int> &numbers)
    {
        if (numbers.empty()) return 0;
        int l = 0, r = numbers.size() - 1, mid;
        int minVal = numbers[0];
        while(l <= r)
        {
            mid = l + (r - l >> 1);
            if (numbers[l] < numbers[mid])
            {
                minVal = min(minVal, numbers[l]);
                l = mid + 1;
            } else if (numbers[l] > numbers[mid])
            {
                minVal = min(minVal, numbers[mid]);
                r = mid - 1;
            } else {
                numbers[l] == numbers[mid]? l++: r--;
                minVal = min(minVal, numbers[mid]);
            }
        }
        return minVal;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
