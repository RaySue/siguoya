//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
// Related Topics 分治算法 
// 👍 64 👎 0


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

    // 基于迭代
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *p = dummyHead;
        while(l1 && l2)
        {
            if (l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1?l1:l2;
        return dummyHead->next;
    }

    // 基于递归
    // Complexity：
    // Time: O(min(N, M))
    // Space: O(min(N, M))
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
