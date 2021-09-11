//给定一个单链表 L：L0→L1→…→Ln-1→Ln ， 
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→… 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 示例 1: 
//
// 给定链表 1->2->3->4, 重新排列为 1->4->2->3. 
//
// 示例 2: 
//
// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3. 
// Related Topics 链表 
// 👍 398 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:

    // 方法一： 分割链表
    // 一刷 2020.12.28
    // 思路：
    // 1. 先利用 快慢指针 将链表一分为二
    // 2. 对后半部分逆序
    // 3. merge 两个链表
    // 4. 然后把 结果赋值给 head
    void reorderList(ListNode *head)
    {
        if (!head || !head->next) return;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        slow = reverse(slow);
        head = merge(head, slow);
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur != nullptr)
        {
            ListNode *buffer = cur->next;
            cur->next = pre;
            pre = cur;
            cur = buffer;
        }
        return pre;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        while (l1 != nullptr || l2 != nullptr)
        {
            if (!l1)
            {
                res->next = l2;
                l2 = l2->next;
                res = res->next;
            } else if (!l2){
                res->next = l1;
                l1 = l1->next;
                res = res->next;
            } else {
                res->next = l1;
                l1 = l1->next;
                res = res->next;
                res->next = l2;
                l2 = l2->next;
                res = res->next;
            }
        }
        return res;
    }

    // ------------------------------------
    // 方法二，利用 deque，注意不可以是 deque<int>，应该是deque<ListNode*>
    // 方法三，利用 vector<ListNode*> 道理是一样的
};
//leetcode submit region end(Prohibit modification and deletion)
