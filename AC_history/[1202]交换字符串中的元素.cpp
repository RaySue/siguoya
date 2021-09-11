// 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
//
//
// 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。 
//
// 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。 
//
// 
//
// 示例 1: 
//
// 输入：s = "dcab", pairs = [[0,3],[1,2]]
//输出："bacd"
//解释： 
//交换 s[0] 和 s[3], s = "bcad"
//交换 s[1] 和 s[2], s = "bacd"
// 
//
// 示例 2： 
//
// 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//
//输出："abcd"
//解释：
//交换 s[0] 和 s[3], s = "bcad"
//交换 s[0] 和 s[2], s = "acbd"
//交换 s[1] 和 s[2], s = "abcd" 
//
// 示例 3： 
//
// 输入：s = "cba", pairs = [[0,1],[1,2]]
//输出："abc"
//解释：
//交换 s[0] 和 s[1], s = "bca"
//交换 s[1] 和 s[2], s = "bac"
//交换 s[0] 和 s[1], s = "abc"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10^5 
// 0 <= pairs.length <= 10^5 
// 0 <= pairs[i][0], pairs[i][1] < s.length 
// s 中只含有小写英文字母 
// 
// Related Topics 并查集 数组 
// 👍 106 👎 0


// leetcode submit region begin(Prohibit modification and deletion)
// 思路：
// 暴力方法，可能性太多了，因为每个

// 要不是提示，我其实想不到用并查集，还是理解的不够深刻，凡是具有传递关系的，首先要考虑使用并查集
// 1. 将 pairs 加入到并查集中
// 2. 双层遍历所有节点，如果后一个位置和前一个位置在一个集合中，
// 就判断时候后一个位置的字典序小于前一个位置来判断是否需要对其进行交换
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector <vector<int>> &pairs)
    {
        UnionFind uf(s.size());
        for (auto pair: pairs)
        {
            uf.unite(pair[0], pair[1]);
        }

        //// TLE 因为这里的复杂度达到了 O(N^2)
//        for (int i = 0; i < s.size(); ++i)
//        {
//            for (int j = i + 1; j < s.size(); ++j)
//            {
//                if (uf.isSameSet(i, j))
//                {
//                    if (s[j] < s[i]) swap(s[i], s[j]);
//                }
//            }
//        }

        // 对每个根节点下的所有字符进行排序，然后，每个位置都换成对应set中字典序最小的，
        unordered_map<int, string> root;
        for (int i = 0; i < s.size(); ++i)
        {
            root[uf.find(i)].push_back(s[i]);
        }
        // 这里的引用非常重要
        for (auto &[k, v]: root)
        {
            auto lambda  = [&](char c1, char c2)->bool {return c1 > c2;};
            sort(v.begin(), v.end(), lambda);
        }
        // 以集合的头领为 key ，对 key 下的所有的字符换为顺序的
        for (int i = 0; i < s.size(); ++i)
        {
            int pi = uf.find(i);
            s[i] = root[pi].back();
            root[pi].pop_back();
        }
        return s;
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
            if (x != parent[x])
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
                if (rank[px] < rank[py])
                {
                    parent[px] = py;
                } else if (rank[px] > rank[py])
                {
                    parent[py] = px;
                } else
                {
                    parent[py] = px;
                    rank[py]++;
                }
            }
        }

        int isSameSet(int x, int y)
        {
            return find(x) == find(y);
        }

    };
};
//leetcode submit region end(Prohibit modification and deletion)
