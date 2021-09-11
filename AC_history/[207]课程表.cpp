// 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
//
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1] 
//
// 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？ 
//
// 
//
// 示例 1: 
//
// 输入: 2, [[1,0]] 
//输出: true
//解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。 
//
// 示例 2: 
//
// 输入: 2, [[1,0],[0,1]]
//输出: false
//解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。 
//
// 
//
// 提示：
// 
// 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。 
// 你可以假定输入的先决条件中没有重复的边。 
// 1 <= numCourses <= 10^5 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 648 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;


public:

    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            if(rank[px] > rank[py])
            {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        }

    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

};

class Solution
{
public:

    // 2020.12.28 一刷 拓扑排序
    //
    // 本题输入 prerequisites 为空的时候，返回 true，即没有任何的限制条件，可以学习任意数目的课程
    // 题意其实就是要判断 prerequisites 是否有环
    // 判断是否存在一种拓扑排序

    // [[1,4],[2,4],[3,1],[3,2]]
    bool canFinish(int numCourses, vector <vector<int>> &prerequisites)
    {
        UnionFind uf(numCourses);
        for (vector<int> pair:prerequisites)
        {
            int x = pair[0], y = pair[1];
            if (uf.find(x) != uf.find(y))
            {
                uf.unite(x, y);
            } else {
                return false;
            }
        }
        return true;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
