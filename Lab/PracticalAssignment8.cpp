#include <iostream>
using namespace std;
class HashTable
{
public:
    int index;
    void print(int A[], int tablesize)
    {
        cout << "[ ";
        for (int i = 0; i < tablesize; i++)
        {
            cout << A[i] << " ";
        }
        cout << "]";
        cout << endl;
    }
    void linearProbeWithR()
    {
        int t;
        cout << "ENTER TABLESIZE: " << endl;
        cin >> t;
        int A[t];

        for (int i = 0; i < t; i++)
        {
            A[i] = 0;
        }
        cout << endl;
        cout << "INITIAL LIST IS: " << endl;
        print(A, t);

        for (int i = 0; i < t; i++)
        {
            int key;
            cout << "\nENTER THE VALUE: " << endl;
            cin >> key;
            index = key % t;
            int z = index;
            if (A[index] == 0)
            {
                A[index] = key;
                print(A, t);
            }
            else
            {
                while (A[index] != 0)
                {
                    index = (index + 1) % t;
                }
                if (A[z] % t == z)
                {
                    A[index] = key;
                }
                else
                {
                    A[index] = A[z];
                    A[z] = key;
                }
                print(A, t);
            }
        }
    }
    void linearProbeWithoutR()
    {
        int t;
        cout << "ENTER TABLESIZE: " << endl;
        cin >> t;
        int A[t];

        for (int i = 0; i < t; i++)
        {
            A[i] = 0;
        }
        cout << endl;
        cout << "INITIAL LIST IS: " << endl;
        print(A, t);

        for (int i = 0; i < t; i++)
        {
            int key;
            cout << "\nENTER THE VALUE: " << endl;
            cin >> key;
            index = key % t;

            if (A[index] == 0)
            {
                A[index] = key;
                print(A, t);
            }
            else
            {
                while (A[index] != 0)
                {
                    index = (index + 1) % t;
                }
                A[index] = key;
                print(A, t);
            }
        }
    }
};
int main()
{
    HashTable h;
    cout << "1.WITH REPLACEMENT: " << endl;
    cout << "2.WITHOUT REPLACEMENT: " << endl;
    cout << "3. EXIT" << endl;
    int n;
    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            h.linearProbeWithR();
            break;
        case 2:
            h.linearProbeWithR();
            break;
        default:
            break;
        }

    } while (n != 3);
}