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


class graph
{
    int v;
    list<int> *l;

public:
// assuming vertices to be from 0 to n - 1
// eg- number of vertices are 4
// the vertices are 0, 1, 2, 3

    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    // assuming edge is bidirectional, so the edge is inserted in both
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print_adj_list()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (auto x: l[i])
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(2, 3);
    g.addedge(1, 2);

    g.print_adj_list();

}