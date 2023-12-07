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
    map<int, list<int> > l;

public:
    void insert_edge(int x, int y)
    {
        l[x].push_back(y);
        
    }

    void topological_sort()
    {
        unordered_map<int, int> indegree;
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
        queue<int> q;

        for (auto p: indegree)
        {
            if (p.second == 0)
            {
                q.push(p.first);
            }
        }

        while(!q.empty())
        {
            int front = q.front();
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

    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    graph g;
    
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g.insert_edge(x, y);
    }
    
    g.topological_sort();
}
