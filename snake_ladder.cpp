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
        
    }

    int bfs(T source, T dest)
    {
        map<T, int> dist;
        unordered_map<T, T> parent;
        queue <T> q;
        q.push(source);

        for (auto p: l)
        {
            dist[p.first] = INT_MAX;
        }

        // to show that dest is invisited
        dist[dest] = INT_MAX;

        dist[source] = 0;
        
        parent[source] = source;

        while(!q.empty())
        {

            T front = q.front();
            // cout << front << " ";
            // go to its neighbours
            for (auto x: l[front])
            {
                // if the node is unvisited
                if (dist[x] == INT_MAX)
                {
                    parent[x] = front;
                    q.push(x);
                    dist[x] = dist[front] + 1;
                }
            }

            q.pop();
        }

        // for (auto p: dist)
        // {
        //     cout << "Node " << p.first << " Dist from src " << p.second << endl;
        // }


        // for printing path
        T temp = dest;
        while (temp != source)
        {
            cout << temp << "<-";
            temp = parent[temp];
        }

        cout << source << endl;
        return dist[dest];
       
    }
    
    
};

int main()
{
    graph <int> g;

    int board[50] = {0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -34;

    
    // if a piece of board has a snake or ladder, then it would take infinte (int max) steps to reach it
    for (int i = 0; i < 36; i++)
    {
        for (int dice = 1; dice <= 6; dice ++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.insert_edge(i, j);
            }
        }
    }

    // there is no 36 edge, so we need to add it
    // g.insert_edge(36, 36);

    // instead of that we can do  dist[dest] = INT_MAX;

    cout << g.bfs(0, 36) << endl;

}