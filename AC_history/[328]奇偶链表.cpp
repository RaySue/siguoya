//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。 
//
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
//
//
// 示例 2: 
//
// 输入: 2->1->3->5->6->4->7->NULL 
//输出: 2->3->6->7->1->5->4->NULL 
//
// 说明: 
//
// 
// 应当保持奇数节点和偶数节点的相对顺序。 
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。 
// 
// Related Topics 链表 
// 👍 295 👎 0


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
class Solution {
public:

    // 前言：
    // 刚开始的思路是 odd->next = odd->next->next; odd = odd->next;
    // 但是这样 even 就没法玩了，因为odd的操作导致了很多结点的丢失

    // 思路：
    // 让 odd 和 even 交替的进行变换
    // 1. odd->next 指向 even->next
    // 2. odd = odd->next;
    // 3. even->next 指向 odd->next
    // 4. even = even->next;
    // 5. odd->next = evenHead;
    // end

    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode *oddPtr = head;
        ListNode *evenHead = head->next;
        ListNode *evenPtr = evenHead;
        while(oddPtr->next != nullptr && evenPtr->next != nullptr)
        {
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;
            evenPtr->next = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = evenHead;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
