// 用一个 非空 单链表来表示一个非负整数，然后将这个整数加一。
//
// 你可以假设这个整数除了 0 本身，没有任何前导的 0。 
//
// 这个整数的各个数位按照 高位在链表头部、低位在链表尾部 的顺序排列。 
//
// 示例: 
//       [3,2,1]
// 输入: [1,2,3]
//输出: [1,2,4]
// 
// Related Topics 递归 链表 
// 👍 55 👎 0


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

    // 一刷 2020.12.28
    // 思路很简单
    // 1. 对链表逆序
    // 2. 令 carry = 1 开始进位, 注意一下 [9] 的进位情况即可
    // 3. 逆序返回
    ListNode *plusOne(ListNode *head)
    {
        if (!head) return head;
        head = reverse(head);
        ListNode *p = head;
        int carry = 1;
        bool first = true;
        while (p != nullptr)
        {
            int tmp = p->val + carry;
            p->val = tmp % 10;
            carry = tmp / 10;
            if (carry > 0 && p->next == nullptr)
            {
                p->next = new ListNode(1);
                carry = 0;
            }
            p = p->next;
        }

        return reverse(head);
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *buffer = cur->next;
            cur->next = pre;
            pre = cur;
            cur = buffer;
        }
        return pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
