//对链表进行插入排序。 
//
// 
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。 
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。 
//
// 
//
// 插入排序算法： 
//
// 
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。 
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。 
// 重复直到所有输入数据插入完为止。 
// 
//
// 
//
// 示例 1： 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2： 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5
// 
// Related Topics 排序 链表 
// 👍 253 👎 0


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

    // 1. 先找到逆序的节点
    // 2. 记录逆序的节点为 node
    // 3. 删除逆序的节点
    // 4. 从头向后找要插入的位置
    // 5. 插入
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->next->val >= cur->val)
            {
                cur = cur->next;
            } else
            {
                // 需要插入到前面的节点
                ListNode *node = cur->next;
                // delete
                cur->next = cur->next->next;
                // 从头找
                ListNode *pre = dummyHead;
                while (pre->next != nullptr && pre->next->val <= node->val)
                    pre = pre->next;
                // add
                node->next = pre->next;
                pre->next = node;
            }
        }
        return dummyHead->next;
    }


    // 二刷 插入排序 2020.12.26
    // 思路：
    // 1. 从头到尾找到第一个逆序的位置，即下一个数（next）大于当前数
    // 2. 把 next 赋值给 node 然后从链表中删除 node 即  cur->next = cur->next->next
    // 3. 从 pre 到尾找到第一个 pre->next 大于 next 的数
    // 4. 把 next 添加到 pre->next 之前
    // [-1,6,3,5,7,8]
    // [-1, 6, ,5,7,8]  3
    // [-1,3,6,5,7,8 ]
    // [-1, 3,4,5,7,8]
    ListNode *sortList(ListNode *head)
    {
        if (!head) return nullptr;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur = head;
        while (cur->next != nullptr)
        {
            // 从小到大
            if (cur->val <= cur->next->val)
            {
                cur = cur->next;
            } else
            {
                ListNode *node = cur->next;
                cur->next = cur->next->next;
                ListNode *pre = dummyHead;
                while(pre->next != nullptr && pre->next->val <= node->val) pre = pre->next;
                node->next = pre->next;
                pre->next = node;
            }
        }
        return dummyHead->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
