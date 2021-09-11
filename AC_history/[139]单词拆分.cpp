//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。 
//
// 说明： 
//
// 
// 拆分时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 
//
// 示例 2： 
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
// Related Topics 动态规划 
// 👍 795 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Trie
{
private:
    unordered_map<char, Trie*> next;
    bool isEnd;

public:
    Trie()
    {
        isEnd = false;
    }


    void insert(string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->next[word[i]] == nullptr)
            {
                node->next[word[i]] = new Trie();
            }
            node = node->next[word[i]];
        }
        node->isEnd = true;
    }

    bool prefix(string &prefix)
    {
        Trie *node = this;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (node->next[word[i]] == nullptr) return false;
            node = node->next[word[i]];
        }
        return true;
    }

    bool find(string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->next[word[i]] == nullptr) return false;
            node = node->next[word[i]];
            if (node->isEnd) node = this;
        }
        return true;
    }

};

class Solution
{
public:
    //    "aaaaaaa"
    //    ["aaaa","aa"]
    bool wordBreak(string s, vector <string> &wordDict)
    {
        Trie trie;
        for (string wd:wordDict)
        {
            trie.insert(wd);
        }
        return trie.find(s);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
