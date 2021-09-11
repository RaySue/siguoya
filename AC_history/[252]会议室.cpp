//给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，请你判断一个人是否能够参加
//这里面的全部会议。 
//
// 示例 1: 
//
// 输入: [[0,30],[5,10],[15,20]]
//输出: false
// 
//
// 示例 2: 
//
// 输入: [[7,10],[2,4]]
//输出: true
// 
// Related Topics 排序 
// 👍 38 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 先看下那个区间在前面，然后再判断两个区间是否有交集
    bool isIntersect(vector<int> interval1, vector<int> interval2)
    {
        int a1, b1, a2, b2;
        a1 = interval1[0];
        b1 = interval1[1];
        a2 = interval2[0];
        b2 = interval2[1];
        if (a2 > a1)
        {
            if (a2 < b1) return true;
        } else
        {
            if (a1 < b2) return true;
        }
        return false;
    }

    // 暴力  Time out
    // 时间复杂度： O(N^2)
    bool canAttendMeetings1(vector <vector<int>> &intervals)
    {
        if (intervals.empty()) return true;
        for (int i = 0; i < intervals.size(); ++i)
        {
            for (int j = i + 1; j < intervals.size(); ++j)
            {
                if (isIntersect(intervals[i], intervals[j])) return false;
            }
        }
        return true;
    }

    // ---------------------------------------------------------------
    // ---------------------------------------------------------------
    // ---------------------------------------------------------------

    // 排序
    // 时间复杂度： O(Nlog(N))
    // 空间复杂度： O(1)
    bool canAttendMeetings(vector <vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [=](vector<int> x,vector<int> y)->bool{return x[0] < y[0];});
        int maxVal = -1;
        for (int i = 0; i < intervals.size(); ++i)
        {
//            if (intervals[i - 1][1] > intervals[i][0]) return false;
            if(intervals[i][0] < maxVal) return false;
            maxVal = intervals[i][1];
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
