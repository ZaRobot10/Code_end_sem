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

template <typename T>

class graph
{   
    map <T, list < pair < T, int> > > l;

public:
    void add_edge(T x, T y, int dist, bool bidir = true)
    {
        l[x].push_back({y, dist});

        if (bidir)
        {
            l[y].push_back({x, dist});
        }
    }

    void print_adj_list()
    {
        for (auto p: l)
        {
            cout << p.first << "->";

            for (auto nbr: p.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    void dijisktraSSSP(T source)
    {
        unordered_map <T, int> dist;

        // set all distances to infinty
        for (auto p: l)
        {
            dist[p.first] = INT_MAX;
        }

        // make a set to find out node with minimum distance
        set <pair <int, T> > s;

        dist[source] = 0;
        s.insert({0, source});

        while (!s.empty())
        {
            auto p = *s.begin();

            int node_dist = p.first;
            T node = p.second;

            s.erase(s.begin());

            for (auto nbr: l[node])
            {
                int distance = nbr.second + node_dist;

                if (distance < dist[nbr.first])
                {
                    // in set updation of a particular element is not possible 
                    // we have to remove the previous pair and insert a new one

                    auto f = s.find({dist[nbr.first], nbr.first});

                    // we are checking if this particular pair already exists or not
                    // if it exists we will remove it
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    
                    // insert new pair
                    s.insert({distance, nbr.first});

                    // update dist
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
    // graph <int> g;
    // g.add_edge(1, 2, 1);
    // g.add_edge(1, 3, 4);
    // g.add_edge(2, 3, 1);
    // g.add_edge(3, 4, 2);
    // g.add_edge(1, 4, 7);
    // // g.print_adj_list();
    // g.dijisktraSSSP(1);

    graph <string> india;
    india.add_edge("amritsar", "delhi", 1);
    india.add_edge("amritsar", "jaipur", 4);
    india.add_edge("jaipur", "delhi", 2);
    india.add_edge("jaipur", "mumbai", 8);
    india.add_edge("bhopal", "agra", 2);
    india.add_edge("mumbai", "bhopal", 3);
    india.add_edge("agra", "delhi", 1);
    // india.print_adj_list();
    india.dijisktraSSSP("amritsar");

}