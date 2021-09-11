//编写一个程序，找到两个单链表相交的起始节点。 
//
// 如下面的两个链表： 
//
// 
//
// 在节点 c1 开始相交。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, s
//kipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1
//,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
// 
//
// 
//
// 示例 2： 
//
// 
//
// 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
//输出：Reference of the node with value = 2
//输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4
//]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
// 
//
// 
//
// 示例 3： 
//
// 
//
// 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
//输出：null
//输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而
// skipA 和 skipB 可以是任意值。
//解释：这两个链表不相交，因此返回 null。
// 
//
// 
//
// 注意： 
//
// 
// 如果两个链表没有交点，返回 null. 
// 在返回结果后，两个链表仍须保持原有的结构。 
// 可假定整个链表结构中没有循环。 
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。 
// 
// Related Topics 链表 
// 👍 796 👎 0


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
    /**
     *
     * 输入两个链表，这两个链表可能相交，即有一部分是重合在一起的，找到其开始相交的节点
     *
     *
     * @param headA
     * @param headB
     * @return
     */
    // 利用hash map
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
    {
        unordered_map < ListNode * , int > record;

        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa != NULL)
        {
            record[pa]++;
            pa = pa->next;
        }

        while (pb != NULL)
        {
            if (record.count(pb)) return pb;
            pb = pb->next;
        }
        return NULL;
    }

    // 思路：
    // pa 从 headA 出发，pb 从 headB 出发，如果pa == pb 那么直接返回，（两个链表相交前长度相同的情况）
    // pa 先走完，那么从headB走，pb走完，让其再headA从头走，它们相等的时候返回即可，或者是节点或者都为nullptr
    // 垃圾代码典范
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        if (headA && !headB || !headA && headB) return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != nullptr && pb != nullptr)
        {
            if (pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        if (pa == nullptr)
        {
            pa = headB;
            while (pa != nullptr && pb != nullptr)
            {
                if (pa == pb) return pa;
                pa = pa->next;
                pb = pb->next;
            }
            pb = headA;
            while (pa != nullptr && pb != nullptr)
            {
                if (pa == pb) return pa;
                pa = pa->next;
                pb = pb->next;
            }
            return pa;
        }
        else
        {
            pb = headA;
            while (pa != nullptr && pb != nullptr)
            {
                if (pa == pb) return pa;
                pa = pa->next;
                pb = pb->next;
            }
            pa = headB;
            while (pa != nullptr && pb != nullptr)
            {
                if (pa == pb) return pa;
                pa = pa->next;
                pb = pb->next;
            }
            return pa;
        }
    }

    // 利用递归代码瘦身失败，因为传入之后，headA和headB已经改变了
    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB)
    {
        // 边界处理
        if (headA == headB) return headA;
        if (!headA && headB || !headB && headA) return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != nullptr && pb != nullptr)
        {
            if (pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        if (!pa)
        {
            pa = headB;
            return getIntersectionNode(pa, pb);
        } else {
            pb = headA;
            return getIntersectionNode(pa, pb);
        }
    }

    // 参考 高手的代码之后的写法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA && headB || headA && !headB) return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != pb)
        {
            pa = !pa? headB:pa->next;
            pb = !pb? headA:pb->next;
        }
        return pa;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
