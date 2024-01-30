#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;
struct TN
{
public:
    int data;
    TN *left;
    TN *right;
    TN(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(TN *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(TN *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int leftSTmax(TN *root)
{
    TN *curr = root;
    curr = curr->left;
    vector<int> v;
    stack<TN *> s;
    while (1)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        if (s.empty())
        {
            break;
        }
        curr = s.top();
        s.pop();
        v.push_back(curr->data);
        curr = curr->right;
    }
    int mx = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        mx = max(mx, v[i]);
    }
    return mx;
}
TN *search(int item, TN **parent, TN *root)
{
    TN *curr = root;
    while (1)
    {
        if (curr->data == item)
        {
            return curr;
            break;
        }
        else if (curr->data > item)
        {
            *parent = curr;
            curr = curr->left;
        }
        else if (curr->data < item)
        {
            *parent = curr;
            curr = curr->right;
        }
    }
    return NULL;
}
void deletion(int item, TN *root)
{
    TN *parent = NULL;
    TN *curr = search(item, &parent, root);

    if (curr == NULL)
    {
        cout << "DELETION NOT POSSIBLE " << endl;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        if (parent->left == curr)
        {
            parent->left = NULL;
            delete curr;
        }
        else if (parent->right == curr)
        {
            parent->right = NULL;
            delete curr;
        }
        return;
    }
    else if (curr->left != NULL && curr->right == NULL)
    {
        if (parent->left == curr)
        {
            parent->left = curr->left;
            delete curr;
        }
        else if (parent->right == curr)
        {
            parent->right = curr->left;
            delete curr;
        }
    }
    else if (curr->left == NULL && curr->right != NULL)
    {
        if (parent->left == curr)
        {
            parent->left = curr->right;
            delete curr;
        }
        else if (parent->right == curr)
        {
            parent->right = curr->right;
            delete curr;
        }
    }
    else if (curr->left != NULL && curr->right != NULL)
    {
        TN *temp = curr->right;
        TN *pred;
        while (temp->left)
        {
            pred = temp;
            temp = temp->left;
        }
        curr->data = temp->data;
        if (curr->right = temp)
        {
            curr->right = temp->right;
        }
        else
        {
            pred->left = temp->left;
        }
    }
}
int main()
{
    TN *root = new TN(4);
    root->left = new TN(2);
    root->right = new TN(7);

    root->left->left = new TN(1);
    root->left->right = NULL;

    root->right->left = new TN(6);
    root->right->right = new TN(9);
    root->right->right->left = new TN(8);
    root->right->right->right = new TN(10);

    int n, item;

    cout << "1.DISPLAY INORDER: " << endl;
    cout << "2.DISPLAY PREORDER: " << endl;
    cout << "3.DELETE: " << endl;
    cout << "4.EXIT " << endl;
    do
    {
        cout << "\nENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            cout << "ENTER ELEMENT TO DELETE: " << endl;
            cin >> item;
            deletion(item, root);
            break;

        default:
            break;
        }
    } while (n != 4);
}