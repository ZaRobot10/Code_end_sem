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



class graph
{
    int v;

    unordered_map<int, list<int> > l;
public:
    graph(int V)
    {
        v = V;
    }

    void insert_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int source)
    {
        unordered_map<int, int> visited;
        queue <int> q;
        q.push(source);
        visited[source] = 1;
        
        while(!q.empty())
        {

            int front = q.front();
            cout << front << " ";
            // go to its neighbours
            for (auto x: l[front])
            {
                if (visited[x] == 0)
                {
                    q.push(x);
                    visited[x] = 1;
                }
            }

            q.pop();
        }
        cout << endl;
    }
    
    
};

int main()
{
    
    cout << "Enter number of vertices: ";
    int v;
    cin >> v;

    graph g(v);

    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g.insert_edge(x, y);
    }

    int source;
    cout << "Enter source: ";
    cin >> source;

    cout << "Nodes reachable from " << source << " are: ";
    g.bfs(source);

}