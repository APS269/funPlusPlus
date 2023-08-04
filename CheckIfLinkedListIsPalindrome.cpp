bool isPalindrome(Node *head)
{
    // Your code here

    Node *temp = head;

    // Create a copy of the original linked list
    Node *copy = NULL;

    while (temp)
    {
        Node *newNode = new Node(temp->data);
        if (!copy)
            copy = newNode;

        else
        {
            newNode->next = copy;
            copy = newNode;
        }
        temp = temp->next;
    }

    // Reverse the copy of the linked listde *temp=head;
    Node *reverseHead = copy;

    while (head)
    {

        if (head->data != reverseHead->data)
            return false;

        head = head->next;
        reverseHead = reverseHead->next;
    }

    return true;
}