//给出一个区间的集合，请合并所有重叠的区间。 
//
// 
//
// 示例 1: 
//
// 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: intervals = [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。 
//
// 
//
// 提示： 
//
// 
// intervals[i][0] <= intervals[i][1] 
// 
// Related Topics 排序 数组 
// 👍 590 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector <vector<int>> merge1(vector <vector<int>> &intervals)
    {
        vector <vector<int>> ans;
        if (intervals.empty()) return ans;
//        auto lambda = [](vector<int> a, vector<int> b) -> bool{ return a[0] < b[0]; };
//        sort(intervals.begin(), intervals.end(), lambda);
        sort(intervals.begin(), intervals.end());
        // 对区间的左边进行排序之后，开始判断两个区间的关系即可
        // 两个区间的关系只剩下三种情况
        // 1. 相离
        // 2. 相交
        // 3. 包含
        for (int i = 1; i < intervals.size(); ++i)
        {
            // 把相交或包含的区间都汇集在 [i-1] 的区间中
            if (intervals[i - 1][1] >= intervals[i][0])
            {
                intervals[i][0] = intervals[i - 1][0];
                if (intervals[i][1] < intervals[i - 1][1])
                {
                    intervals[i][1] = intervals[i - 1][1];
                }
            } else
            {
                ans.push_back(intervals[i - 1]);
            }
        }
        // 需要添加最后一个区间
        ans.push_back(intervals.back());
        return ans;

    }

    vector <vector<int>> merge2(vector <vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> ans;
        for (int i = 0; i < intervals.size();)
        {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t)
            {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], t});
            i = j;
        }
        return ans;
    }

    vector <vector<int>> merge(vector <vector<int>> &intervals)
    {
        if (intervals.size() < 2) return intervals;
        vector<vector<int>> ret;
        auto lambda = [&](vector<int> v1, vector<int> v2){ return v1[0] < v2[0];};
        sort(intervals.begin(), intervals.end(), lambda);
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (r >= intervals[i][0])
            {
                r = max(r, intervals[i][1]);
            } else {
                ret.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ret.push_back({l, r});
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
