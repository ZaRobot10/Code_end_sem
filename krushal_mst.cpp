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

// 5 3
// 0 1
// 1 2
// 3 4

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

    graph g(4);

    g.add_edge(0, 1, 1);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 4);
    g.add_edge(2, 0, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 2, 2);
    

    cout << g.krushal_mst() << endl;

   

}