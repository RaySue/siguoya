//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
//数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第
//一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。 
//
// 示例 1: 
//
// 
//输入: [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数； 
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 
//
// 注意: 输入数组的长度不会超过 10000。 
// Related Topics 栈 
// 👍 213 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    // 思路：对两个数组进行合并
    // 如何达到循环数组的效果 index = i % n (i in [0, 2n - 1]);
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 0);
        stack<int> s;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int idx = i % n;
            while(!s.empty() && s.top() <= nums[idx]) s.pop();
            ans[idx] = s.empty()?-1:s.top();
            s.push(nums[idx]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
