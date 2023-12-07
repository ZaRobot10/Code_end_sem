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
    unordered_map<T, list<T> > l;

public:
    void insert_edge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }

    void dfs(int source)
    {
        static unordered_map<T, int> visited;
        cout << source << " ";
        visited[source] = 1;

        for (auto nbr: l[source])
        {
            if (visited[nbr] == 0)
            {
                dfs(nbr);
            }
        }
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
    g.insert_edge(0, 3);
    g.dfs(0);
    cout << endl;

}