class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }

    ListNode* merge(ListNode* h1, ListNode* h2)
    {
        ListNode* fh = NULL;
        ListNode* ft = NULL;

        while(h1 != NULL && h2 != NULL)
        {
            if(fh == NULL && ft == NULL)
            {
                if(h1->val > h2->val)
                {
                    fh = h2;
                    ft = h2;
                    h2 = h2->next;
                }
                else
                {
                    fh = h1;
                    ft = h1;
                    h1 = h1->next;
                }
            }
            else
            {
                if (h1->val < h2->val)
                {
                    ft->next = h1;
                    ft = ft->next;
                    h1 = h1->next;
                }
                else
                {
                    ft->next = h2;
                    ft = ft->next;
                    h2 = h2->next;
                }
            }
            
        }

        if(h1 != NULL)
            ft->next = h1;
        
        if(h2 != NULL)
            ft->next = h2;

        return fh;
    }

};
