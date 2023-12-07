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


// using bfs
class graph
{
    map<T, list<T> > l;

public:
    void insert_edge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

        
    }

    bool is_tree()
    {
        unordered_map<T, int> visited;
        unordered_map<T, T> parent;
        queue<T> q;
        int source = 0;
        visited[source] = 1;
        q.push(source);

        while(!q.empty())
        {
            T front = q.front();

            for (auto nbr: l[front])
            {
                if (visited[nbr] == 0)
                {
                    q.push(nbr);
                    visited[nbr] = 1;
                    parent[nbr] = front;
                    
                }

                else
                {
                    if (nbr == parent[front])
                    {
                        
                    } 

                    else
                    {
                        // cout << nbr << endl;
                        return false;
                    }

                }
            }
            q.pop();
        }

        return true;

        
    }
   


};

int main()
{
    graph <int> g;

    g.insert_edge(0, 1);
    g.insert_edge(3, 2);
    g.insert_edge(1, 2);
    g.insert_edge(0, 3);
   
    if (g.is_tree())
    {
        cout << "There is a tree" << endl;
    }

    else
    {
        cout << "Tree does not exist" << endl;
    }
}