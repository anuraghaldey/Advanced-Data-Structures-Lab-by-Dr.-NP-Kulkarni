#include <iostream>
using namespace std;
struct treenode
{
public:
    int data;
    treenode *lchild;
    treenode *rchild;
};
class binaryTree
{
    treenode *root;

public:
    binaryTree()
    {
        root = NULL;
    }
    void insert(treenode *root, treenode *curr)
    {
        char choice;

        cout << "WHERE YOU WANT TO ATTACH NEW NODE : LEFT/RIGHT? " << endl;
        cin >> choice;

        if (choice == 'l')
        {
            if (root->lchild == NULL)
            {
                root->lchild = curr;
            }
            else
            {
                insert(root->lchild, curr);
            }
        }
        else if (choice == 'r')
        {
            if (root->rchild == NULL)
            {
                root->rchild = curr;
            }
            else
            {
                insert(root->rchild, curr);
            }
        }
    }

    void create()
    {
        treenode *temp;
        char choice;

        do
        {
            temp = new (treenode);
            temp->lchild = NULL;
            cout << "ENTER DATA: " << endl;
            cin >> temp->data;
            temp->rchild = NULL;

            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }

            cout << "\nDO YOU WANT TO CONTINUE" << endl;
            cin >> choice;
        } while ((choice == 'y') || (choice == 'Y'));
    }
};

int main()
{
    binaryTree t;

    t.create();
}