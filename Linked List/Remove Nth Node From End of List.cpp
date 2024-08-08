class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* pre = temp;
        ListNode* cur = temp;

        for(int i=0; i<n+1; i++)
            cur = cur->next;
        
        while(cur != NULL)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;

        return temp->next;
    }
};
