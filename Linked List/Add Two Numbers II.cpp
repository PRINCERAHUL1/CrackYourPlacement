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
class Solution {
public:

    stack<int> convert(ListNode* l) {
        stack<int> s;
        while (l != NULL) {
            s.push(l->val);
            l = l->next;
        }
        return s;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = convert(l1);
        stack<int> s2 = convert(l2);

        ListNode* head = NULL;
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry != 0) {
            int s = carry;

            if (!s1.empty()) {
                s += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                s += s2.top();
                s2.pop();
            }

            ListNode* l3 = new ListNode(s % 10);
            l3->next = head;
            head = l3;

            carry = s / 10;
        }

        return head;
    }
};
