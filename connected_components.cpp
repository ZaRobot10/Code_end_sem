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

// sample input
// Enter number of vertices: 8
// Enter number of edges: 8
// 0 1
// 1 2
// 2 3
// 0 3
// 0 4
// 5 6
// 6 7
// 8 8


class graph
{
    int v;
    map<int, list<int> > l;

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

    void dfs_helper(int source, unordered_map<int, int> & visited)
    {
        cout << source << " ";
        visited[source] = 1;

        for (auto nbr: l[source])
        {
            if (visited[nbr] == 0)
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs()
    {
        unordered_map<int, int> visited;
        int count = 0;

        for (auto p: l)
        {
            if (visited[p.first] == 0)
            {
                count ++;
                cout << "Component " << count << " -->";
                dfs_helper(p.first, visited);
                cout << endl;
            }
        }
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


    g.dfs();
    
}