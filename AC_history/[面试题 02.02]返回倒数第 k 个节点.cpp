//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。 
//
// 注意：本题相对原题稍作改动 
//
// 示例： 
//
// 输入： 1->2->3->4->5 和 k = 2
//输出： 4 
//
// 说明： 
//
// 给定的 k 保证是有效的。 
// Related Topics 链表 双指针 
// 👍 49 👎 0


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

    // 二刷 2020.12.19
    // 返回倒数第二个节点的值，所以用快慢指针
    // 如果是要返回正数第 k 个节点，那就太简单了
    int kthToLast(ListNode *head, int k)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        fast = head;
        for (int i = 0; i < k; ++i)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
