// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
// Related Topics 链表 
// 👍 707 👎 0


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

    // [1,2,3,4]
    // 1. 先考虑边界问题
    // 2. 取到 next 节点 head->next
    // 3. swapParis(next->next) 我们可以抽象的认为后续已经翻转好了
    // 4. 只需把 next->next 指向head即可，这时候head就变为了 next
    // 核心是要想到先拿到 next 节点
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
