#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;

    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }
};
void printTree(TreeNode<int> *root)
{
    if (!root)
        return;

    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        cout << "Enter no of children of " << f->data << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {

            int childData;
            cout << "Enter " << i << " th child of  " << f->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        cout << f->data << ":";
        for (int i = 0; i < f->children.size(); i++)
        {

            cout << f->children[i]->data << " ,";
            q.push(f->children[i]);
        }

        cout << endl;
    }
}
int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }

    return ans;
}
int height(TreeNode<int> *root)
{

    if (!root)
        return 0;
    int mx = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        mx = max(mx, height(root->children[i]));
        // if(childHeight>mx)
        //   mx=childHeight;
    }
    return mx + 1;
}

void NodesAtLevelK(TreeNode<int> *root, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        NodesAtLevelK(root->children[i], k - 1);
    }
}
int countLeafNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (root->children.size() == 0)
        return 1;

    int ans = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}
void countLeafNodes2(TreeNode<int> *root, int &ans)
{
    int a = 0;

    if (root->children.size() == 0)
    {
        a++;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        countLeafNodes2(root->children[i], a);
    }
    ans = a;
}

void preorderTraversal(TreeNode<int> *root)
{

    if (!root)
        return;

    cout << root->data << ",";

    for (int i = 0; i < root->children.size(); i++)
    {
        preorderTraversal(root->children[i]);
    }
}

void postOrderTraversal(TreeNode<int> *root)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << ",";
}

void deleteTree(TreeNode<int> *root)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
        deleteTree(root->children[i]);

    delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    delete root;
    postOrderTraversal(root);

    return 0;
}
