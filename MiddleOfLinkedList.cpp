/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */


    int getMiddle(Node *head)
    {
        
        
        if(!head) return -1;
        
        
        Node *fast=head;
        Node *slow=head;
        
        
        while( fast->next && fast->next->next)
        {
          slow=slow->next;
          
          fast=fast->next->next;
          
        }
        
        if(fast->next) return slow->next->data;
        
        return slow->data;
        
    }