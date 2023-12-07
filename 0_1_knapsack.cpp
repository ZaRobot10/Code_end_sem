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
#define mod 1000000007

using namespace std;

#define ll long long    
#define MAX 50000000000

int dp[1005][10005];
ll int knapsack(int wt[], int val[], int n, int w)
{
    if (n == -1)
    {
        return 0;
    }

    if (dp[w][n] != -1)
    {
        return dp[w][n];
    }
    ll int ans = 0;

    // include
    ll int op1 = 0;

    
    if (wt[n] <= w)
    {
        op1 = val[n] + knapsack(wt, val, n - 1, w - wt[n]);
    }

    // exclude
    ll int op2 = knapsack(wt, val, n - 1, w);


    ans = max(op1, op2);

    return dp[w][n] = ans;

}

int main()
{
    cout << "Number of items and maximum weight: ";
    int n, max_weight;
    cin >> n >> max_weight;
    int wt[n];
    int val[n];
    memset(dp, -1, sizeof(dp));

    cout << "Enter weight: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter value: ";

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << knapsack(wt, val, n - 1, max_weight) << endl;


}