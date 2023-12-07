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
                cout << graph[i][j] << " ";

            }

            cout << endl;
        }

}


int main()
{
    // 4 vertices (4 x 4 Matrix)
    vector < vector <int > > graph = {
                                        {0, INT_MAX, -2, INT_MAX},
                                        {4, 0, 3, INT_MAX},
                                        {INT_MAX, INT_MAX, 0, 2},
                                        {INT_MAX, -1, INT_MAX, 0}
                                    };


    floyd_warshall(graph);
}