//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
// Related Topics 队列 Sliding Window 
// 👍 110 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一： 滑动窗口 + 双端队列
    // 双端队列，每次入队列一个元素判断一下，如果大于目前的最大值就替换掉目前的最大值
    // 双端队列，每次出队列，如果出队列的结果等于最大值，那么就遍历双端队列，找到新的最大值
    // 双端队列，如果出队列之后双端队列为空，要把maxVal 置为 INT_MIN

    int getMax(deque<int> &window)
    {
        int ans = window.front();
        for (int i = 0; i < window.size(); ++i)
        {
            int tmp = window.front();
            if (tmp > ans) ans = tmp;
            window.pop_front();
            window.push_back(tmp);
        }
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int l = 0, r = 0, maxVal = INT_MIN;
        deque<int> window;
        while (r < nums.size())
        {
            if (nums[r] > maxVal) maxVal = nums[r];
            window.push_back(nums[r]);
            r++;
            while (r - l >= k)
            {
                ans.push_back(maxVal);
                int cur = window.front();
                window.pop_front();
                if (cur == maxVal) maxVal = getMax(window);
                if (window.empty()) maxVal = INT_MIN;
                l++;
            }
        }
        return ans;
    }

    // -----------------------------------------------------------------
    // -----------------------------------------------------------------
    // -----------------------------------------------------------------

    // 方法二 使用单调队列



};
//leetcode submit region end(Prohibit modification and deletion)
