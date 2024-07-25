class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        vector<int> p;
        while(head!=NULL)
        {
            p.push_back(head->val);
            head = head->next;
        }
        
        int start=0;
        int end= p.size() -1;

        while(start<end)
        {
            if(p[start] !=  p[end])
                return false;
            
            start++;
            end--;
        }
        return true;

    }
};
