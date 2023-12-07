#include <iostream>
#include <climits>
#include <math.h>
#include <string>
#include <cstring> //using strlen in char arrays
#include <set>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <cstdlib> // for absolute function

using namespace std;

#define ll long long    

// sample input - 
// Enter number of vertices: 6
// Enter number of edges: 9
// 0 1 1
// 0 2 5
// 1 2 2
// 2 4 2
// 1 4 1
// 1 3 2
// 3 4 3
// 3 5 1
// 4 5 2
void floyd_warshall(vector < vector <int > > graph)
{
    int v = graph.size();

    for (int k = 0; k < v; k ++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                // we can either skip it, or include it, it wont make a difference
                // if (i == k || j == k)
                // {
                //     continue;
                // }

                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }

            }
        }
    }

    for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (graph[i][j] == INT_MAX)
                {
                    cout << "INF" << " ";
                    continue; 
                }
                cout << graph[i][j] << " ";

            }

            cout << endl;
        }

}

int main()
{

    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector <vector <int> > graph(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < e; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;

        graph[x][y] = d;

    }

    for (int i = 0; i < v; i++)
    {
        graph[i][i] = 0;
    }

    floyd_warshall(graph);
}
