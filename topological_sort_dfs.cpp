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

    void dfs_helper(T source, unordered_map<T, int> & visited, list <T> & ordering)
    {
        // cout << source << " ";
        visited[source] = 1;

        for (auto nbr: l[source])
        {
            if (visited[nbr] == 0)
            {
                dfs_helper(nbr, visited, ordering);
            }
        }

        ordering.push_front(source);
    }

    void dfs()
    {
        unordered_map<T, int> visited;
        list <T> ordering;
        for (auto p: l)
        {
            if (visited[p.first] == 0)
            {
                
                dfs_helper(p.first, visited, ordering);
            }
        }

        for (auto x: ordering)
        {
            cout << x << endl;
        }
       
    }

};

int main()
{
    graph <string> g;

    g.insert_edge("Python", "DataPreprocessing");
    g.insert_edge("Python", "Pytorch");
    g.insert_edge("Python", "ML");
    g.insert_edge("DataPreprocessing", "ML");
    g.insert_edge("Pytorch", "DL");
    g.insert_edge("ML", "DL");
    g.insert_edge("DL", "FaceRecogn");
    g.insert_edge("Dataset", "FaceRecogn");
    

    g.dfs();
    

}