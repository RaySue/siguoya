// 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法 
// 👍 871 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if (nums.empty()) return -1;
        priority_queue<int, vector<int>, greater<int>> q;  // 小顶堆
//        priority_queue<int, vector<int>, less<int>> q; // 大顶堆
        for (int i = 0; i < nums.size(); ++i)
        {
            if (q.size() == k)
            {
                q.push(nums[i]);
                q.pop();
            } else {
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
