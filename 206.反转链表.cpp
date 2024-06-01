/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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

/*
// 双指针
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;    // 快指针
        ListNode *pre = nullptr; // 慢指针

        // 快指针到达末端
        while (cur != nullptr)
        {
            // 将下一位置保存
            ListNode *tmp = cur->next;
            // 改变指向
            cur->next = pre;
            // 更新慢指针
            pre = cur;
            // 更新快指针
            cur = tmp;
        }
        // 慢指针到达尾节点
        return pre;
    }
};
*/
class Solution
{
public:
    ListNode *reverse(ListNode *cur, ListNode *pre)
    {
        if (cur == nullptr)
            return pre;
        else
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            // 在reverse函数中，递归调用时应该返回递归函数的结果，
            // 而不是直接调用递归函数。这可能导致函数没有正确返回结果
            return reverse(tmp, cur);
        }
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverse(head, nullptr);
    }
};

// @lc code=end
