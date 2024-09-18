class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        
        Node* cur=root;

        while(cur->left != NULL)
        {
            Node* temp=cur;

            while(cur != NULL)
            {
                cur->left->next=cur->right;
                cur->right->next= cur->next==NULL? NULL:cur->next->left;
                cur=cur->next; 
            }

            cur= temp->left;
        }

        return root;
    }
};
