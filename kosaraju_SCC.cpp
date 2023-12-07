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
// 7 8
// 2 1
// 1 0
// 0 2
// 0 3
// 3 5
// 5 6
// 6 3
// 3 4

// kosaraju strongly connected component algo
class graph
{
    int v;
    unordered_map < int, vector <int > > l;
    unordered_map < int, vector <int > > reversed_l;

public:

    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        reversed_l[y].push_back(x);
    }


    void dfs1(int node, unordered_map < int, int > &visited, vector <int> &stack)
    {
        visited[node] = 1;

        for (auto nbr: l[node])
        {
            if (visited[nbr] == 0)
            {
                dfs1(nbr, visited, stack);
            }

        }

        stack.push_back(node);

       
    }


    void dfs2(int node, unordered_map < int, int > &visited)
    {
        visited[node] = 1;
        cout << node << " ";

        for (auto nbr: reversed_l[node])
        {
            if (visited[nbr] == 0)
            {
                dfs2(nbr, visited);
            }

        }
       
    }


    void kosaraju_SCC()
    {
        unordered_map < int, int > visited;
        vector <int> stack;

        // step - 1 storing the vertices according to dfs finnsh time
        for (auto p: l)
        {
            int x = p.first;

            if (visited[x] == 0)
            {
                dfs1(x, visited, stack);
            }
        }

       
        // reseting the visited map
        unordered_map < int, int > visited1;

        // our ordering is in the vector stack

        // step - 2 reversing the graph (already done while taking input)

        // step - 3 do dfs according to ordering in stack in reverse graph

        char component = 'A';
        for (int i = v - 1; i >= 0; i--)
        {
            int node = stack[i];

            if (visited1[node] == 0)
            {
                cout << "component " << component <<  " --> ";
                dfs2(node, visited1);

                cout << endl;
                component ++;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m ; i++)
    {
        int x, y;
        cin >> x  >> y;

        g.add_edge(x, y);
    }

    g.kosaraju_SCC();
   
}