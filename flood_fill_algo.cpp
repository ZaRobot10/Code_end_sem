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

// input - 12 30
// ..............................
// .............#####............
// .............#...#............
// .....#########...#######......
// ....###.....######.....###....
// ....###.....###.##.....###....
// ....###......##.##.....###....
// ....###................###....
// ....###.....##.###.....###....
// .......#################......
// ..............................
// .............APPLE............

int r, c;
void floodfill (char input[][50], int i, int j, char ch, char color)
{
    // base case  - matrix bounds

    if (i < 0 || i >= r || j < 0 || j >= c)
    {
        return;
    }

    if (input[i][j] != ch)
    {
        return;
    }

    input[i][j] = color;
    cout << 1 << endl;
    floodfill(input, i + 1, j, ch, color);
    floodfill(input, i - 1, j, ch, color);
    floodfill(input, i, j + 1, ch, color);
    floodfill(input, i, j - 1, ch, color);

}


void print_matrix (char input[][50], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << input[i][j];
        }
        cout << endl;
    }
}


int main()
{
    cin >> r >> c;
    char input[15][50];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> input[i][j];
        }
    }
    cout << endl << endl;

    floodfill(input, 7, 13, '.', 'r');
    print_matrix(input, r, c);

}