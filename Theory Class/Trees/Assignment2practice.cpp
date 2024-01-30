#include <iostream>
#include <string.h>
using namespace std;
struct TN
{
    TN *left;
    char keyword[20];
    char meaning[20];
    TN *right;
};
class Dictionary
{
private:
    TN *root;

public:
    Dictionary()
    {
        root = NULL;
    }
    void insert(TN *curr, TN *temp)
    {
        if (strcmp(curr->keyword, temp->keyword) < 0)
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
        else
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
    void createD()
    {
        char c;
        TN *temp;
        do
        {
            temp = new TN;
            temp->left = NULL;
            cout << "ENTER KEYWORD: " << endl;
            cin >> temp->keyword;
            cout << "ENTER MEANING: " << endl;
            cin >> temp->meaning;
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
    void display(TN *root)
    {
        if (root)
        {
            display(root->left);
            cout << "KEYWORD: " << root->keyword << "| ";
            cout << "MEANING: " << root->meaning << endl;
            cout << endl;
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
            cout << "EMPTY DICTIONARY " << endl;
        }
    }
    void search(char searchkey[])
    {
        TN *temp = root;
        while (1)
        {
            if (strcmp(searchkey, temp->keyword) == 0)
            {
                cout << searchkey << " FOUND WITH MEANING : " << temp->meaning << endl;
                return;
            }
            else if (strcmp(searchkey, temp->keyword) < 0)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << "KEYWORD NOT FOUND " << endl;
    }
    void update(char updatekey[])
    {
        TN *temp = root;
        while (1)
        {
            if (strcmp(updatekey, temp->keyword) == 0)
            {
                cout << "ENTER THE UPDATED MEANING: " << endl;
                cin >> temp->meaning;
                return;
            }
            else if (strcmp(updatekey, temp->keyword) < 0)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << "CANT UPDATE BECAUSE KEYWORD NOT FOUND " << endl;
    }
};
int main()
{
    Dictionary d;
    cout << "1.CREATE: " << endl;
    cout << "2.DISPLAY CONTENT: " << endl;
    cout << "3.SEARCH KEYWORD: " << endl;
    cout << "4.UPDATE KEYWORD'S MEANING: " << endl;
    cout << "5.EXIT " << endl;
    int n;
    char searchkey[20];
    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            d.createD();
            break;
        case 2:
            d.display();
            break;
        case 3:
            cout << "ENTER KEYWORD YOU WANT TO SEARCH : " << endl;
            cin >> searchkey;
            d.search(searchkey);
            break;
        case 4:
            cout << "ENTER KEYWORD TO UPDATE MEANING: " << endl;
            cin >> searchkey;
            d.update(searchkey);
            break;
        default:
            break;
        }

    } while (n != 5);
}