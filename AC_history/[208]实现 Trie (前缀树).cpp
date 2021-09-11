//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。 
//
// 示例: 
//
// Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");   
//trie.search("app");     // 返回 true 
//
// 说明: 
//
// 
// ****你可以假设所有的输入都是由小写字母 a-z 构成的。 ****
// 保证所有输入均为非空字符串。 
// 
// Related Topics 设计 字典树 
// 👍 458 👎 0


// 1. Trie 头结点不包含任何字符(头结点的next需要用nullptr初始化)除了根节点以外每个节点都只包含一个字符
// 2. 从根节点到某一个节点路径上经过的字符连接起来就是对应的字符串
// 3. 每个节点的所有子节点包含的字符串都不同

//leetcode submit region begin(Prohibit modification and deletion)

// 利用数组实现的
class Trie
{
private:
    bool isEnd;
    Trie *next[26];
public:
    /** Initialize your data structure here. */
    // 构建过程出现新的字母就需要调用改初始化，利用 new 关键字
    Trie()
    {
        // 定义变量时一定要进行初始化
        isEnd = false;
        memset(next, 0, sizeof(next));
//        for (int i = 0; i < 26; ++i) this->next[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;  // 类似链表中的 ListNode *ptr = head;
        for (char c:word)
        {
            int idx = static_cast<int>(c - 'a');
            if (node->next[idx] == nullptr)
            {
                node->next[idx] = new Trie();
            }
            node = node->next[idx];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this;  // 类似链表中的 ListNode *ptr = head;
        for (char c:word)
        {
            int idx = static_cast<int>(c - 'a');
            node = node->next[idx];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c:prefix)
        {
            int idx = static_cast<int>(c - 'a');
            node = node->next[idx];
            if (node == nullptr) return false;
        }
        return true;
    }
};

namespace hash_map
{
    // 利用 unordered_map 实现 Trie 树
    class Trie
    {
    private:
        int count; // 带词频统计
        unordered_map<char, Trie *> root;

    public:
        /** Initialize your data structure here. */
        Trie()
        {
            count = 0;
        }

        /** Inserts a word into the trie. */
        void insert(string word)
        {
            Trie *node = this;  // 类似链表中的 ListNode *ptr = head;
            for (char c:word)
            {
                if (!node->root.count(c))
                {
                    node->root[c] = new Trie();
                }
                node = node->root[c];
            }
            node->count++;
        }

        /** Returns if the word is in the trie. */
        bool search(string word)
        {
            Trie *node = this;
            for (char c:word)
            {
                if (!node->root.count(c)) return false;
                node = node->root[c];
            }
//            cout << word << " " << node->count << endl;
            return node->count > 0;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix)
        {
            Trie *node = this;
            for (char c:prefix)
            {
                if (!node->root.count(c)) return false;
                node = node->root[c];
            }
            return true;
        }
    };
}



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)
