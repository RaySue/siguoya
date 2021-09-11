// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
// 注意: 
//
// 
// 可以认为区间的终点总是大于它的起点。 
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。 
// 
//
// 示例 1: 
//
// 
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
// 
//
// 示例 2: 
//
// 
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
// 
//
// 示例 3: 
//
// 
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
// 
// Related Topics 贪心算法 
// 👍 276 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // [[1,2], [2,3], [3,4], [1,3]]
    // [1,2] [1,3] [2,3] [3,4]
    // [1,2] [3,1] [2,3] [3,4]
    /**
     *
        [1,2] [3,4] [5,6] 都没有交集
        [1,3] [2,4] [5,6] 前面两个有交集
        [1, 3] [3, 5] [5, 8]  中间和两边的有重叠
        [1, 8] [3, 6] [8, 9]  前面的包含next，并和 next next 有交集

        注意题意 边界相互“接触”，但没有相互重叠
        1. 先对区间的起始位置排序
        2. 如果两个区间有重叠
        2.1 如果前面的区间包含后面的区间，那么删除前面的区间
        2.2 如果前面的区间不包含后面的区间，那么删除后面的区间
     */
    //  排序 + 两层循环的朴素解法， 复杂度较高 O(N^2)
    int eraseOverlapIntervals1(vector <vector<int>> &intervals)
    {
        int count = 0;
        auto lambda = [&](vector<int> i1, vector<int> i2) -> bool
        { return i1[0] == i2[0] ? i1[1] < i2[1] : i1[0] < i2[0]; };
        sort(intervals.begin(), intervals.end(), lambda);
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > intervals[i][1]) continue;
            for (int j = i + 1; j < intervals.size(); ++j)
            {
                if (intervals[i][1] >= intervals[j][1]) // contain
                {
                    count++;
                    swap(intervals[i][0], intervals[i][1]);
                } else if (intervals[i][1] > intervals[j][0])  // intersect
                {
                    count++;
                    swap(intervals[j][0], intervals[j][1]);
                } else if (intervals[i][1] < intervals[j][0]) // separation
                {
                    break;
                }
            }
        }
        return count;
    }


    // -----------------------------------------------------------
    // 核心是排序，和记录前一个的边界，一次遍历即可
    // 1. 先对区间的左边界进行排序
    // 2. 遍历 intervals 每一步记录最大的右区间，如果前一个右区间，大于当前的左区间，那么就删掉，计算保留目前最大右区间
    // [[0,2],[1,3],[2,4],[3,5],[4,6]]
    // [[0,2],[1,3],[2,4],[3,5],[4,6]]
    int eraseOverlapIntervals(vector <vector<int>> &intervals)
    {
        int count = 0;
        if (intervals.empty()) return count;
        auto lambda = [&](vector<int> l1, vector<int> l2) -> bool
        { return l1[0] == l2[0] ? l1[1] < l2[1] : l1[0] < l2[0]; };
        sort(intervals.begin(), intervals.end(), lambda);
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (r > intervals[i][0])
            {
                count ++;
                r = min(r, intervals[i][1]);
            } else {
                r = intervals[i][1];
            }
        }
        return count;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
