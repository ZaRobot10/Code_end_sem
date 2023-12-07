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


// input -
// Enter number of vertices: 5
// Enter number of edges: 6
// 0 1 1
// 1 3 3
// 3 2 4
// 2 0 2
// 0 3 2
// 1 2 2

class graph
{   
    // we are making a list of edge pair

    int v;
    vector <pair < int, pair <int, int > > > l;

public:

    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y, int w)
    {
        l.push_back({w, {x, y}});
    }

    int find(int i, int parent[])
    {
        if (parent[i] == -1)
        {
            return i;
        }

        parent[i] = find(parent[i], parent);
        return parent[i];
    }

    int krushal_mst()
    {
        int parent[v];
        int rank[v];

        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        sort(l.begin(), l.end());
        
        int ans = 0;

        for (auto p: l)
        {
            int x = p.second.first;
            int y = p.second.second;
            int w = p.first;

            // union part
            int s1 = find(x, parent);
            int s2 = find(y, parent);

            if (s1 != s2)
            {

                if (rank[s1] >= rank[s2])
                {
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }

                else
                {
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }

                ans += w;

                
            }

            else
            {
                
                // return true;
            }

        }

        

        return ans;
        // return false;
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
        int x, y, w;
        cin >> x >> y >> w;
        g.add_edge(x, y, w);
    }
    


    cout << "The minimum cost is: " << g.krushal_mst() << endl;

   

}