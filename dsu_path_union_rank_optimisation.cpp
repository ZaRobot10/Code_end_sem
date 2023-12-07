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


// cycle detection in a undirected graph using DSU

class graph
{   
    // we are making a list of edge pair

    int v;
    list <pair <int, int > > l;

public:

    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y)
    {
        l.push_back({x, y});
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

    bool contains_cycle()
    {
        int parent[v];
        int rank[v];

        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto p: l)
        {
            int x = p.first;
            int y = p.second;

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
                
            }

            else
            {
                cout << "same parent " << s1 << endl;
                return true;
            }

        }

        return false;
    }


};



int main()
{   
    graph g(4);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    cout << g.contains_cycle() << endl;

}