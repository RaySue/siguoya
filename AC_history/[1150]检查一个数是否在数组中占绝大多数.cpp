// 给出一个按 非递减 顺序排列的数组 nums，和一个目标数值 target。假如数组 nums 中绝大多数元素的数值都等于 target，则返回 True，
// 否则请返回 False。
//
// 所谓占绝大多数，是指在长度为 N 的数组中出现必须 超过 N/2 次。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [2,4,5,5,5,5,5,6,6], target = 5
//输出：true
//解释：
//数字 5 出现了 5 次，而数组的长度为 9。
//所以，5 在数组中占绝大多数，因为 5 次 > 9/2。
// 
//
// 示例 2： 
//
// 输入：nums = [10,100,101,101], target = 101
//输出：false
//解释：
//数字 101 出现了 2 次，而数组的长度是 4。
//所以，101 不是 数组占绝大多数的元素，因为 2 次 = 4/2。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i] <= 10^9 
// 1 <= target <= 10^9 
// 
// Related Topics 数组 二分查找 
// 👍 25 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    int binarySearch(vector<int> &nums, int target, bool leftBound)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = l + (r - l >> 1);
            if (nums[mid] < target)
            {
                l = mid + 1;
            } else if (nums[mid] > target)
            {
                r = mid - 1;
            } else
            {
                if (leftBound)
                {
                    r = mid - 1;
                } else
                {
                    l = mid + 1;
                }
            }
        }
        if (leftBound)
        {
            if (l >= nums.size() || nums[l] != target) return -1;
        } else
        {
            cout << r << endl;
            if (r < 0 || nums[r] != target) return -1;
        }
        return leftBound ? l : r;
    }

    // 顺序数组，要想到二分法，二分法有三种，找左、找中、找右
    bool isMajorityElement(vector<int> &nums, int target)
    {
        int sz = nums.size();
        int leftBound = 2, rightBound = -1;
        leftBound = binarySearch(nums, target, true);
        rightBound = binarySearch(nums, target, false);
        if (leftBound == -1 || rightBound == -1) return false;
        return rightBound - leftBound + 1 > sz / 2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
