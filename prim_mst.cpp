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
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40

class graph
{
    int v;
    // x,   y,    w
    unordered_map<int, list<pair < int, int > > >  l;

public:

    graph (int V)
    {
        v = V;
    }
    
    void add_edge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});

    }


    int prim_mst()
    {
        unordered_map<int, int> visited;
    

        // it will store w and y
        priority_queue < pair <int, int>, vector <pair < int, int> >, greater <pair < int, int> > > q;

        // let the starting node be 0
        q.push({0, 0});
        // visited[0] = 1;


        int ans = 0;

        while (!q.empty())
        {
            pair<int, int>  top = q.top();
            q.pop();

            int weight = top.first;
            int y = top.second;

            if (visited[y] == 1)
            {
                continue;
            }

            visited[y] = 1;
            ans += weight;

            for (auto nbr: l[y])
            {
                if (visited[nbr.first] != 1)
                {
                    q.push({nbr.second, nbr.first});
                }
            }


        }

        return ans;

    }



};  

int main()
{
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; i++)
    {   
        int x, y, w;
        cin >> x >> y >> w;
        g.add_edge(x - 1, y - 1, w);
    }

    cout << g.prim_mst() << endl;
}