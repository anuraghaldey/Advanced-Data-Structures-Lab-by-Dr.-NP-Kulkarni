#include <iostream>
#include <queue>
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
    void create()
    {
        char c;
        TN *temp;
        do
        {
            temp = new (TN);
            temp->left = NULL;
            cout << "ENTER DATA: " << endl;
            cin >> temp->data;
            temp->right = NULL;

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
    TN *mirror(TN *root)
    {
        if (root)
        {
            TN *swap = root->left;
            root->left = root->right;
            root->right = swap;
            mirror(root->left);
            mirror(root->right);
        }
        return root;
    }
    TN *mirror()
    {
        if (root)
        {
            mirror(root);
            return root;
        }
        else
        {
            return NULL;
        }
    }
    void inorder(TN *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
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
    void LW(TN *root)
    {
        queue<TN *> q;
        TN *curr = root;
        q.push(curr);

        do
        {
            curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            if (q.empty())
            {
                break;
            }
        } while (1);
    }
    void LW()
    {
        if (root)
        {
            LW(root);
        }
        else
        {
            cout << "EMPTY TREE: " << endl;
        }
    }
    int height(TN *root)
    {
        if ((!root) || (!root->left && !root->right))
        {
            return 0;
        }
        else
        {
            int lheight = height(root->left);
            int rheight = height(root->right);
            int maxheight = max(lheight, rheight);
            return maxheight + 1;
        }
    }
    void height()
    {
        if (root)
        {
            cout << height(root);
        }
        else
        {
            cout << "0";
        }
    }
    void printLN(TN *root)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            cout << root->data << " ";
            return;
        }
        if (root->left)
        {
            printLN(root->left);
        }
        if (root->right)
        {
            printLN(root->right);
        }
    }
    void printLN()
    {
        if (root)
        {
            printLN(root);
        }
        else
        {
            cout << "EMPTY TREE: " << endl;
        }
    }
};
int main()
{
    BST b;
    cout << "1.CREATE " << endl;
    cout << "2.MIRROR " << endl;
    cout << "3.DISPLAY INORDER: " << endl;
    cout << "4.LEVELWISE DIPLAY: " << endl;
    cout << "5.TO FIND HEIGHT: " << endl;
    cout << "6.TO PRINT LEAF NODES: " << endl;
    cout << "7.EXIT" << endl;
    int n;

    do
    {
        cout << "\nENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            b.create();
            break;
        case 2:
            b.mirror();
            break;
        case 3:
            b.inorder();
            break;
        case 4:
            b.mirror();
            b.LW();
            break;
        case 5:
            b.height();
            break;
        case 6:
            b.printLN();
            break;
        default:
            break;
        }
    } while (n != 7);
}
