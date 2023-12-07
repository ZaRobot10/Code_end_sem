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


// sample input - (negative weight cycle)
// 3 3
// 1 2 3
// 2 3 4
// 3 1 -10

// sample input -
// 3 3
// 1 2 3
// 2 3 4
// 1 3 -10

class graph
{
    int v;
    
    // edge list (x, y, w)
    vector < pair < pair < int, int >, int > > edges;

public:
    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y, int w)
    {
        edges.push_back({ {x, y}, w});
    }

    void bellman_ford(int src)
    {
        vector <int > dist(v + 1, INT_MAX);
        dist[src] = 0;

        // we need to this v - 1 times
        for (int i = 0; i < v - 1; i++)
        {
            for (auto edge : edges)
            {
                auto p = edge;

                int u = p.first.first;
                int v = p.first.second;
                int w = p.second;
                
                
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }

            }
        }

        // for negative weight cycle
        for (auto edge : edges)
        {
            auto p = edge;

            int x = p.first.first;
            int y = p.first.second;
            int w = p.second;
            
            int u = dist[x];
            int v = dist[y];
            
            if (u != INT_MAX && u + w < v)
            {
                cout << "negative cycle found" << endl;
                return;
            }

        }

        // printing all the distances

        for (int i = 1; i <= v; i++)
        {
            cout << "Node " << i << " is at distance " << dist[i] <<endl;
        }
            

    }


};

int main()
{
    // n is the number of vertices and m is the number of egdes
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        g.add_edge(x, y, w);
    }

    g.bellman_ford(1);

}