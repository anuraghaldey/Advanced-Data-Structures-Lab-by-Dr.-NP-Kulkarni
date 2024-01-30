#include <iostream>
#include <stack>
#define Max 20
#define infi 999
using namespace std;
class ShortestPath
{
private:
    int A[Max][Max];
    int NoOfvertices;

public:
    ShortestPath()
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

    void shortestPath()
    {
        int start;
        cout << "Enter starting vertex: ";
        cin >> start;

        int dist[Max];
        bool visited[Max] = {false};
        int parent[Max];

        // initialize distances to infinity and parent to -1
        for (int i = 0; i < NoOfvertices; i++)
        {
            dist[i] = infi;
            parent[i] = -1;
        }

        // distance to starting vertex is 0
        dist[start] = 0;

        // find shortest path to all vertices
        for (int i = 0; i < NoOfvertices - 1; i++)
        {
            // find vertex with minimum distance
            int minDist = infi;
            int u;
            for (int j = 0; j < NoOfvertices; j++)
            {
                if (!visited[j] && dist[j] < minDist)
                {
                    minDist = dist[j];
                    u = j;
                }
            }

            // mark vertex as visited
            visited[u] = true;

            // update distances to adjacent vertices
            for (int v = 0; v < NoOfvertices; v++)
            {
                if (!visited[v] && A[u][v] != infi && dist[u] != infi && dist[u] + A[u][v] < dist[v])
                {
                    dist[v] = dist[u] + A[u][v];
                    parent[v] = u;
                }
            }
        }

        // display shortest paths and weights
        cout << "Shortest paths from vertex " << start << ":" << endl;
        for (int i = 0; i < NoOfvertices; i++)
        {
            if (i == start)
            {
                continue;
            }

            cout << "Path to vertex " << i << ": ";

            // construct path by following parents backwards
            stack<int> path;
            int v = i;
            while (v != start)
            {
                path.push(v);
                v = parent[v];
            }
            path.push(start);

            // display path and weight
            cout << path.top();
            int weight = dist[i];
            path.pop();
            while (!path.empty())
            {
                cout << " -> " << path.top();
                weight += A[parent[path.top()]][path.top()];
                path.pop();
            }
            cout << " (weight " << weight/2 << ")" << endl;
        }
    }
}

;
int main()
{
    ShortestPath s;
    int n;
    cout << " 1.CREATE " << endl;
    cout << " 2.DISPLAY " << endl;
    cout << " 3.SHORTEST PATH " << endl;
    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            s.Create_Graph();
            break;
        case 2:
            s.Display_Graph();
            break;
        case 3:
            s.shortestPath();
            break;
        default:
            break;
        }

    } while (n != 4);
}