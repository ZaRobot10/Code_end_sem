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
// 5
// 14
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 7 6 1
// 2 8 2
// 8 6 6
// 6 5 2
// 2 5 4
// 2 3 7
// 3 4 9
// 3 5 14
// 5 4 10
// 0
class graph
{
    int v;
    unordered_map < int, list < pair < int, int > > > l;

public:

    graph (int V)
    {
        v = V;
    }

    void insert_edge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    void dijisktraSSSP(int src)
    {
        unordered_map <int, int> dist;
        for (auto p: l)
        {
            dist[p.first] = INT_MAX;
        }

        dist[src] = 0;


        // let an element be weight, source 
        set < pair < int, int > > s;

        s.insert({0, src});

        while (s.size() != 0)
        {
            auto top = *s.begin();
            int weight = top.first;
            int node = top.second;

            s.erase(s.begin());

            for (auto nbr: l[node])
            {
                int distance = dist[node] + nbr.second;

                if (distance < dist[nbr.first])
                {

                    // if the element is already in the set we must remove it

                    auto f = s.find({dist[nbr.first], nbr.first});

                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    s.insert({distance, nbr.first});
                    dist[nbr.first] = distance;
                }
            }
        }

        // lets print distance to all other nodes from source
        for (auto p: dist)
        {
            cout << p.first << " is located at a distance of " << p.second << endl;
        }



    }


};

int main()
{
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    graph g(v);

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.insert_edge(x, y, w);
    }

    cout << "Enter Source: ";
    int src;
    cin >> src;

    g.dijisktraSSSP(src);




}