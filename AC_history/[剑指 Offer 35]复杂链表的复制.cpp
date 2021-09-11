//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指
//向链表中的任意节点或者 null。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 示例 4： 
//
// 输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
// 
//
// 
//
// 提示： 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random 为空（null）或指向链表中的节点。 
// 节点数目不超过 1000 。 
// 
//
// 
//
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-point
//er/ 
//
// 
// Related Topics 链表 
// 👍 117 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution1
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *clonedList = new Node(head->val);
        Node *ptr = head;
        Node *cPtr = clonedList;
        unordered_map < Node * , Node * > mem;
        mem[ptr] = cPtr;
        while (ptr != nullptr)
        {
            if (ptr->next != nullptr)
            {
                if (!mem.count(ptr->next))
                {
                    cPtr->next = new Node(ptr->next->val);
                    mem[ptr->next] = cPtr->next;
                } else
                {
                    cPtr->next = mem[ptr->next];
                }
            }

            if (ptr->random != nullptr)
            {
                if (!mem.count(ptr->random))
                {
                    cPtr->random = new Node(ptr->random->val);
                    mem[ptr->random] = cPtr->random;
                } else
                {
                    cPtr->random = mem[ptr->random];
                }
            }
            cPtr = cPtr->next;
            ptr = ptr->next;
        }
        return clonedList;
    }
};


class Solution
{
public:

    // 利用 hash map
    // 1. 先遍历 clone next，并用 hash map 记录 head 和 cloned 的关系
    // 2. 再遍历 head 根据 hash map 把clone 的 random 补上
    Node *copyRandomList(Node *head)
    {
        Node *cloneList = new Node(-1);
        unordered_map < Node*, Node*> mem;
        Node *ph = head;
        Node *pc = cloneList;
        while (ph != nullptr)
        {
            pc->next = new Node(ph->val);
            mem[ph] = pc->next; // 这里的关系 1
            ph = ph->next;
            pc = pc->next;
        }
        ph = head;
        pc = cloneList;
        while (ph != nullptr)
        {
            if (ph->random) pc->next->random = mem[ph->random];  // 1 对应这里的关系 2
            ph = ph->next;
            pc = pc->next;
        }
        return cloneList->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
