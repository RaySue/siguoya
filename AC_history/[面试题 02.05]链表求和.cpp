// 给定两个用链表表示的整数，每个节点包含一个数位。
//
// 这些数位是反向存放的，也就是个位排在链表首部。 
//
// 编写函数对这两个整数求和，并用链表形式返回结果。 
//
// 
//
// 示例： 
//
// 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
//输出：2 -> 1 -> 9，即912
// 
//
// 进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢? 
//
// 示例： 
//
// 输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
//输出：9 -> 1 -> 2，即912
// 
// Related Topics 链表 数学 
// 👍 40 👎 0


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

    // 二刷 2020.12.19
    // 求和问题的范本
    // 注意：
    // 1. 链表需要 next
    // 2. next 之前需要判断是否为空
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* ptr = dummyHead;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry > 0)
        {
            int n1 = l1 == nullptr? 0 : l1->val;
            int n2 = l2 == nullptr? 0 : l2->val;
            int cur = n1 + n2 + carry;
            carry = cur / 10;
            cur = cur % 10;
            ptr->next = new ListNode(cur);
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            ptr = ptr->next;
        }
        return dummyHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
