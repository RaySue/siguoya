// 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
//
// 如果数组元素个数小于 2，则返回 0。 
//
// 示例 1: 
//
// 输入: [3,6,9,1]
//输出: 3
//解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。 
//
// 示例 2: 
//
// 输入: [10]
//输出: 0
//解释: 数组元素个数小于 2，因此返回 0。 
//
// 说明: 
//
// 
// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。 
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。 
// 
// Related Topics 排序 
// 👍 243 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 题目要求用线性的时间和空间复杂度解决问题
    // time out
    // 原因是当数值过大的时候，需要遍历的maxVal太大，导致复杂度太高，时空复杂度都高
    // 使用计数桶排序的时候，一定要注意最大值的问题否则非常惨
    int maximumGap1(vector<int> &nums)
    {
        int maxInterval = 0;
        if (nums.size() < 2) return maxInterval;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> bucket(maxVal + 1, 0);
        for (int num:nums) bucket[num]++;
        int prev = INT_MAX;
        for (int i = 0; i <= maxVal; ++i)
        {
            if (bucket[i] == 0) continue;
            int interval = i - prev;
            maxInterval = max(maxInterval, interval);
            prev = i;
        }
        return maxInterval;
    }

    // 基于基数排序
    // 基数排序的思路：
    // 先根据个位排序，再根据十位排序，在根据百位排序，...，最终的结果就是有序的
    // 给定无序字符串 n
    // 1. 先确定基数 base = 10，
    // 2. 遍历数组，将每个数字都和base取余数，放入长度为10的桶中
    // 3. 将桶中元素的个数向后累加，最后一位的结果就是长度 n，这一步是为了将元素的个数转化为下标，最后一个数字就是 （n - 1）
    // 4. 逆序遍历桶，将对应的数字从 nums 赋值到 buffer（长度为 n ） 中
    // 5. base *= 10
    // d 表示有多少位，由于是32 位有符号整数范围内所以d是常数， r 表示基数，也是常数一般取10
    // O(d * (N + r)) O(N + r)
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2) return 0;

        int exp = 1;
        vector<int> buf(n, 0);
        int maxVal = *max_element(nums.begin(), nums.end());

        while (maxVal >= exp)
        {
            vector<int> cnt(10, 0);
            for (int i = 0; i < n; i++)
            {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++)
            {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--)
            {
                int digit = (nums[i] / exp) % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int ret = 0;
        for (int i = 1; i < n; i++)
        {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
