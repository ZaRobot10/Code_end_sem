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
    unordered_map <int, vector < pair < int, int > >  > l;

public:

    graph(int V)
    {
        v = V;
    }

    void add_edge(int x, int y, int w)
    {   
        l[x].push_back({y, w});
        l[y].push_back({x, w});

    }   
    

    int dfs_helper(int node, unordered_map < int, int > &visited, int &ans)
    {
        
        visited[node] = 1;
        int count  = 0;
        for (auto nbr: l[node])
        {
            int y = nbr.first;
            int w = nbr.second;

            if (visited[y] == 0)
            {
                int count_neighbour = dfs_helper(y, visited, ans);
                int nx = count_neighbour;
                int ny = v - nx;

                ans += 2 * min(nx, ny) * w;
                count += count_neighbour;
            }   

        }

        return count + 1;
    }   


    int dfs()       
    {
        unordered_map < int, int > visited;
        int src = 0;
        int ans = 0;

        dfs_helper(0, visited, ans);
        
        return ans;

    }

};

int main()
{
    graph g(4);

    g.add_edge(0, 1, 3);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 2);

    cout << g.dfs() << endl;

}