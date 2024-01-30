// NAME- Anurag Haldey
// CLASS-SY-13(B)
// ROLL NO-2215055
// ENROLMENT NO-MITU21BTIT0010

#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char key[20];
    char meaning[20];
    node *left, *right;
};

class dictionary
{
private:
    node *root;

public:
    dictionary()
    {
        root = NULL;
    }

    void createDictionary();
    node *getData();
    void displayDictionary(node *);
    void insertNode(node *);
    void searchInDictionary(char[]);
    void updateInDictionary(char[]);
    node *deleteFromDictionary(node *, char[]);
    node *minNode(node *);
};

node *dictionary ::getData()
{
    node *newNode;
    newNode = new node();

    cout << "Enter key value:";
    cin >> newNode->key;

    cout << "Enter its meaning:";
    cin >> newNode->meaning;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void dictionary ::insertNode(node *newNode)
{
    node *tempNode = new node();
    tempNode = root;
    while (1)
    {
        if (strcmp(newNode->key, tempNode->key) < 0)
        {
            if (tempNode->left == NULL)
            {
                tempNode->left = newNode;
                break;
            }
            else
            {
                tempNode = tempNode->left;
            }
        }
        else
        {
            if (tempNode->right == NULL)
            {
                tempNode->right = newNode;
                break;
            }
            else
            {
                tempNode = tempNode->right;
            }
        }
    }
}

void dictionary ::createDictionary()
{
    char nodeChoice;
    node *newNode;
    newNode = new node();
    while (1)
    {
        newNode = getData();
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            insertNode(newNode);
        }
        cout << "Do you want to add more data (y/n):";
        cin >> nodeChoice;

        if (nodeChoice == 'n')
        {
            break;
        }
    }
}

void dictionary ::displayDictionary(node *tempNode)
{
    if (tempNode != NULL)
    {
        displayDictionary(tempNode->left);
        cout << "\n Key Word:" << tempNode->key;
        cout << "\t Meaning:" << tempNode->meaning;
        displayDictionary(tempNode->right);
    }
}


void dictionary ::searchInDictionary(char searchKey[])
{
    node *tempNode;
    tempNode = root;

    while (1)
    {
        if (strcmp(searchKey, tempNode->key) == 0)
        {
            cout << "Key found! Meaning is: " << tempNode->meaning;
            return;
        }
        else if (strcmp(searchKey, tempNode->key) < 0)
        {
            tempNode = tempNode->left;
        }
        else
        {
            tempNode = tempNode->right;
        }
    }

    cout << "Key not found!";
}

void dictionary ::updateInDictionary(char updateKey[])
{
    node *tempNode;
    tempNode = root;

    while (1)
    {
        if (strcmp(updateKey, tempNode->key) == 0)
        {
            cout << "Enter the updated meaning:";
            cin >> tempNode->meaning;
            return;
        }
        else if (strcmp(updateKey, tempNode->key) < 0)
        {
            tempNode = tempNode->left;
        }
        else
        {
            tempNode = tempNode->right;
        }
    }

    cout << "Key not found!";
}

node *dictionary ::deleteFromDictionary(node *tempNode, char deleteKey[])
{
    node *deleteNode;

    if (tempNode == NULL)
    {
        cout << "Dictionary (TREE) is empty!/ Key Not Found\n";
        return tempNode;
    }
    else if (strcmp(deleteKey, tempNode->key) < 0)
    {
        tempNode->left = deleteFromDictionary(tempNode->left, deleteKey);
        return tempNode;
    }
    else if (strcmp(deleteKey, tempNode->key) > 0)
    {
        tempNode->right = deleteFromDictionary(tempNode->right, deleteKey);
        return tempNode;
    }
    else
    {
        if (tempNode->left == NULL && tempNode->right == NULL)
        {
            deleteNode = tempNode;
            delete deleteNode;
            return 0;
        }
        else if (tempNode->left != NULL)
        {
            deleteNode = tempNode;
            tempNode = tempNode->right;
            delete deleteNode;
            return tempNode;
        }
        else if (tempNode->right != NULL)
        {
            deleteNode = tempNode;
            tempNode = tempNode->left;
            delete deleteNode;
            return tempNode;
        }
        deleteNode = minNode(tempNode->right);
        strcpy(tempNode->key, deleteNode->key);
        tempNode->right = deleteFromDictionary(tempNode->right, deleteNode->key);
    }
    return tempNode;
}

node *dictionary ::minNode(node *successor)
{
    while (successor->left != NULL)
    {
        successor = successor->left;
    }
    return successor;
}

int main()
{
    dictionary dict;
    char userInput, searchKey[20];
    int choice;
    do
    {
        cout << "\n Menu: \n 1.Create Dictionary \n 2.Display content \n 3. Search \n 4. Update \n 5. Delete\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dict.createDictionary();
            break;

        case 2:
            dict.displayDictionary();
            break;

        case 3:
            cout << "Enter the key whose meaning you want to search:";
            cin >> searchKey;
            dict.searchInDictionary(searchKey);
            break;

        case 4:
            cout << "Enter the key whose meaning you want to update:";
            cin >> searchKey;
            dict.updateInDictionary(searchKey);
            break;

        case 5:
            cout << "Enter the key whose record you want to delete:";
            cin >> searchKey;
            root = dict.deleteFromDictionary(root, searchKey);
            break;

        default:
            cout << "Enter Correct Input" << endl;
        }

        cout << "\nDo you wish to continue(y/n)";
        cin >> userInput;

    }

    while (userInput == 'y');

    return 0;
}
