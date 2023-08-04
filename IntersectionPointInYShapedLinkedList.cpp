int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here

    if (!head1)
        return -1;
    if (!head2)
        return -1;

    Node *cur1 = head1;
    Node *cur2 = head2;

    while (cur1 != cur2)
    {

        if (!cur1)
            cur1 = head2;

        if (!cur2)
            cur2 = head1;

        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    if (!cur2)
        return -1;

    return cur1->data;
}