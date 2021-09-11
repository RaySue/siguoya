//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 
//
// 示例： 
//
// 给你这个链表：1->2->3->4->5 
//
// 当 k = 2 时，应当返回: 2->1->4->3->5 
//
// 当 k = 3 时，应当返回: 3->2->1->4->5 
//
// 
//
// 说明： 
//
// 
// 你的算法只能使用常数的额外空间。 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
// Related Topics 链表 
// 👍 800 👎 0


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




    // 建立 dummy 节点
    // 1. pre 节点为待翻转区之前的节点
    // 2. start 是待翻转区的首位置
    // 3. end 是待翻转区的尾节点
    // 4. buffer 用于保存后续的节点
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* end = dummyHead;

        while(end != nullptr)
        {
            for (int i = 0; end != nullptr && i < k; ++i)
            {
                end = end->next;
            }
            if (!end) break;

            ListNode* buffer = end->next; // 未翻转区
            end->next = nullptr;

            ListNode* start = pre->next;
            pre->next = reverse(start); // 翻转
            start->next = buffer;

            pre = start;
            end = start;
        }
        return dummyHead->next;
    }

    ListNode *reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur != nullptr)
        {
            ListNode* buffer = cur->next;
            cur->next = pre;
            pre = cur;
            cur = buffer;
        }
        return pre;
    }

    // 1->2->3->4->5
    // 1. 先弄个dummyHead -1，pre=dummyHead, end=dummyHead如下：
    //     -1->1->2->3->4->5
    // 2. 对end向后移动k步，注意要保证end != nullptr， 否则会报错
    // 3. start = pre->next; end 断链交给buffer
    //     -1-> 1->2 3->4->5
    // 4. 对 start reverse，返回的结果是 2->1， 此时start变为了 1
    //     -1-> 2->1 3->4->5
    // 5. pre->next = reverse的结果
    //     -1->2->1
    // 6. start接链 buffer
    //    1->3->4->5
    // 7. pre = start; end = start;
    // 最终的结果返回 dummyHead->next


















    // 三刷 2020.12.26
    // 思路：pre -> 待翻转区（start，end） 保存 未翻转区 (buffer)
    // 1->2->3->4->5
    // -1-> 1->2 ->3->4->5

//    ListNode *reverse(ListNode *head)
//    {
//        ListNode *pre = nullptr;
//        ListNode *cur = head;
//        while(cur != nullptr)
//        {
//            ListNode *buffer = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = buffer;
//        }
//        return pre;
//    }
//
//    ListNode *reverseKGroup(ListNode *head, int k)
//    {
//        ListNode *dummyHead = new ListNode(-1);
//        dummyHead->next = head;
//        ListNode *pre = dummyHead;
//        ListNode *end = dummyHead;
//        while (end != nullptr)
//        {
//            for (int i = 0; i < k && end != nullptr; ++i) end = end->next;
//            if (end == nullptr) break;
//            ListNode *buffer = end->next;
//            end->next = nullptr;
//            ListNode *start = pre->next;
//            pre->next = reverse(start);
//            start->next = buffer;
//            pre = start;
//            end = start;
//        }
//        return dummyHead->next;
//    }






























//    ListNode *reverseKGroup(ListNode *head, int k)
//    {
//        ListNode *dummyHead = new ListNode(0);
//        dummyHead->next = head;
//        ListNode *pre = dummyHead;
//        ListNode *end = dummyHead;
//        while (end->next != nullptr)
//        {
//            for (int i = 0; i < k && end != nullptr; ++i)
//                end = end->next;
//            if (end == nullptr) break;
//            ListNode *start = pre->next;  // 指定翻转的首位置
//            ListNode *next = end->next;   // 存储 end 后面的链子到 next
//            end->next = nullptr;          // 断后
//            pre->next = reverse(start);   // start 逆序, start 由头变为了尾
//            start->next = next;           // 连后
//            pre = start;                  // 初始状态：start 的前一个节点 pre
//            end = pre;                    // 初始装： end 也在pre的位置
//        }
//        return dummyHead->next;
//    }


};
//leetcode submit region end(Prohibit modification and deletion)
