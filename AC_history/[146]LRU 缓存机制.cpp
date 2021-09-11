//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。 
//
// 
// 
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
// 
// 
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 3000 
// 0 <= value <= 104 
// 最多调用 3 * 104 次 get 和 put 
// 
// Related Topics 设计 
// 👍 1046 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class Node
{
public:
    int key;
    int value;
    Node *left;
    Node *right;
    Node(int key, int value) : key(key), value(value)
    {}
};

// 由左往右，最新的数据插在最左边，达到capacity删除最后边的节点
class doubleList
{
    Node *head;
    Node *tail;
public:
    doubleList()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
    }
    // 插 node 到最前面
    void insertAsFirst(Node *node)
    {
        node->left = head;
        node->right = head->right;
        head->right = node;
        node->right->left = node;
    }
    // O(1)时间删除一个节点
    void remove(Node *node)
    {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }
    // 返回最后一个节点
    Node *getLastNode()
    {
        return tail->left;
    }

};

class LRUCache
{
    int cap;
    int curSize;
    unordered_map<int, Node *> mp;
    doubleList cache;

public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
        this->curSize = 0;
    }

    int get(int key)
    {
        // 如果没有，直接返回-1
        if (mp.count(key) == 0) return -1;
        // 找到原节点删除后，插入新节点
        Node *tmp = mp[key];
        int val = tmp->value;
        Node *node = new Node(key, val);
        cache.remove(tmp);
        mp[key] = node;
        cache.insertAsFirst(node);
        return val;
    }

    void put(int key, int value)
    {
        // c查看是否存在
        if (mp.count(key) == 0)
        {
            Node *node = new Node(key, value);
            if (cap == curSize)
            {
                Node *tmp = cache.getLastNode();
                mp.erase(tmp->key);
                cache.remove(tmp);
                mp[key] = node;
                cache.insertAsFirst(node);
            } else
            {
                mp[key] = node;
                cache.insertAsFirst(node);
                this->curSize++;
            }
        } else
        {
            // 不要忘了修改value
            get(key);
            mp[key]->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
