// 给出 字符串 text 和 字符串列表 words,
// 返回所有的索引对 [i, j] 使得在索引对范围内的子字符串 text[i]...text[j]（包括i 和 j）
// 属于字符串列表 words。
//
// 
//
// 示例 1: 
//
// 输入: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
//输出: [[3,7],[9,13],[10,17]]
// 
//
// 示例 2: 
//
// 输入: text = "ababa", words = ["aba","ab"]
//输出: [[0,1],[0,2],[2,3],[2,4]]
//解释: 
//注意，返回的配对可以有交叉，比如，"aba" 既在 [0,2] 中也在 [2,4] 中
// 
//
// 
//
// 提示: 
//
// 
// 所有字符串都只包含小写字母。 
// 保证 words 中的字符串无重复。 
// 1 <= text.length <= 100 
// 1 <= words.length <= 20 
// 1 <= words[i].length <= 50 
// 按序返回索引对 [i,j]（即，按照索引对的第一个索引进行排序，当第一个索引对相同时按照第二个索引对排序）。 
// 
// Related Topics 字典树 字符串 
// 👍 13 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 错误的思路： 对 text 构建 Trie 树，真是太傻了，导致 search 方法非常臃肿，而且逻辑特别麻烦

// 把 words 建立 Trie 树
class Trie
{
private:

    bool isEnd;
    Trie *next[26];

public:
    Trie()
    {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c:word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    vector <vector<int>> search(string text, int start)
    {
        Trie *node = this;
        int ptr = start;
        vector <vector<int>> ans;
        while (ptr <= text.size())
        {
            int idx = -1;
            for (int i = 0; i < 26; ++i)
            {
                if (node->next[i] != nullptr) // 这里保证了ptr不会越界
                {
                    if (i + 'a' == text[ptr])
                    {
                        idx = i;
                    }
                }
            }
            if (node->isEnd)
            {
                ans.push_back({start, ptr - 1});
            }
            if (idx < 0) return ans;
            node = node->next[idx];
            ptr++;
        }
        return ans;
    }
};


class Solution
{
public:
    // 利用 find 方法
    // find 方法返回找到的字符串的首位置
    //	Success:
    //	Runtime:8 ms, faster than 86.67% of C++ online submissions.
    //	Memory Usage:8.7 MB, less than 57.63% of C++ online submissions.
    vector <vector<int>> indexPairs1(string text, vector <string> &words)
    {
        vector <vector<int>> ans;
        for (string word:words)
        {
            int index = text.find(word);
            while (index != -1)
            {
                int end = index + word.size();
                ans.push_back({index, end - 1});  // 添加 range
                index = text.find(word, index + 1);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // 利用字典树，得到的结果直接就是有序的
    // 1. 建立 Trie 树，包含insert方法和变形的search方法
    // 2. 将 words 每个字符串 insert 到 Trie 树中
    // 3. 遍历 text， 从第一个字符开始查找，如果没找到就返回空，继续查找，直到找完为止
    vector <vector<int>> indexPairs(string text, vector <string> &words)
    {
        vector <vector<int>> ans;
        Trie *trieNode = new Trie();
        for (string word:words)
        {
            trieNode->insert(word);
        }
        for (int i = 0; i < text.size(); ++i)
        {
            vector <vector<int>> range = trieNode->search(text, i);
            if (range.empty()) continue;
            ans.insert(ans.end(), range.begin(), range.end());
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
