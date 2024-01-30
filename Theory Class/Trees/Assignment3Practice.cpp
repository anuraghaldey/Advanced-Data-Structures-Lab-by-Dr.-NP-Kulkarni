#include <iostream>
#include <queue>

using namespace std;
struct TN
{
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
            temp = new TN;
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
    void display(TN *root)
    {
        if (root)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
    }
    void display()
    {
        if (root)
        {
            display(root);
        }
        else
        {
            cout << "EMPTY TREE " << endl;
        }
    }
    void LevelW(TN *root)
    {
        queue<TN *> q;
        TN *temp = root;
        q.push(temp);
        do
        {
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (q.empty())
            {
                break;
            }

        } while (1);
    }
    void levelW()
    {
        if (root)
        {
            LevelW(root);
        }
        else
        {
            cout << "EMPTY TREE " << endl;
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
            int maxHeight = max(lheight, rheight);
            return maxHeight + 1;
        }
    }
    void height()
    {
        if (root)
        {
            cout << "HEIGHT = " << height(root);
        }
        else
        {
            cout << "0";
        }
    }
    void PrintLN(TN *root)
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
            PrintLN(root->left);
        }
        if (root->right)
        {
            PrintLN(root->right);
        }
    }
    void PrintLN()
    {
        if (root)
        {
            PrintLN(root);
        }
        else
        {
            cout << "EMPTY TREE " << endl;
        }
    }
};
int main()
{
    BST b;
    cout << "1.CREATE: " << endl;
    cout << "2.DISPLAY: " << endl;
    cout << "3.MIRROR: " << endl;
    cout << "4.LEVELWISE DISPLAY OF THE ORIGINAL TREE: " << endl;
    cout << "5.FIND HEIGHT: " << endl;
    cout << "6.PRINT LEAFNODES " << endl;
    cout << "7.EXIT " << endl;
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
            b.display();
            break;
        case 3:
            b.mirror();
            break;
        case 4:
            b.mirror();
            b.levelW();
            break;
        case 5:
            b.height();
            break;
        case 6:
            b.PrintLN();
            break;
        default:
            break;
        }

    } while (n != 7);
}