
#include <iostream>

using namespace std;
struct t
{
    int data;
    t *l;
    t *r;
};
class BT
{
private:
    t *root;

public:
    BT()
    {
        root = NULL;
    }
    void insert(t *root, t *curr)
    {
        char c;
        cout << "WHICH SIDE TO INSERT l/r? " << endl;
        cin >> c;

        if (c == 'l')
        {
            if (root->l == NULL)
            {
                root->l = curr;
            }
            else
            {
                insert(root->l, curr);
            }
        }
        else if (c == 'r')
        {
            if (root->r == NULL)
            {
                root->r = curr;
            }
            else
            {
                insert(root->r, curr);
            }
        }
    }
    void inorder(t *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            inorder(root->l);
            cout << root->data << " ";
            inorder(root->r);
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
            cout << "EMPTY TREE " << endl;
        }
    }
    void preorder(t *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            cout << root->data << " ";
            preorder(root->l);
            preorder(root->r);
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
            cout << "EMPTY TREE " << endl;
        }
    }
    void postorder(t *root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            postorder(root->l);
            postorder(root->r);
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
            cout << "EMPTY TREE " << endl;
        }
    }
    void create()
    {
        char c, ch;
        t *temp;
        do
        {
            temp = new (t);
            temp->l = NULL;
            cout << "ENTER DATA: " << endl;
            cin >> temp->data;
            temp->r = NULL;

            if (root == NULL)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }

            cout << "\nDO YOU WANT TO CONTINUE: " << endl;
            cin >> c;
        } while (c == 'y');
    }
};
int main()
{
    BT b;
    b.create();
    char c;
    int n;
    cout << "DO YOU WANT TO DIPLAY: " << endl;
    cin >> c;
    if (c == 'y')
    {
        cout << "1.INORDER: " << endl;
        cout << "2.PREORDER: " << endl;
        cout << "3.POSTORDER: " << endl;
        cout << "ENTER CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            b.inorder();
            break;
        case 2:
            b.preorder();
            break;
        case 3:
            b.postorder();
            break;
        default:
            break;
        }
    }
}