#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
struct TN
{
    int data;
    TN *left;
    TN *right;

    TN(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};
TN *Search(int item, TN **parent, TN *root)
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
vector<int> inorder(TN *root)
{
    stack<TN *> s;
    vector<int> v;
    TN *pt = root;

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
        else
        {
            pt = s.top();
            s.pop();
            v.push_back(pt->data);
            pt = pt->right;
        }
    }
    return v;
}
int main()
{
    TN *root = new TN(4);
    root->left = new TN(34);
    root->right = new TN(7);

    root->left->left = new TN(3);
    root->left->right = new TN(43);

    root->right->left = new TN(71);
    root->right->right = new TN(702);

    vector<int> v = inorder(root);
    int mx = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        mx = max(mx, v[i]);
    }
    TN *parent = NULL;
    TN *curr = Search(mx, &parent, root);
    cout << curr->data << " ";
}