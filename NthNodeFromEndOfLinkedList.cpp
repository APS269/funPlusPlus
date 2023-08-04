int getNthFromLast(Node *head, int n)
{

    if (!head)
        return -1;

    Node *slow = head;
    Node *fast = head;

    // set the fast pointer n steps ahead of slow
    while (n--)
    {

        if (!fast)
            return -1; // if you find fast is Null in middle way simply no way to have nth node from end
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}