//反转一个单链表。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 进阶: 
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
// Related Topics 链表 
// 👍 1476 👎 0


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
    ListNode* pre = nullptr;


    void dfs(ListNode* head)
    {
        if (!head) return;
        head->next = pre;
        pre = head;
        dfs(head->next);
    }

    ListNode* reverseList(ListNode* head)
    {
        if (!head) return nullptr;
        dfs(head);
        return pre;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
