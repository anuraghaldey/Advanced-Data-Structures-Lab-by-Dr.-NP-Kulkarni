#include <iostream>
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
bool checkBST(TN *root)
{
    TN *curr = root;
    if(curr->data<curr->right->data)
}
int main()
{
    TN *root = new TN(4);
    root->left = new TN(2);
    root->right = new TN(6);

    root->left->left = new TN(1);
    root->left->right = new TN(3);

    root->right->left = new TN(5);
    root->right->right = new TN(7);
}