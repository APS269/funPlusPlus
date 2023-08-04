Node *removeDuplicates(Node *head)
{
    // Your code goes here

    if (!head || !head->next)
        return head;

    Node *temp = head;

    while (temp && temp->next)
    {
        while (temp->next && temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }

    return head;
}