bool detectLoop(Node *head)
{
    // your code here
    unordered_map<Node *, bool> m;

    if (!head)
        return false;

    Node *temp = head;

    while (temp)
    {

        if (m[temp->next])
            return true;

        m[temp] = true;

        temp = temp->next;
    }

    return false;
}