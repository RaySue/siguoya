// 给出一个字符串数组 words 组成的一本英语词典。
// 从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返
// 回答案中字典序最小的单词。
//
// 若无答案，则返回空字符串。 
//
// 字典序的概念？ 这里是全字符串排序，而不是字典序
//
// 示例 1： 
//
// 输入：
//words = ["w","wo","wor","worl", "world"]
//输出："world"
//解释： 
//单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
// 
//
// 示例 2： 
//
// 输入：
//words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
//输出："apple"
//解释：
//"apply"和"apple"都能由词典中的单词组成。但是"apple"的字典序小于"apply"。
// 
//
//
//
// 提示： 
//
// 
// 所有输入的字符串都只包含小写字母。 
// words数组长度范围为[1,1000]。 
// words[i]的长度范围为[1,30]。 
// 
// Related Topics 字典树 哈希表 
// 👍 109 👎 0
// 思路：
//


//leetcode submit region begin(Prohibit modification and deletion)


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

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c:prefix)
        {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }

};

class Solution
{
public:
    // 特殊测试用例 ["a", "b", "ac", "bb"]
    // 方法一：
    // 思路：用Trie树
    // 1. 先对单词列表排序
    // 2. 然后对最短的单词 insert 到 Trie 中
    // 3. 然后长度大的字符先对前其n-1部分在Trie中查找是否存在prefix，如果存在 入 Trie
    // 4. 记录当前最长的成功入Trie的字符串
    // 5. 最后有多个最长字符串成功入Trie树后，对其最后一个字符排序，最小的返回
    string longestWord1(vector <string> &words)
    {
        if (words.empty() || words[0].empty()) return "";
        auto lambda = [&](string s1, string s2) -> bool
        { return s1.size() != s2.size() ? s1.size() < s2.size() : s1 < s2; };
        sort(words.begin(), words.end(), lambda);
        int maxLen = 0;
        string ans;
        Trie *trie = new Trie();

        for (int i = 2; i <= bucket.size(); ++i)
        {
            if (words[i].size() == 1) trie->insert(words[i]);
            else if (trie->startsWith(words[i].substr(0, words[i].size() - 1)))
            {
                trie.insert(words[i]);
                if (words[i].size() > maxLen)
                {
                    ans = words[i];
                    maxLen = words[i].size();
                }
            }
        }
        if (maxLenStr.empty())
        {
            sort(bucket[1].begin(), bucket[1].end());
            return bucket[1][0];
        }
        sort(maxLenStr.begin(), maxLenStr.end());
        return maxLenStr[0];
    }


    // 方法二：
    // 利用 Trie 树找公共前缀
    string longestWord(vector <string> &words)
    {
        if (words.empty() || words[0].empty()) return "";
        auto lambda = [&](string s1, string s2) -> bool{ return s1.size() != s2.size() ? s1.size() < s2.size() : s1 < s2; };
        sort(words.begin(), words.end(), lambda);
        int maxLen = 0;
        string ans = words[0];
        Trie *trie = new Trie();
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i].size() == 1) trie->insert(words[i]);
            else if (trie->startsWith(words[i].substr(0, words[i].size() - 1)))
            {
                trie->insert(words[i]);
                if (words[i].size() > maxLen)
                {
                    ans = words[i];
                    maxLen = words[i].size();
                }
            }
        }
        return ans;
    }


    // 方法三：
    // ["ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"] "e";
    // 1. 先对words进行排序，按照word的size进行排序，如果size相同那么就根据字符串顺序排序
    // 2. 利用集合进行筛选，筛选下一个长度的单词是否能由前一个组成，如果能就加入到集合
    // 3. 记录第一次出现的最长单词即可
    string longestWord3(vector <string> &words)
    {
        if (words.empty() || words[0].empty()) return "";
        unordered_set <string> checker;
        auto lambda = [&](string s1, string s2) -> bool
        { return s1.size() != s2.size() ? s1.size() < s2.size() : s1 < s2; };
        sort(words.begin(), words.end(), lambda);
        int maxLen = 0;
        string ans = words[0]; // 如果最长字符小于2的情况，那么就可以直接返回该结果
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i].size() == 1) checker.insert(words[i]);
            else if (checker.count(words[i].substr(0, words[i].size() - 1)))
            {
                checker.insert(words[i]);
                if (words[i].size() > maxLen)
                {
                    ans = words[i];
                    maxLen = words[i].size();
                }
            }
        }
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
