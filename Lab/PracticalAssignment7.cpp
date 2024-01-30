#include <iostream>
#define Max 20
#define infi 999
using namespace std;
class Graph
{
private:
    int A[Max][Max];
    int NoOfvertices;

public:
    Graph()
    {
        cout << "ENTER NO OF VERTICES: " << endl;
        cin >> NoOfvertices;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                if (i != j)
                {
                    A[i][j] = infi;
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
    }
    void Create_Graph()
    {
        char r;
        int w;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {

                    cout << "WHETHER " << i << " & " << j << " ARE ADJACENT TO EACH OTHER: Y/N?";
                    cin >> r;
                    if ((r == 'y') || (r == 'Y'))
                    {
                        cout << "ENTER THE WEIGHT: " << endl;
                        cin >> A[i][j];
                    }
                }
            }
        }
    }
    void Display_Graph()
    {
        cout << "YOUR GRAPH IS AS FOLLOWS: " << endl;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                cout << A[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void display_MST()
    {
        int visited[NoOfvertices], sv, min, x, y;
        for (int i = 0; i < NoOfvertices; i++)
        {
            visited[i] = 0;
        }
        cout << "ENTER STARTING VERTEX: " << endl;
        cin >> sv;
        visited[sv] = 1;
        int no_edge = 0;
        int cost_MST = 0;
        cout << "EDGE: WEIGHT " << endl;
        while (no_edge < NoOfvertices - 1)
        {
            min = infi;
            x = 0;
            y = 0;
            for (int i = 0; i < NoOfvertices; i++)
            {
                if (visited[i])
                {
                    for (int j = 0; j < NoOfvertices; j++)
                    {
                        if (!visited[j] && A[i][j])
                        {
                            if (min > A[i][j])
                            {
                                min = A[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout << x << "-->" << y << " :" << A[x][y] << endl;
            cost_MST += A[x][y];
            visited[y] = 1;
            no_edge++;
        }
        cout << "COST OF MST IS: " << cost_MST << endl;
    }
    void Total_Cost()
    {
        int tc = 0;
        for (int i = 0; i < NoOfvertices; i++)
        {
            for (int j = 0; j < NoOfvertices; j++)
            {
                if (i < j && (A[i][j]!=999||A[i][j]!=infi))
                {
                    tc += A[i][j];
                }
            }
        }
        cout << "TOTAL COST IS: " << tc << endl;
    }
};

int main()
{
    Graph g;
    int n;
    cout << "1.CREATE GRAPH " << endl;
    cout << "2.DISPLAY GRAPH " << endl;
    cout << "3.DISPLAY OF MINIMUM SPANNING TREE " << endl;
    cout << "4.TO DISPLAY TOTAL COST " << endl;
    do
    {

        cout << "\nENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            g.Create_Graph();
            break;
        case 2:
            g.Display_Graph();
            break;
        case 3:
            g.display_MST();
            break;
        case 4:
            g.Total_Cost();
            break;
        default:
            break;
        }

    } while (n != 5);
}
