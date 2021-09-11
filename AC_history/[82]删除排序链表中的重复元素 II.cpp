//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
// 
//
// 示例 2: 
//
// 输入: 1->1->1->2->3
//输出: 2->3 
// Related Topics 链表 
// 👍 415 👎 0


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

    // 一刷 2020.12.24
    // 思路：
    // 1. 特殊情况处理
    // 2. 建立 dummyHead 节点
    // 3. 利用 cur 从前向后遍历，如果重复就 next，并记录此时的数值
    // 4. 如果不相等，那么判断当前的数字是否出现过，如果出现就不添加
    // 5. 添加 cur 节点
    // 6. 最后需要断后，因为cur后面的节点不符合需求，不可以加进来
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) return nullptr;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *ptr = dummyHead;
        ListNode *cur = head;
        int tmp = INT_MIN;
        while (cur != nullptr)
        {
            if (cur->next != nullptr && cur->val == cur->next->val)
            {
                tmp = cur->val;
                cur = cur->next;
                continue;
            } else
            {
                if (cur->val == tmp)
                {
                    cur = cur->next;
                    continue;
                }
                ptr->next = cur;
                ptr = ptr->next;
            }
            cur = cur->next;
        }
        ptr->next = nullptr;  // 每次添加会把cur后面的节点添加进来
        return dummyHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
