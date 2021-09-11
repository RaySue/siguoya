//我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。 
//
// （这里，平面上两点之间的距离是欧几里德距离。） 
//
// 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。 
//
// 
//
// 示例 1： 
//
// 输入：points = [[1,3],[-2,2]], K = 1
//输出：[[-2,2]]
//解释： 
//(1, 3) 和原点之间的距离为 sqrt(10)，
//(-2, 2) 和原点之间的距离为 sqrt(8)，
//由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
//我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
// 
//
// 示例 2： 
//
// 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
//输出：[[3,3],[-2,4]]
//（答案 [[-2,4],[3,3]] 也会被接受。）
// 
//
// 
//
// 提示： 
//
// 
// 1 <= K <= points.length <= 10000 
// -10000 < points[i][0] < 10000 
// -10000 < points[i][1] < 10000 
// 
// Related Topics 堆 排序 分治算法 
// 👍 144 👎 0

ostream &operator<<(ostream &out, const vector<int> &v)
{
    for (auto a:v)
    {
        out << a << " ";
    }
    return out;
}

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一：思路(排序)：
    // 1. 先计算所有的points到(0,0)点的距离的平方，存入到 disVec 中，再得到一个idx。 time:O(N), Space:O(N)
    // 2. 然后对idx根据disVec进行排序，即argSort，time:O(NlogN)
    // 3. 取前K个结果即可
    // Complexity:
    // Time: O(NlogN)
    // Space: O(N)
    vector <vector<int>> kClosest1(vector <vector<int>> &points, int K)
    {
        vector <vector<int>> ans;
        if (points.empty()) return ans;
        vector<int> disVec(points.size(), 0);
        vector<int> idx(points.size(), 0);
        for (int i = 0; i < points.size(); ++i)
        {
            disVec[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            idx[i] = i;
        }
//        auto lambda = [=](int x1, int x2)->bool{return disVec[x1] < disVec[x2];};
//        auto lambda = [&](int x1, int x2)->bool{return disVec[x1] < disVec[x2];};
//        auto lambda = [=,&disVec](int x1, int x2)->bool{return disVec[x1] < disVec[x2];};
        auto lambda = [disVec](int x1, int x2) -> bool
        { return disVec[x1] < disVec[x2]; };
//        auto lambda = [&disVec](int x1, int x2)->bool{return disVec[x1] < disVec[x2];};
        sort(idx.begin(), idx.end(), lambda);

        for (int i = 0; i < K; ++i)
        {
            ans.push_back(points[idx[i]]);
        }
        return ans;
    }


    // 方法二：思路（堆）：
    // 使用优先队列来得到距离最小的K个点，在优先队列中指定好排序的方式即可
    // 1. 先将所有的Points 放入到priority_queue中 Time:O(N) Space:O(N)
    // 2. 然后将priority_queue中的前K个放入ans中
    // Complexity:
    // Time: O(NlogN) 堆调整的时间复杂度
    // Space: O(N)
    struct cmp
    {
        bool operator () (vector<int> a, vector<int> b)
        {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        }
    };

    vector <vector<int>> kClosest(vector <vector<int>> &points, int K)
    {
        vector <vector<int> > ans;
        priority_queue < vector<int> , vector<vector<int> >, cmp > pq;
        for (auto point:points)
        {
            pq.push(point);
        }
        for (int i = 0; i < K; ++i)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
