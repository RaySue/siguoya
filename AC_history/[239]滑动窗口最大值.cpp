// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [9,11], k = 2
//输出：[11]
// 
//
// 示例 5： 
//
// 
//输入：nums = [4,-2], k = 2
//输出：[4] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window 
// 👍 702 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 二刷 2020.01.02 每日一题
    // 滑动窗口法，利用 deque 作为窗口记录, maxVal 保存窗口最大值
    // 滑动入窗口 更新最大值
    // 滑动出窗口：
    //     1. 如果最大值出窗口，那么遍历找到新的最大值
    //     2. 如果最大值没有出窗口，则不变
    // Time Out了，同样的思路，用我之前的代码依旧是Time Out
    // Complexity:
    // 时间复杂度： O(N * k)
    // 空间复杂度： O(k)
    // 所以要滑动窗口法，但是要用利用单调队列使用 O(1) 的复杂度来找到滑动窗口的最大值
    vector<int> maxSlidingWindow1(vector<int>& nums, int k)
    {
        vector<int> ans;
        int l = 0, r = 0, maxVal = nums[0];
        deque<int> window;
        while(r < nums.size())
        {
            maxVal = max(maxVal, nums[r]);
            window.push_back(nums[r]);
            r++;
            while(window.size() >= k)
            {
                ans.push_back(maxVal);
                // 先去掉之前的最大值
                window.pop_front();
                if (nums[l] == maxVal)
                {
                    // 这里的线性查找非常耗时 O(k)
                    maxVal = findWindowMax(window);
                }
                l++;
            }
        }
        return ans;
    }

    int findWindowMax(deque<int> &window)
    {
        int maxVal = window.front();
        for (int i = 0; i < window.size(); ++i)
        {
            int tmp = window.front();
            maxVal = max(tmp, maxVal);
            window.pop_front();
            window.push_back(tmp);
        }
        return maxVal;
    }

    // 二刷 2020.01.02
    // 滑动窗口法，利用单调队列进行窗口最大值的获取
    // 单调队列，就是每次保存的值都是单调的，或者单调递减，或者单调递增
    // 可以使用deque来做单调队列
    vector<int> maxSlidingWindow2(vector<int>& nums, int k)
    {
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        int l = 0, r = 0;
        deque<int> window;
        while(r < nums.size())
        {
            // 每次新添加的数据，我们判断一下，是不是比window.back()要大，如果大于，那么删除掉，只保存最大值
            // 因为，前面的比后面的小，那么前面的数字就没有意义了，永远不会出场了
            // 剩余的我们取递减顺序存放
            while(!window.empty() && window.back() < nums[r]) window.pop_back();
            window.push_back(nums[r]);
            r++;
            while(r - l >= k)
            {
                res.push_back(window.front());
                if (nums[l] == window.front()) window.pop_front();  // 当最大值离去的时候，我们剩余的一定是第二大的，back up
                l++;
            }
        }
        return res;
    }

    // 利用单调栈的思想
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int size = k;
        vector<int> ret;
        int l = 0, r = 0;
        deque<int> window;
        while(r < nums.size())
        {
            while (!window.empty() && window.back() < nums[r]) window.pop_back();
            window.push_back(nums[r]);
            r++;
            while (r - l >= size)
            {
                ret.push_back(window.front());
                if (window.front() == nums[l]) window.pop_front();
                l++;
            }
        }
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
