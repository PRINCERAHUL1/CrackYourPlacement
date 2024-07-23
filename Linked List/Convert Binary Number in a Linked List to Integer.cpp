class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int r = head->val;

        while(head->next)
        {
            r = r*2 + head->next->val;
            head = head->next;
        }
        return r;

    }
};
