#include <iostream>
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
TN *SEARCH(int item, TN **parent, TN *root)
{
    TN *curr = root;
    while (curr)
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

int main()
{
    int item;
    TN *root = new TN(4);
    root->left = new TN(2);
    root->right = new TN(7);

    root->left->left = new TN(1);
    root->left->right = new TN(3);

    root->right->left = new TN(6);
    root->right->right = new TN(9);

    TN *parent = NULL;
    cout << "ENTER DATA TO BE SEARCHED: " << endl;
    cin >> item;

    TN *curr = SEARCH(item, &parent, root);
    if (!curr)
    {
        cout << "ITEM NOT FOUND " << endl;
    }
    else if (!parent)
    {
        cout << item << " FOUND AT ROOT " << endl;
    }
    else
    {
        cout << item << " IS CHILD OF " << parent->data << endl;
    }
}