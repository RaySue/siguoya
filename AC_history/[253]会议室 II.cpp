//给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，为避免会议冲突，同时要考虑
//充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。 
//
// 示例 1: 
//
// 输入: [[0, 30],[5, 10],[15, 20]]
//输出: 2 
//
// 示例 2: 
//
// 输入: [[7,10],[2,4]]
//输出: 1 
// Related Topics 堆 贪心算法 排序 
// 👍 209 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // [[0, 30],[5, 10],[15, 20]]

    // 所谓的上下车算法
    // 如果每次开会都先结束，那么就没有重叠，
    // 如果连续开会 n 次，那么至少需要 n 个会议室
    // 利用 tree map 对开会时间进行排序
    // 对开会的起始时间 +1， 对开会的终止时间 -1
    // 这样如果没有重叠那么map的value就是 1 -1 1 -1 ...
    // 如果有重叠， 1 1 1 -1 -1 -1, 那么显然最多需要三个会议室
    // 一刷 2021.02.03
    int minMeetingRooms(vector <vector<int>> &intervals)
    {
        map<int, int> record;
        for (vector<int> interval:intervals)
        {
            record[interval[0]] ++;
            record[interval[1]] --;
        }
        int ret = 0;
        int cur = 0;
        for (auto [k, v]:record)
        {
            cur += v;
            ret = max(cur, ret);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
