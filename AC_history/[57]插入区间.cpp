// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
//
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。 
//
// 
//
// 示例 1： 
//
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出：[[1,5],[6,9]]
// 
//
// 示例 2： 
//
// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出：[[1,2],[3,10],[12,16]]
//解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
// 
//
// 
//
// 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。 
// Related Topics 排序 数组 
// 👍 193 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // base解法，和56合并区间一样，直接把newInterval加进来就好了
    // 所以很慢
    // 把 newInterval 添加到 intervals 中，合并区间即可
    //  [[1,3],[2,5], [6,9]]
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ret;
        intervals.push_back(newInterval);
        if (intervals.size() < 2) return intervals;
        auto lambda = [&](vector<int> v1, vector<int> v2){return v1[0] < v2[0];};
        sort(intervals.begin(), intervals.end(), lambda);
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= r)
            {
                r = max(r, intervals[i][1]);
            } else {
                ret.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
        }
        ret.push_back({l, r});
        return ret;
    }


    vector <vector<int>> insert2(vector <vector<int>> &intervals, vector<int> &newInterval)
    {
        vector <vector<int>> ret;

        auto lambda = [&](vector<int> v1, vector<int> v2)
        { return v1[0] < v2[0]; };

        sort(intervals.begin(), intervals.end(), lambda);

        int l = newInterval[0], r = newInterval[1];
        //         [1,6]
        //  [[1,3],[6,9]], newInterval = [2,6]
        for (int i = 0; i < intervals.size(); ++i)
        {
            // 包含
            if (intervals[i][0] >= l && intervals[i][1] <= r) continue;
            // 相交
            else if (l >= intervals[i][0] && l <= intervals[i][1] || r >= intervals[i][0] && r <= intervals[i][1])
            {
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
            // 大于 相离
            else if (intervals[i][0] > r)
            {
                ret.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            }
            // 小于 相离
            else if(intervals[i][1] < l)
            {
                ret.push_back(intervals[i]);
            }
        }
        ret.push_back({l, r});
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
