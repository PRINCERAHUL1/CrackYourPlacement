class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        ListNode* h = removeElements(head->next, val);

        if(head->val == val)
            return h;
        head->next = h;
        return head;

    }
};
