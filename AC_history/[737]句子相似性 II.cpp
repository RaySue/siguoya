// 给定两个句子 words1, words2 （每个用字符串数组表示），和一个相似单词对的列表 pairs ，判断是否两个句子是相似的。
//
// 例如，当相似单词对是 pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]]的时候，
// words1 = ["great", "acting", "skills"] 和 words2 = ["fine", "drama", "talent"] 是相似的。
//
// 注意相似关系是 具有 传递性的。例如，如果 "great" 和 "fine" 是相似的，"fine" 和 "good" 是相似的，则 "great" 和
//"good" 是相似的。
//
// 而且，相似关系是具有对称性的。例如，"great" 和 "fine" 是相似的相当于 "fine" 和 "great" 是相似的。
//
// 并且，一个单词总是与其自身相似。例如，句子 words1 = ["great"], words2 = ["great"], pairs = [] 是相似的
//，尽管没有输入特定的相似单词对。
//
// 最后，句子只会在具有相同单词个数的前提下才会相似。所以一个句子 words1 = ["great"] 永远不可能和句子 words2 = ["double
//plus","good"] 相似。
//
// 注：
//
//
// words1 and words2 的长度不会超过 1000。
// pairs 的长度不会超过 2000。
// 每个pairs[i] 的长度为 2。
// 每个 words[i] 和 pairs[i][j] 的长度范围为 [1, 20]。

// Related Topics 深度优先搜索 并查集 
// 👍 30 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class UnionFind
{
private:

    unordered_map <string, string> parent;
    unordered_map<string, int> rank;

public:

    UnionFind()
    {}

    string find(string x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(string x, string y)
    {
        if (!parent.count(x)) parent[x] = x;
        if (!parent.count(y)) parent[y] = y;

        string px = find(x);
        string py = find(y);
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
        unordered_map<string, string>::iterator iter = parent.begin();
        for (;iter != parent.end(); iter++)
        {
            if (iter->first == iter->second) res++;
        }
        return res;
    }

};

class Solution
{
public:
    bool areSentencesSimilarTwo(vector <string> &words1, vector <string> &words2, vector <vector<string>> &pairs)
    {
        if (words1.size() != words2.size()) return false;
        if (words1.empty() && words2.empty()) return true;
        UnionFind uf;
        for (int i = 0; i < pairs.size(); ++i)
        {
            uf.unite(pairs[i][0], pairs[i][1]);
        }
        for (int i = 0; i < words1.size(); ++i)
        {
            if (uf.find(words1[i]) != uf.find(words2[i])) return false;
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
