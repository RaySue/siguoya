// 给定一个无重复元素的有序整数数组 nums 。
//
// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
// 并且不存在属于某个范围但不属于 nums 的数字 x 。
//
// 列表中的每个区间范围 [a,b] 应该按如下格式输出：
// 
// "a->b" ，如果 a != b 
// "a" ，如果 a == b
//
// 
//
// 示例 1： 
//
// 输入：nums = [0,1,2,4,5,7]
//输出：["0->2","4->5","7"]
//解释：区间范围是：
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
// 
//
// 示例 2： 
//
// 输入：nums = [0,2,3,4,6,8,9]
//输出：["0","2->4","6","8->9"]
//解释：区间范围是：
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
// 
//
// 示例 3： 
//
// 输入：nums = []
//输出：[]
// 
//
// 示例 4： 
//
// 输入：nums = [-1]
//输出：["-1"]
// 
//
// 示例 5： 
//
// 输入：nums = [0]
//输出：["0"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 20 
// -231 <= nums[i] <= 231 - 1 
// nums 中的所有值都 互不相同 
// 
// Related Topics 数组 
// 👍 71 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 此题不简单
    // 使用类似滑窗法的框架来解决
    // 利用 deque 作为窗口，
    // 如果后一个数比前一个数大超过 1
    // 如果deque的size() >= 2，那么就添加 首->尾
    // 否则添加单个元素
    //
    // Time: O(N)
    // Space: O(N)
    vector <string> summaryRanges1(vector<int> &nums)
    {
        vector <string> ans;
        if (nums.empty()) return ans;
        int l = 0, r = 0;
        deque<int> window;
        while (r < nums.size())
        {
            window.push_back(nums[r]);
            r++;
            // r == nums.size() 是为了让最后一组能够入到 ans 中
            // nums[r]  > window.back() + 1 是为了防止内存溢出相比 nums[r] - 1 > window.back()
            if (r == nums.size() || !window.empty() && nums[r]  > window.back() + 1)
            {
                if (window.size() >= 2)
                {
                    ans.push_back(to_string(window.front()) + "->" + to_string(window.back()));
                } else
                {
                    ans.push_back(to_string(window.front()));
                }
                window.clear();
            }
        }
        return ans;
    }

    vector <string> summaryRanges(vector<int> &nums)
    {
        vector <string> ans;
        if (nums.empty()) return ans;
        for (int i = 0; i < nums.size(); ++i)
        {

        }

    }

};
//leetcode submit region end(Prohibit modification and deletion)
