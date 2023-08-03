#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};
void printRecursive(BTNode<int> *root)
{

    if (!root)
        return; // edge case + base case in Btree

    cout << root->data << ":";

    if (root->left)
    {
        cout << "L=" << root->left->data;
    }
    cout << " ";
    if (root->right)
    {
        cout << "R=" << root->right->data;
    }
    cout << endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

BTNode<int> *takeinput()
{

    int rootdata;
    cout << "Enter Data" << endl;
    cin >> rootdata;

    if (rootdata == -1)
        return NULL;

    BTNode<int> *root = new BTNode<int>(rootdata);
    root->left = takeinput();
    root->right = takeinput();

    return root;
}

BTNode<int> *takeinputLevelWise()
{
    int rootdata;
    queue<BTNode<int> *> q;
    cout << "Enter root" << endl;
    cin >> rootdata;
    BTNode<int> *root = new BTNode<int>(rootdata);
    q.push(root);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        cout << "Enter left child of " << f->data << endl;
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BTNode<int> *child = new BTNode<int>(leftchild);
            q.push(child);
            f->left = child;
        }
        cout << "Enter right child of " << f->data << endl;
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BTNode<int> *child = new BTNode<int>(rightchild);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}
void printLevelWise(BTNode<int> *root)
{

    queue<BTNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        if (!f)
        {
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << " ";

            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}
int countNodes(BTNode<int> *root)
{

    if (!root)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void InOrderTraversal(BTNode<int> *root)
{
    if (!root)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
bool findNode(BTNode<int> *root, int key)
{

    if (!root)
        return false;

    if (root->data == key)
        return true;

    return (findNode(root->left, key) || findNode(root->right, key));
}
bool getpath(BTNode<int> *root, int val, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == val)
    {
        return true;
    }

    bool left = getpath(root->left, val, ans);
    bool right = getpath(root->right, val, ans);

    if (left || right)
    {
        return true;
    }
    ans.pop_back();
    return false;
}
/// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    //    BTNode<int> *root= new BTNode<int>(1);
    //    BTNode<int> *n1= new BTNode<int>(2);
    //    BTNode<int> *n2= new BTNode<int>(3);
    //
    //    root->left=n1;
    //    root->right=n2;

    vector<int> v;
    if (getpath(takeinputLevelWise(), 9, v))
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
        cout << "not found";
    return 0;
}
