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


// sample input - 1
// 5 4
// 0 1
// 0 2
// 1 3
// 2 4

// sample input - 2
// 5 5
// 0 1
// 0 2
// 1 3
// 2 4
// 3 2

// sample input - 3
// 5 6
// 0 1
// 0 2
// 1 3
// 2 4
// 3 2
// 3 4

class graph
{
    int v;
    unordered_map < int, vector <int > > l;

public:

    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }


    bool dfs_helper(int node, unordered_map < int, int > &visited)
    {
        int color = visited[node];
        for (auto nbr: l[node])
        {
            if (visited[nbr] == 0)
            {
                visited[nbr] = 3 - color;
                int ans = dfs_helper(nbr, visited);
                if (ans == false)
                {
                    return false;
                }
            }

            else
            {   
                if (visited[nbr] == color)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs()
    {
        unordered_map < int, int > visited;
        visited[0] = 1;  // 0 means unvisited and 1 and 2 represent color (also means visited)
        return dfs_helper(0, visited);

    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i  < m ; i++)
    {
        int x, y;
        cin >> x  >> y;

        g.add_edge(x, y);
    }

    if (g.dfs())
    {
        cout << "It is a bipartite graph" << endl;
    }

    else
    {
        cout << "It is not a bipartite graph" << endl;
    }
}