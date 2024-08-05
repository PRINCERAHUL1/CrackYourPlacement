class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL)
            return 0;
        
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(left>1)
        {
            pre = cur;
            cur = cur->next;
            left--;
            right--;
        }

        ListNode* start = pre;
        ListNode* end = cur;
        ListNode* temp = NULL;

        while(right>0)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            right--;
        }
        
        if(start != NULL)
            start->next = pre;
        else
            head = pre;
        
        end->next = cur;
        
        return head;
    }
};
