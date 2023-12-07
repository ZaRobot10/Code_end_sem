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
#include <list>
using namespace std;

class graph
{
    
    unordered_map<string, list<pair <string, int> > > m;

public:

    void insert_edge(string x, string y, bool bidirec, int wt)
    {
        m[x].push_back({y, wt});

        if (bidirec)
        {
            m[y].push_back({x, wt});

        }
      
    }

    void print_adj_list()
    {
        for (auto p: m)
        {
            cout << "city " << p.first << " -> "; 

            for (auto a: p.second)
            {
                cout << a.first << " " << a.second << ", ";
            } 
            cout << endl;  
        }
       
    }

};


int main()
{
    graph g;

    g.insert_edge("A", "B", true, 20);
    g.insert_edge("B", "D", true, 40);
    g.insert_edge("A", "C", true, 10);
    g.insert_edge("C", "D", true, 40);
    g.insert_edge("A", "D", false, 50);

    
    g.print_adj_list();

}
