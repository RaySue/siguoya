//
// 树是一张连通的无向无环图
//
// 给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。
//                         0
// 示例 1：              4 1 2 3
//
// 输入: n = 5, 边列表 edges = [[0,1], [0,2], [0,3], [1,4]]
//输出: true 
//
// 示例 2:
//
// 输入: n = 5, 边列表 edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
//输出: false 
//
// 注意：你可以假定边列表 edges 中不会出现重复的边。由于所有的边是无向边，边 [0,1] 和边 [1,0] 是相同的，因此不会同时出现在边列表 edg
//es 中。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 77 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 和 冗余连接 一样简单的思路
// 并查集可以用来判断根据一些 edges 构成的图是否满足树的条件，即是否成环
class Solution
{
public:
    bool validTree(int n, vector <vector<int>> &edges)
    {
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            // 合并两个有公共祖先的节点，说明有环了
            if (uf.find(x) == uf.find(y)) return false;
            uf.unite(x, y);
        }
        // 注意了，还有可能出现的情况是两个子树的情况
        return uf.count() == 1;
    }

private:

    class UnionFind
    {
    private:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

    public:
        UnionFind(int n)
        {
            for (int i = 0; i < n; ++i)
            {
                parent[i] = i;
                rank[i] = 0;
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
                } else {
                    parent[px] = py;
                    rank[py] ++;
                }
            }
        }

        int count()
        {
            int res = 0;
            unordered_map<int, int>::iterator iter = parent.begin();
            for (;iter != parent.end(); iter++)
            {
                if (iter->first == iter->second)
                {
                    res ++;
                }
            }
            return res;
        }
    };

};
//leetcode submit region end(Prohibit modification and deletion)
