// 编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。
// 如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。
// 分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。
//
// 示例: 
//
// 输入: head = 3->5->8->5->10->2->1, x = 5
//输出: 1->2->3->10->5->8->5
// 
// Related Topics 链表 双指针 
// 👍 37 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // 二刷 2020.12.30
    // 和前面的 86 分隔链表一模一样，需要我们利用两个额外的指针来遍历链表，按题意存储即可
    ListNode* partition(ListNode* head, int x)
    {
        if (!head || !head->next) return head;
        ListNode *lessHead = new ListNode(-1);
        ListNode *pl = lessHead;
        ListNode *geHead = new ListNode(-1);
        ListNode *pge = geHead;
        while(head != nullptr)
        {
            if (head->val < x)
            {
                pl->next = head;
                pl = pl->next;
            } else{
                pge->next = head;
                pge = pge->next;
            }
            head = head->next;
        }
        pge->next = nullptr;
        pl->next = geHead->next;
        return lessHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
