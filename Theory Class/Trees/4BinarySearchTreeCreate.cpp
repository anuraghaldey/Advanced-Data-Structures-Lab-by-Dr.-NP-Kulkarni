#include <iostream>
using namespace std;
struct tn
{
    int data;
    tn *left;
    tn *right;
};
class BST
{
private:
    tn *root;

public:
    BST()
    {
        root = NULL;
    }
    void Create()
    {

        char c;
        tn *temp;
        tn *curr;

        do
        {
            curr = new (tn);
            temp = new (tn);
            temp->left = NULL;
            cout << "ENTER DATA: " << endl;
            cin >> temp->data;
            temp->right = NULL;

            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                curr = root;
            }
            while (1)
            {
                if (curr->data > temp->data)
                {
                    if (curr->left == NULL)
                    {
                        curr->left = temp;
                        break;
                    }
                    else
                    {
                        curr = curr->left;
                    }
                }
                else if (curr->data < temp->data)
                {
                    if (curr->right == NULL)
                    {
                        curr->right = temp;
                        break;
                    }
                    else
                    {
                        curr = curr->right;
                    }
                }
            }
            cout << "DO YOU WANT TO CONTINUE: " << endl;
            cin >> c;
        } while ((c == 'y') || (c == 'Y'));
    }
};
int main()
{
    BST b;
    b.Create();
}