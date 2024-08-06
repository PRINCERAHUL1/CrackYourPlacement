class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;

        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while(second)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next=temp1;
            first = temp1;
            second = temp2;
        }
    }
};
