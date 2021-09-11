//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。 
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。 
// 你可以按任意顺序返回答案。 
// 
// Related Topics 堆 哈希表 
// 👍 499 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:


    struct cmp
    {
        template <typename T, typename U>
        bool operator()(T const &left, U const &right)
        {
            // 以second比较。输出结果为Second较大的在前Second相同时，先进入队列的元素在前。
            if (left.second < right.second)
                return true;
            return false;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> ans;
        if (nums.empty()) return ans;
        unordered_map<int, int> record;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int> > > Maxheap;
        for (auto n : nums)record[n]++;
        unordered_map<int, int>::iterator iter;

        for (iter = record.begin(); iter != record.end(); ++iter)
        {
            Maxheap.push(pair<int, int>(iter->second, iter->first));
        }

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(Maxheap.top().second);
            Maxheap.pop();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
