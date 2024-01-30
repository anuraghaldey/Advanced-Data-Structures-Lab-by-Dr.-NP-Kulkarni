/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
struct TN
{
public:
    int data;
    TN *left;
    TN *right;
};
class BST
{
private:
    TN *root;

public:
    BST()
    {
        root = NULL;
    }
    void insert(TN *curr, TN *temp)
    {
        if (curr->data > temp->data)
        {
            if (!curr->left)
            {
                curr->left = temp;
            }
            else
            {
                insert(curr->left, temp);
            }
        }
        else if (curr->data < temp->data)
        {
            if (!curr->right)
            {
                curr->right = temp;
            }
            else
            {
                insert(curr->right, temp);
            }
        }
    }
    void Create()
    {
        char c;
        TN *temp;

        do
        {
            temp = new (TN);
            temp->right = NULL;
            cout << "ENTER DATA: " << endl;
            cin >> temp->data;
            temp->left = NULL;

            if (!root)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }
            cout << "DO YOU WANT TO CONTINUE: " << endl;
            cin >> c;
        } while (c == 'y');
    }
    void inorder(TN *root)
    {
        stack<TN *> s;
        TN *curr = root;
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
            else
            {
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    void inorder()
    {
        if (root)
        {
            inorder(root);
        }
        else
        {
            cout << "TREE EMPTY " << endl;
        }
    }
    void preorder(TN *root)
    {
        stack<TN *> s;
        TN *curr = root;
        while (1)
        {
            while (curr)
            {
                cout << curr->data << " ";
                s.push(curr);
                curr = curr->left;
            }
            if (s.empty())
            {
                break;
            }
            else
            {
                curr = s.top();
                s.pop();

                curr = curr->right;
            }
        }
    }
    void preorder()
    {
        if (root)
        {
            preorder(root);
        }
        else
        {
            cout << "TREE EMPTY " << endl;
        }
    }
    void postorder(TN *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    void postorder()
    {
        if (root)
        {
            postorder(root);
        }
        else
        {
            cout << "TREE EMPTY " << endl;
        }
    }

    TN *Search(int item, TN **parent)
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
};
int main()
{
    BST b;
    int n, item;
    cout << "1.CREATE " << endl;
    cout << "2.INORDER " << endl;
    cout << "3.PREORDER " << endl;
    cout << "4.POSTORDER " << endl;
    cout << "5.SEARCH DATA " << endl;
    cout << "7.EXIT " << endl;

    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> n, item;
        switch (n)
        {
        case 1:
            b.Create();
            break;
        case 2:
            b.inorder();
            break;
        case 3:
            b.preorder();
            break;
        case 4:
            b.postorder();
            break;
        case 5:
            cout << "ENTER AN ITEM TO SEARCH: " << endl;
            cin >> item;
            TN *parent = NULL;
            TN *curr = b.Search(item, &parent);
            if (!curr)
            {
                cout << item << " NOT FOUND " << endl;
            }
            else if (!parent)
            {
                cout << item << "FOUND AT ROOT " << endl;
            }
            else
            {
                cout << item << " IS CHILD OF " << parent->data << endl;
            }
        }

    } while (n != 7);
}