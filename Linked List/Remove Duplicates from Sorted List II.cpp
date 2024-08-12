class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while(head != NULL)
        {
            if(head->next != NULL && head->val == head->next->val)
            {
                while(head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }

                pre->next = head->next;
            }
            else
                pre = pre->next;
            
            head = head->next;
        }
        return dummy->next;
    }
};
