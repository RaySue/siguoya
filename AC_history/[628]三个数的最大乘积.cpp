//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。 
//
// 示例 1: 
//
// 
//输入: [1,2,3]
//输出: 6
// 
//
// 示例 2: 
//
// 
//输入: [1,2,3,4]
//输出: 24
// 
//
// 注意: 
//
// 
// 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。 
// 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。 
// 
// Related Topics 数组 数学 
// 👍 189 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：
    // 先对数组进行排序， 目标是为了得到前三大的数，和最小的两个数
    // 比较最小的两个数和最大的数的乘积 和 前三大的数的乘积哪个大即可。
    // Complexity:
    // Time: O(NlogN)
    // Space: O(1)
    int maximumProduct1(vector<int> &nums)
    {
        if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
        sort(nums.begin(), nums.end());
        int first = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int second = nums[0] * nums[1] * nums[nums.size() - 1];
        return max(first, second);
    }

    // 2021.01.20 每日一题
    // 思路：
    // 存在负数，所以只需要考虑两种情况下可能出现三数之积的最大值：
    // 1. 最大的三个值之积
    // 2. 最小的两个值（负数）与最大值 之积
    // 方法二：
    // 通过一趟扫描拿到 max1，max2，max3，min1，min2
    // 比较 max1 * max2 * max3 与 max1 * min1 * min2 的大小

    // 归纳一下这个题目：
    // 核心是要找到最大的三个数的乘积，考虑到负数的情况
    // 可以利用排序，然后找到最大的三个数相乘 与 最大数与最小的两个数相乘做比较，因为使用排序所以复杂度为 O(NlogN)
    // 也可以一趟找到最大值、次大值、次次大值，最小值、次小值，这个模型如下：
    // 需要考虑到数组本身就是一个递增的数组，那怎么处理呢？
    // 我们先让最大值、次大值、次次大值 为 INT_MIN，如果递增的，那么每次肯定是更新最大值，我们在更新第一次最大值之后，
    // 就需要更新次大值了，所以需要判断最大值是否已经更新过，如果更新过，那么就把之前的值给次大值，次大值也一样，遵循这个就可以。
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > max1)
            {
                if (max1 != INT_MIN)
                {
                    if (max2 != INT_MIN)
                    {
                        max3 = max2;
                    }
                    max2 = max1;
                }
                max1 = nums[i];
            } else if (nums[i] > max2)
            {
                if (max2 != INT_MIN)
                {
                    max3 = max2;
                }
                max2 = nums[i];
            } else if (nums[i] > max3)
            {
                max3 = nums[i];
            }

            if (nums[i] < min1)
            {
                if (min1 != INT_MIN)
                {
                    min2 = min1;
                }
                min1 = nums[i];
            } else if (nums[i] < min2)
            {
                min2 = nums[i];
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
