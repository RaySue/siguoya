//班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 
//的朋友。所谓的朋友圈，是指所有朋友的集合。 
//
// 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你
//必须输出所有学生中的已知的朋友圈总数。 
//
// 
//
// 示例 1： 
//
// 输入：
//[[1,1,0],
// [1,1,0],
// [0,0,1]]
//输出：2 
//解释：已知学生 0 和学生 1 互为朋友，他们在一个朋友圈。
//第2个学生自己在一个朋友圈。所以返回 2 。
// 
//
// 示例 2： 
//
// 输入：
//[[1,1,0],
// [1,1,1],
// [0,1,1]]
//输出：1
//解释：已知学生 0 和学生 1 互为朋友，学生 1 和学生 2 互为朋友，所以学生 0 和学生 2 也是朋友，所以他们三个在一个朋友圈，返回 1 。
// 
//
// 
//
//[[1,0,1],
// [0,1,0],
// [1,0,1]]
//
// 提示： 
//
// 
// 1 <= N <= 200 
// M[i][i] == 1 
// M[i][j] == M[j][i] 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 381 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 非常简单的 dfs 解法
    // 每行代表一个人，我们先判断这个人是否check过，利用isVis
    // 如果这行存在 1，那么 1 这列对应的那个人 isVis 设置为true，即说明构成朋友圈
    // 当遍历到某个人的 isVis 已经为 true 的时候，说明已经加入到其他朋友圈了，返回 0
    // 否则 返回 1，对这个结果累加即可

    vector<bool> isVis;

    int dfs(vector <vector<int>> &M, int i)
    {
        if (isVis[i] == true) return 0;
        isVis[i] = true;
        for (int j = 0; j < M[0].size(); ++j)
        {
            if (M[i][j] == 1) dfs(M, j);
        }
        return 1;
    }

    int findCircleNum1(vector <vector<int>> &M)
    {
        isVis.resize(M.size());
        int ans = 0;
        for (int i = 0; i < M.size(); ++i)
        {
            ans += dfs(M, i);
        }
        return ans;
    }

    // ----------------------------------------------------------------

    // 方法二： 使用 并查集
    int findCircleNum(vector <vector<int>> &M)
    {
        int N = M.size();
        UnionFind uf(N);

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (M[i][j] == 1)
                {
                    uf.unite(i, j);
                }
            }
        }
        return uf.count();
    }

private:


//    ------------------ 并查集 -------------------
    class UnionFind
    {
    public:

        // 已知个体数为 N 的时候，通过一个 N 长度的数组可以初始化并查集
        UnionFind(int n)
        {
            parent = vector<int>(n, 0);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        // 个体合并
        void unite(int x, int y)
        {
            auto px = find(x);
            auto py = find(y);
            if (px != py)
            {
                parent[px] = py;
            }
        }

        // 寻找头目
        int find(int x)
        {
            if (x == parent[x])
            {
                return x;
            }

            return find(parent[x]);
        }

        // 计算数量
        int count()
        {
            int res = 0;
            for (int i = 0; i < parent.size(); i++)
            {
                res += (parent[i] == i);
            }

            return res;
        }

    private:
        vector<int> parent;
    };

};
//leetcode submit region end(Prohibit modification and deletion)
