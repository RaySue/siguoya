// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//
// 你应当保留两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例: 
//
// 输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5
// 
// Related Topics 链表 双指针 
// 👍 287 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:

    // 之前的思路
    // 思路类似于 插入排序, 无法通过所有的测试用例
    // cur 遍历链表
    // 1. 先找到 小于 x 的节点 a
    // 2. 把该节点单独拿出来 a
    // 3. 从头到尾找到第一个 >= x 的节点，将 a 房子 该节点之前
    // 1->4->3->2->5->2
    // 1->4->3->5->2 2
    // 1->2->4->3->5->2
    // 1->2->4->3->5 2
    // 1->2->2->4->3->5
    ListNode *partition1(ListNode *head, int x)
    {
        if (!head || !head->next) return head;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->val >= x)
            {
                cur = cur->next;
            } else
            {
                ListNode *node = cur->next;
                cur->next = cur->next->next;

                ListNode *pre = dummyHead;
                while (pre->next != nullptr && pre->next->val < node->val) pre = pre->next;

                node->next = pre->next;
                pre->next = node;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }

    // 一刷，2020.12.28，参考题解之后
    // 思路：
    // 1. 利用 lower 记录所有小于 x 的节点
    // 2. 利用 greater 记录所有大于等于 x 的节点
    // 3.
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lowerHead = new ListNode(-1);
        ListNode *greaterHead = new ListNode(-1);
        ListNode *pl = lowerHead;
        ListNode *pg = greaterHead;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                pl->next = head;
                pl = pl->next;
            } else
            {
                pg->next = head;
                pg = pg->next;
            }
            head = head->next;
        }
        // pg 此时是head->next，后面的节点都在，所以需要赋值为 nullptr
        pg->next = nullptr; // # 难点在这，如果你忘了这个步骤，那么就会导致出问题
        pl->next = greaterHead->next;
        return lowerHead->next;
    }


};


// 高手的简单解法，让我汗颜
// 非常简单，有时候使用额外空间就可以里面清晰明了的解决问题。
class Solution2
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head) return nullptr;

        ListNode *smaller_head = new ListNode(985); // 定义一个新的链表，用来存比x小的值
        ListNode *smaller = smaller_head; // 定义一个指针，初始位置指在上面的新链表的头结点
        ListNode *larger_head = new ListNode(211); // 定义一个新的链表，用来存比x大或等于x的值
        ListNode *larger = larger_head; // 定义一个指针，初始位置指在上面的新链表的头结点

        while (head)
        {
            if (head->val < x)
            {
                smaller->next = head;
                smaller = smaller->next;
            } else
            {
                larger->next = head;
                larger = larger->next;
            }
            head = head->next;
        }

        larger->next = nullptr;
        smaller->next = larger_head->next; // 由此可得，larger_head的头结点，其实是一个dummy值（哑值）

        return smaller_head->next; // 由此可得，smaller_head的头结点，其实是一个dummy值（哑值）
    }
};


//leetcode submit region end(Prohibit modification and deletion)
