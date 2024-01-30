#include <iostream>
#include <stack>
using namespace std;
struct TN
{
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

void InorderNR(TN *root)
{
    TN *pt = root;
    stack<TN *> s;
    while (1)
    {
        while (pt)
        {
            s.push(pt);
            pt = pt->left;
        }
        if (s.empty())
        {
            break;
        }
        pt = s.top();
        s.pop();
        cout << pt->data << " ";
        pt = pt->right;
    }
}
void PreorderNR(TN *root)
{
    TN *pt = root;
    stack<TN *> s;
    while (1)
    {
        while (pt)
        {
            cout << pt->data << " ";
            s.push(pt);
            pt = pt->left;
        }
        if (s.empty())
        {
            break;
        }
        pt = s.top();
        s.pop();
        pt = pt->right;
    }
}
void PostorderNR(TN *root)
{
    stack<TN *> s;

    while (1)
    {
        while (root)
        {
            s.push(root->right);
            s.push(root);
            root = root->left;
        }
        if (s.empty())
        {
            break;
        }
        root = s.top();
        s.pop();
        if (root->right == s.top())
        {
            s.pop();
            s.push(root);
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = NULL;
        }
    }
}

int main()
{
    TN *root = new TN(1);
    root->left = new TN(2);
    root->right = new TN(3);

    root->left->left = new TN(4);
    root->left->right = new TN(5);

    root->right->left = new TN(6);
    root->right->right = new TN(7);

    InorderNR(root);
    cout << endl;
    PreorderNR(root);
    cout << endl;
    PostorderNR(root);
}