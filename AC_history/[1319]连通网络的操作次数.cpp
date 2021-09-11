// 用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。
//
// 网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。 
//
// 给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连
//通所需的最少操作次数。如果不可能，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：n = 4, connections = [[0,1],[0,2],[1,2]]
//输出：1
//解释：拔下计算机 1 和 2 之间的线缆，并将它插到计算机 1 和 3 上。
// 
//
// 示例 2： 
//
// 
//
// 输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
//输出：2
// 
//
// 示例 3： 
//
// 输入：n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
//输出：-1
//解释：线缆数量不足。
// 
//
// 示例 4： 
//
// 输入：n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 10^5 
// 1 <= connections.length <= min(n*(n-1)/2, 10^5) 
// connections[i].length == 2 
// 0 <= connections[i][0], connections[i][1] < n 
// connections[i][0] != connections[i][1] 
// 没有重复的连接。 
// 两台计算机不会通过多条线缆连接。 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 68 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 2021.01.23 每日一题
    // 思路：
    // 典型的使用并查集
    // 这个问题的初始化就是 n 个节点，根据连线对 n 个节点进行 两两组团
    // 1. 如果两个节点已经在一个组里了，那么就保留这根网线
    // 2. 剩余的网线数 小于 未连接的节点，返回-1
    // 3. 剩余的网线数 大于 未连接的节点，返回未连接节点的个数
    int makeConnected(int n, vector <vector<int>> &connections)
    {
        UnionFind uf(n);
        int cableNum = 0;
        for (int i = 0; i < connections.size(); ++i)
        {
            int x = connections[i][0];
            int y = connections[i][1];
            if (uf.find(x) != uf.find(y))
            {
                uf.unite(x, y);
            } else
            {
                cableNum++;
            }
        }
        if (cableNum < uf.count() - 1) return -1;
        return uf.count() - 1;
    }

private:

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

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
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
                } else
                {
                    parent[px] = py;
                }
            }
        }

        int count()
        {
            int ret = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                if (i == parent[i]) ret++;
            }
            return ret;
        }

    };

};
//leetcode submit region end(Prohibit modification and deletion)
