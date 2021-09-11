// 给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//
// 如果一个单词在其中一个句子中**只出现一次**，在另一个句子中却**没有出现**，那么这个单词就是不常见的。
//
// 返回所有不常用单词的列表。 
//
// 您可以按任何顺序返回列表。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet","sour"]
// 
//
// 示例 2： 
//
// 输入：A = "apple apple", B = "banana"
//输出：["banana"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= A.length <= 200 
// 0 <= B.length <= 200 
// A 和 B 都只包含空格和小写字母。 
// 
// Related Topics 哈希表 
// 👍 74 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Trie
{
private:
    Trie *next[26];
    int count;

public:
    vector<string> res;

public:
    Trie()
    {
        memset(next, 0, sizeof(next));
        count = 0;
    }

    void insert(string &word)
    {
        Trie *node = this;
        for (char c: word)
        {
            int idx = c - 'a';
            if (node->next[idx] == nullptr)
            {
                node->next[idx] = new Trie();
            }
            node = node->next[idx];
        }
        node->count++;
    }

    bool search(string &word)
    {
        Trie *node = this;
        for (char c: word)
        {
            int idx = c - 'a';
            if (node->next[idx] == nullptr) return false;
            node = node->next[idx];
        }
        return node->count > 0;
    }

    bool isValid(string &word)
    {
        Trie *node = this;
        for (char c: word)
        {
            int idx = c - 'a';
            if (node->next[idx] == nullptr) return false;
            node = node->next[idx];
        }
        return node->count == 1;
    }

    vector<string> run()
    {
        string path;
        Trie *node = this;
        findall(path, node);
        return res;
    }

    // 遍历字典树 找到只出现一次的字符串
    void findall(string &path, Trie *node)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (node->next[i] == nullptr)
            {
                if (node->count == 1)  // 某个字母开头的字符串，可能有多个
                {
                    res.push_back(path);
                    node->count = -1;
                }
                continue;
            }
            Trie* nodenext = node->next[i];
            path.push_back(i + 'a');
            findall(path, nodenext);
            path.pop_back();
            nodenext = node;
        }
    }

};

class Solution
{
public:

    // 一刷 2021.01.02
    // 这个题目可以用哈希表来完成
    // 1. 把 A B 利用哈希表存储，对应出现的个数
    // 2. 遍历 A 计算没有出现在 hash_map_B 中的单词，找到频数恰好为 1 的记录
    // 3. 遍历 B ~~~
    // 结果很慢
    /**
        Success:
        Runtime:8 ms, faster than 11.03% of C++ online submissions.
        Memory Usage:8.7 MB, less than 5.16% of C++ online submissions.
     */
    // 这是思路的问题
    // 正确的简洁的思路是：
    // 将 A B 放入 一个 trie 树中，然后只返回count 为 1 的字符串
    vector <string> uncommonFromSentences1(string A, string B)
    {
        vector <string> res;
        Trie trieA;
        Trie trieB;
        stringstream ssa(A);
        stringstream ssb(B);
        string s;
        while (ssa >> s) trieA.insert(s);
        while (ssb >> s) trieB.insert(s);

        ssa.clear();
        ssa.str(A);
        ssb.clear();
        ssb.str(B);

        while (ssa >> s)
        {
            if (trieA.isValid(s))
            {
                if (!trieB.search(s)) res.push_back(s);
            }
        }
        while (ssb >> s)
        {
            if (trieB.isValid(s))
            {
                if (!trieA.search(s)) res.push_back(s);
            }
        }
        return res;
    }

    // 将 A B 放入 Trie 中
    vector <string> uncommonFromSentences(string A, string B)
    {
        vector<string> res;
        Trie trie;
        stringstream ssa(A);
        stringstream ssb(B);
        string s;
        while (ssa >> s) trie.insert(s);
        while (ssb >> s) trie.insert(s);
        res = trie.run();
        return res;
    }

    // 老老实实利用 hash 表吧
    // 找到 A B 中只出现一次的字符
    vector <string> uncommonFromSentences3(string A, string B)
    {
        vector<string> res;
        unordered_map<string, int> mp;
        stringstream ss(A);
        string s;
        while(ss >> s)
        {
            mp[s] ++;
        }
        ss.clear();
        ss.str(B);
        while(ss >> s)
        {
            mp[s] ++;
        }
        unordered_map<string, int>::iterator iter = mp.begin();
        for (;iter != mp.end(); ++iter)
        {
            if (iter->second == 1)
            {
                res.push_back(iter->first);
            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
