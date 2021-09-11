//在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横
//坐标就足够了。开始坐标总是小于结束坐标。 
//
// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足 xsta
//rt ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的
//最小数量。 
//
// 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。 
// 
//
// 示例 1： 
//
// 
//输入：points = [[10,16],
//               [2,8],
//               [1,6],
//               [7,12]]
//输出：2
//解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球 
//
// 示例 2： 
//
// 
//输入：points = [[1,2],[3,4],[5,6],[7,8]]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：points = [[1,2],[2,3],[3,4],[4,5]]
//输出：2
// 
//
// 示例 4： 
//
// 
//输入：points = [[1,2]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：points = [[2,3],[2,3]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 0 <= points.length <= 104 
// points[i].length == 2 
// -231 <= xstart < xend <= 231 - 1 
// 
// Related Topics 贪心算法 排序 
// 👍 221 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 朴素版本的思路：
    // 1. 先对 区间进行排序，按照左边界进行排序，如果左边界相等那么再按照右边界排序  O(N*logN)
    // 2. 从头开始计算 前两个区间的交集，然后再和后面的区间计算交集，如果没有交集那么 count++ 即需要一箭

    // 相交三种情况：
    // 1. 包含 i1[0] <= i2[0] && i1[1] > i2[1]  交集 [i2[0], i2[1]]
    // 2. 相交 i1[0] <= i2[0] && i1[1] < i2[1]  交集 [i2[0], i1[1]]
    // 3. 内切 i1[0] <= i2[0] && i1[1] == i2[1]  交集 [i2[0], i1[1]]
    // 4. 外切 i1[0] <= i2[0] && i1[1] == i2[0]  交集 [i2[0], i1[1]]
    // 相离
    // i1[0] < i2[0] && i1[1] < i2[0]
    // 由于是排序之后的，所以 i1[0] < i2[0] 必然满足


    // 最小数量的箭引爆气球
    // 找到两个相交区间的交集并计算和下一个区间的交集，更新，如果没有交集，加个箭
    void mergeInterval(vector<int> &i1, vector<int> &i2)
    {
        if (i1[1] < i2[0])
        {
            i2 = {};
            return;
        };
        i2[0] = max(i1[0], i2[0]);
        i2[1] = min(i1[1], i2[1]);
    }
    int findMinArrowShots1(vector <vector<int>> &points)
    {
        if (points.empty()) return 0;
        auto lambda = [&](vector<int> p1, vector<int> p2) -> bool
        { return p1[0] != p2[0] ? p1[0] < p2[0] : p1[1] < p2[1]; };
        sort(points.begin(), points.end(), lambda);
        int count = 1;
        int p = 1;
        while (p < points.size())
        {
            mergeInterval(points[p - 1], points[p]);
            if (points[p].empty()) count++;
            p++;
        }
        return count;
    }


    // 简化版本
    int findMinArrowShots(vector <vector<int>> &points)
    {
        if (points.empty()) return 0;
        // O(N*logN)
        auto lambda = [&](vector<int> p1, vector<int> p2) -> bool
        { return p1[1] < p2[1]; };

        sort(points.begin(), points.end(), lambda);
        int r = points[0][1];  // 记录前区间的右边界类似寻找集合
        int ret = 1;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] > r)
            {
                r = max(r, points[i][1]);
                ++ret;
            }
        }
        return ret;
    }

    // 如果不使用排序
    // 初始化 count = points.size()
    // O(N^2) 对一个区间和所有的区间计算交集， 出现一个交集那么就 count --;
    // 对合并后的区间进行记录，如果合并了那么就对points[i] = {} 赋值为空即可
};
//leetcode submit region end(Prohibit modification and deletion)
