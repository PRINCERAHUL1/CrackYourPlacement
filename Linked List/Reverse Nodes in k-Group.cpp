class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0, head);
        
        int total = 0;
        ListNode* cur = head;

        while(cur != NULL)
        {
            total++;
            cur = cur->next;
        }

        cur = head;
        ListNode* nxt = NULL;
        ListNode* pre = dummy;

        while(total >= k)
        {
            cur = pre->next;
            nxt = cur->next;

            for(int i=1; i<k; i++)
            {
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }

            pre = cur;
            total = total - k;
        }

        return dummy->next;
    }
};
