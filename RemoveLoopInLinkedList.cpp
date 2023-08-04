void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes\\

    unordered_map<Node *, bool> m;

    Node *temp = head;

    while (temp)
    {
        if (m[temp->next])
            temp->next = NULL;

        else
            m[temp] = true;

        temp = temp->next;
    }
}