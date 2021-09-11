//
// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//
// 要求返回这个链表的 深拷贝。 
//
// 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示： 
//
// 
// val：一个表示 Node.val 的整数。 
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为 null 。 
// 
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
// Related Topics 哈希表 链表 
// 👍 422 👎 0


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

class Solution
{
public:

    // naive O(N) O(N) 解法
    // 思路：
    // 1. 先对所有的 next 节点进行赋值，并记录每个节点及其赋值节点的映射关系memory - time: O(N) space: O(N)
    // 2. 利用memory的信息，对赋值后的random进行clone
    // Complexity
    // Time: O(N)
    // Space: O(N)
    Node *copyRandomList(Node *head)
    {
        Node* cloneHead = new Node(-1);
        cloneHead->next = head;
        Node* po = head;
        Node* pc = cloneHead;
        unordered_map<Node*, Node*> mem;
        while(po != nullptr)
        {
            pc->next = new Node(po->val);
            mem[po] = pc->next;
            po = po->next;
            pc = pc->next;
        }
        po = head;
        pc = cloneHead;
        while(po != nullptr)
        {
            if (po->random != nullptr)
            {
                pc->next->random = mem[po->random];
            }
            po = po->next;
            pc = pc->next;
        }
        return cloneHead->next;
    }
    // naive O(N) O(N) 解法
    // 思路：
    // 1. 利用 unordered_map 来记录 {老节点：新节点}
    // 2. For next： 遍历 old 链表，如果 unordered_map 中记录了old的next的新的节点，那么直接赋值，如果没有那么直接new一个，存入到memory
    // 3. For random： 如果 unordered_map 记录了old的random指向的新节点已经建立好，那么直接赋值，否则new一个，等到next指向的时候，就可以直接查到
    Node *copyRandomList2(Node *head)
    {
        if (!head) return nullptr;
        unordered_map < Node * , Node * > memory;

        Node *ptr = head;
        Node *clonedRandomList = new Node(ptr->val);
        Node *clonedRandomListPtr = clonedRandomList;
        memory[ptr] = clonedRandomListPtr;
        while (ptr != nullptr)
        {
            if (ptr->next != nullptr)
            {
                if (memory.count(ptr->next))
                {
                    clonedRandomListPtr->next = memory[ptr->next];
                } else
                {
                    clonedRandomListPtr->next = new Node(ptr->next->val);
                    memory[ptr->next] = clonedRandomListPtr->next;
                }
            }
            if (ptr->random != nullptr)
            {
                if (memory.count(ptr->random))
                {
                    clonedRandomListPtr->random = memory[ptr->random];
                } else
                {
                    clonedRandomListPtr->random = new Node(ptr->random->val);
                    memory[ptr->random] = clonedRandomListPtr->random;
                }
            }
            ptr = ptr->next;
            clonedRandomListPtr = clonedRandomListPtr->next;
        }
        return clonedRandomList;
    }


    // O(N) O(1) 解法
    // 思路：
    // 1. 先在每个老节点后面复制一个新的节点， 用于记录
    // 2. 然后遍历老节点的random指向的位置，就是老节点random指向的节点的next节点
    // 3. 去掉奇数的老节点即可

};
//leetcode submit region end(Prohibit modification and deletion)
