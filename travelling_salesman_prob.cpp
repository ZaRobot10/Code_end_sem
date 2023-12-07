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


int n = 4;

// dp[mask][pos]
int dp[16][4];

// adj matrix which defines the graph
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10}, 
    {25, 34, 10, 0}
};

// if all cities have been visited
int visited_all = (1 << n) - 1;

// tsp - travelling salesman problem

bool flag = true;
int intial_pos;

int tsp (int mask, int pos)
{
    if (flag)
    {
        intial_pos = pos;
        flag = false;
    }

    if (mask == visited_all)
    {
        return dist[pos][intial_pos];
    }

    // lookup
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {   
        if ((mask & (1 << i)) == 0)
        {
            int current_ans = dist[pos][i] + tsp(mask | (1 << i), i);
            ans = min(ans, current_ans);
            
        }
    }   

    return dp[mask][pos] = ans;
}

int main()
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    // at starting point give the mask corresponding to the position
    cout << "Min weight hamiltonian path costs " << tsp(1, 0) << endl;
}