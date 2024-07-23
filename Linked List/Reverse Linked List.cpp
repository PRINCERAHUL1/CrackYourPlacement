class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;

        while(head!=nullptr)
        {
            ListNode* nextNode= head->next;
            head->next = pre;
            pre = head;
            head = nextNode;
        }

        return pre;
    }
};
