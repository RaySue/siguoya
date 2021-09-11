// 设计一个方法，找出任意指定 单词 在一本书中的出现频率。
//
// 你的实现应该支持如下操作： 
//
// 
// WordsFrequency(book)构造函数，参数为字符串数组构成的一本书 
// get(word)查询指定单词在书中出现的频率 
// 
//
// 示例： 
//
// WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple
//", "he", "have", "a", "pen"});
//wordsFrequency.get("you"); //返回0，"you"没有出现过
//wordsFrequency.get("have"); //返回2，"have"出现2次
//wordsFrequency.get("an"); //返回1
//wordsFrequency.get("apple"); //返回1
//wordsFrequency.get("pen"); //返回1
// 
//
// 提示： 
//
// 
// book[i]中只包含小写字母 
// 1 <= book.length <= 100000 
// 1 <= book[i].length <= 10 
// get函数的调用次数不会超过100000 
// 
// Related Topics 设计 哈希表 
// 👍 12 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Trie
{
private:
    int count;
//    Trie *next[26];
    unordered_map<char, Trie*> next;

public:
    Trie()
    {
        count = 0;
//        memset(next, 0, sizeof(next));
    }

    void insert(string &word)
    {
        Trie *node = this;
        for (char c: word)
        {
//            if (!node->next[c - 'a'] == nullptr)  // 利用数组
            if (!node->next.count(c - 'a'))
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->count++;
    }

    int find(string &word)
    {
        Trie *node = this;
        for (char c:word)
        {
            if (node->next[c - 'a'] == nullptr) return 0;
            node = node->next[c - 'a'];
        }
        return node->count;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c:prefix)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return true;
    }

};

class WordsFrequency
{

private:
    Trie *trie;

public:
    WordsFrequency(vector <string> &book)
    {
        trie = new Trie();
        for (string word:book)
        {
            trie->insert(word);
        }
    }

    int get(string word)
    {
        return trie->find(word);
    }

};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
//leetcode submit region end(Prohibit modification and deletion)
