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
    map<T, list<T> > l;

public:
    void insert_edge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }

    bool cycle_helper(T node, map <T, int> &visited, T parent)
    {
        visited[node] = 1;

        for (auto nbr: l[node])
        {
            if (visited[nbr] == 1 &&  nbr != parent)
            {
                return true;
            }

            else if (visited[nbr] == 0)
            {
                bool cycle_found = cycle_helper(nbr, visited, node);
                if (cycle_found)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool contains_cycle()
    {
        map <T, int> visited;
        return cycle_helper(0, visited, -1);
    }

};

int main()
{
    graph <int> g;

    g.insert_edge(0, 1);
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(3, 4);
    g.insert_edge(4, 0);
   
    if (g.contains_cycle())
    {
        cout << "cycle exists" << endl;
    }

    else
    {
        cout << "cycle does not exist" << endl;
    }
}