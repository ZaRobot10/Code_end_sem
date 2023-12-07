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
        
    }

    bool cycle_helper(int src, unordered_map<T, int> &visited, unordered_map<T, int> &current_path)
    {
        visited[src] = 1;
        current_path[src] = 1;

        for (auto nbr: l[src])
        {
            if (visited[nbr] == 0)
            {
                bool cycle_found = cycle_helper(nbr, visited, current_path);
                if (cycle_found)
                {
                    return true;
                }
            }

            else if (current_path[nbr] == 1)
            {
                return true;
            }


        }
        current_path[src] = 0;
        return false;
    }


    bool contains_cycle()
    {
        unordered_map<T, int> visited;
        unordered_map<T, int> current_path;

        return cycle_helper(0, visited, current_path);
    }

};

int main()
{
    graph <int> g;

    g.insert_edge(0, 1);
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(3, 4);
    g.insert_edge(4, 5);
    g.insert_edge(1, 5);
    g.insert_edge(5, 6);
    g.insert_edge(4, 2);    // back edge
   
    if (g.contains_cycle())
    {
        cout << "cycle exists" << endl;
    }

    else
    {
        cout << "cycle does not exist" << endl;
    }
}