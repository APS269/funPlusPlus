struct Node *reverseList(struct Node *head)
{
    // code here
    // return head of reversed list

    if (!head)
        return head; // if head is NULL

    if (!(head->next))
        return head; // if there is a single node

    Node *prev = NULL;

    Node *curr = head;

    while (curr)
    {

        Node *n = curr->next;

        curr->next = prev;

        prev = curr;
        curr = n;
    }

    return prev;
}