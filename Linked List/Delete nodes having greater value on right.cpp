class Solution
{
    public:
    
    Node *rev(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    
    Node *compute(Node *head)
    {
        head = rev (head);
        
        int max = head->data;
        Node* cur = head->next;
        Node* prev = head;
        
        while(cur != nullptr)
        {
            if(cur->data >= max)
            {
                prev = cur;
                max = cur->data;
            }
            else
            {
                prev->next = cur->next;
            }
            cur = cur->next;
        }
        
        head = rev(head);
        return head;
        
    }
    
};
