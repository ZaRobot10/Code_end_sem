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

    void topological_sort()
    {
        unordered_map<T, int> indegree;
        // find indegrees

        for (auto p: l)
        {
            indegree[p.first] = 0;
        }

        for (auto p: l)
        {
            for (auto x: p.second)
            {
                indegree[x] ++;
            }
        }

        // find vertices with zero indegree
        queue<T> q;

        for (auto p: indegree)
        {
            if (p.second == 0)
            {
                q.push(p.first);
            }
        }

        while(!q.empty())
        {
            T front = q.front();
            cout << front << " ";
            for (auto nbr: l[front])
            {
                indegree[nbr] --;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
            q.pop();
        }
        cout << endl;
    }
   


};

int main()
{
    graph <int> g;

    g.insert_edge(0, 2);
    g.insert_edge(1, 2);
    g.insert_edge(1, 4);
    g.insert_edge(2, 3);
    g.insert_edge(2, 5);
    g.insert_edge(4, 5);
    g.insert_edge(3, 5);
    
    g.topological_sort();
}