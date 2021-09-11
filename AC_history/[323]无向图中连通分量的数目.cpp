//给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点），请编写一个函数来计算无向图中连通分量的数目。 
//
// 示例 1: 
//
// 输入: n = 5 和 edges = [[0, 1], [1, 2], [3, 4]]
//
//     0          3
//     |          |
//     1 --- 2    4 
//
//输出: 2
// 
//
// 示例 2: 
//
// 输入: n = 5 和 edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
//
//     0           4
//     |           |
//     1 --- 2 --- 3
//
//输出:  1
// 
//
// 注意: 
//你可以假设在 edges 中不会出现重复的边。而且由于所以的边都是无向边，[0, 1] 与 [1, 0] 相同，所以它们不会同时在 edges 中出现。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 61 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int countComponents(int n, vector <vector<int>> &edges)
    {
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            uf.unite(edges[i][0], edges[i][1]);
        }
        return uf.count();
    }

private:

    class UnionFind
    {

    private:

        vector<int> parent;
        vector<int> rank;  // 深度

    public:

        UnionFind(int n) : parent(n, -1), rank(n, 0)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
            }
        }

        // rank 记录树的深度
        // 由于是自底向上构建的，所以开始的时候的深度都默认为0，或1都可以
        // 两个rank相等的树合成一个树的时候需要对作为根的树 rank ++
        void unite(int x, int y)
        {
            int px = find(x);
            int py = find(y);
            if (px != py)
            {
                if (rank[px] > rank[py])
                {
                    parent[py] = px;
                } else if (rank[py] > rank[px])
                {
                    parent[px] = py;
                } else
                {
                    rank[py] ++;
                    parent[px] = py;
                }
            }
        }

        int find(int x)
        {
            while (x != parent[x])
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        int count()
        {
            int res = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                res += (parent[i] == i);
            }
            return res;
        }

    };


};
//leetcode submit region end(Prohibit modification and deletion)
