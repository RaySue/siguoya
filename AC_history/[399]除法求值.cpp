// 给出方程式 A / B = k, 其中 A 和 B 均为用字符串表示的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。
// 如果结果不存在，则返回 -1.0。
//
// 输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。 
//
// 
//
// 示例 1： 
//
// 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"
//],["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//给定：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//返回：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 
//
// 示例 2： 
//
// 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], que
//ries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
// 
//
// 示例 3： 
//
// 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["
//a","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= equations.length <= 20 
// equations[i].length == 2 
// 1 <= equations[i][0].length, equations[i][1].length <= 5 
// values.length == equations.length 
// 0.0 < values[i] <= 20.0 
// 1 <= queries.length <= 20 
// queries[i].length == 2 
// 1 <= queries[i][0].length, queries[i][1].length <= 5 
// equations[i][0], equations[i][1], queries[i][0], queries[i][1] 由小写英文字母与数字组成 
// 
// Related Topics 并查集 图 
// 👍 272 👎 0


//leetcode submit region begin(Prohibit modification and deletion)



// 2021.01.06 每日一题
// 官网的答案解析非常好 ： https://leetcode-cn.com/problems/evaluate-division/solution/399-chu-fa-qiu-zhi-nan-du-zhong-deng-286-w45d/
// 带权的并查集，还是比较巧妙的一道题目，简单看了下提示，自己写的代码，却没有通过
// 思考了一下原因，是因为我比较纠结于使用 对半路径压缩 和 rank优化 ，而实际上这对于合并两个 簇的结果来说就变的非常复杂
// 这道题使用并查集来推理关系，在 find 过程 **路径压缩必须直接压缩到两层，否则非常复杂**，在 unite 过程 使用 平行四边形 法则，求解 两个集合老大的权重
// 然后再执行 find 操作的时候又进行了路径压缩 和 权重更新
// weights 都初始化为 1
//
//
// 普通的两个节点进行 合并 示意图 已知 x->px y->py x->y， 根据平行四边形 求 px -> py
// 两个集合的首领进行 合并
// 只对压缩到两层的并查集结果 进行合并
// x / y = val
// x = y * val
// 只有两个节点的时候 x == px，我们要把 y 作为父节点，即分母为父节点
// px * x = y * val
// px = y * val / x

// 三刷 2021.01.13
// 这个题目的核心考点：
// 并查集 +
// 1. 路径压缩时候的权重累乘
// 2. 合并两个集合时候的 平行四边形法则
/**
  所谓平行四边形法则，指 x / y = 2 变为 parent[px] = py 并求 weight[px]
  weight[x] * weight[px] = weight[y] * weight[py]   初始化的时候 weight[x] = 1

      x -(?)> y
     /       /
    x -(2)> y

    x / y = 2
*/

class Solution
{

public:
    vector<double>
    calcEquation(vector <vector<string>> &equations, vector<double> &values, vector <vector<string>> &queries)
    {
        UnionFind uf;
        for (int i = 0; i < equations.size(); ++i)
        {
            uf.add(equations[i][0]);
            uf.add(equations[i][1]);
            uf.unite(equations[i][0], equations[i][1], values[i]);
        }
        vector<double > ret(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i)
        {
            string x = queries[i][0];
            string y = queries[i][1];
            if (!uf.isIn(x) || !uf.isIn(y)) continue;
            if (uf.find(x) != uf.find(y)) continue;
            ret[i] = uf.divide(x, y);
        }
        return ret;
    }

private:
    class UnionFind
    {
    private:
        unordered_map <string, string> parent;
        unordered_map<string, double> weight;

    public:

        UnionFind()
        {};

        // find 过程，也是路径压缩的过程
        // 路径压缩的过程，针对此题而言就是对权重进行合并
        string find(string x)
        {
            if (x != parent[x])
            {
                string oriX = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[oriX];
            }
            return parent[x];
        }

        void unite(string x, string y, double val)
        {
            string px = find(x);
            string py = find(y);
            if (px != py)
            {
                parent[px] = py;
                weight[px] = weight[y] * val / weight[x];
            }
        }

        void add(string x)
        {
            if (!parent.count(x))
            {
                parent[x] = x;
                weight[x] = 1.0;
            }
        }

        bool isIn(string x)
        {
            return parent.count(x);
        }

        double divide(string x, string y)
        {
            return weight[x] / weight[y];
        }
    };

};
//leetcode submit region end(Prohibit modification and deletion)
