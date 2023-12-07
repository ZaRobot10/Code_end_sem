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

int get_digit(int n, int d)
{
    int ans = 0;
    while (d != 0)
    {
        ans = n % 10;
        n /= 10;
        d--;
    }

    return ans;
}


int sorted_arr[10000];
// first will be digit, second will be the number
void count_sort(pair< int, int >  arr[], int n)
{
    int counting_array[10] = {0};
    
    for (int i = 0; i < n; i++)
    {
        int digit = arr[i].first;
        counting_array[digit] ++;
    }

    // cout << 5434545 << endl;
    // make counting_arr as csum arr
    int csum = counting_array[0];
    for (int i = 1; i < 10; i++)
    {
        counting_array[i] += csum;
        csum = counting_array[i];
    }

    // cout << 5434545 << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i].first;
        sorted_arr[counting_array[num] - 1] = arr[i].second;
        counting_array[num] --;
    }


}


void bucketSort(int arr[], int n, int max_el, int min_el) 
{
    int bucket_size = 10;
    
    
    int range = max_el - min_el + 1;
    int bucket_count = (range / bucket_size) + 1;
    
    vector <int> buckets[bucket_count];
    
    for (int i = 0; i < n; i++) 
    {
        int index = (arr[i] - min_el) / bucket_size;
        buckets[index].push_back(arr[i]);
    }
    
    int index = 0;
    for (int i = 0; i < bucket_count; i++) 
    {
        sort(buckets[i].begin(), buckets[i].end());

        for (int j = 0; j < buckets[i].size(); j++) 
        {
            arr[index] = buckets[i][j];
            index ++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    
    cout << "enter number of numbers: ";
    int n;
    cin >> n;

    
    int arr[n];
   
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
       
        sorted_arr[i] = arr[i];

        largest = max(largest, arr[i]);
        smallest = min(smallest, arr[i]);
        
    }

    cout << "Elements before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<  " ";
    }

    cout << endl;
    int Largest = largest;
    clock_t start, end;
    start = clock();
    // count number of digits of largest number

    int count  = 0;
    while (Largest != 0)
    {   
        count ++;
        Largest /= 10;

    }

    pair < int, int > to_sort[n];

    int d = 1;
    while (d != count + 1)
    {
       
    
    for (int i = 0; i < n; i++)
    {
        to_sort[i].second = sorted_arr[i];
        to_sort[i].first = get_digit(sorted_arr[i], d);
        
    }

    count_sort(to_sort, n);
    d++;
    }


    cout << "elements after radix sort" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << sorted_arr[i] << " ";
    }
    

    cout << endl;
     cout << fixed << setprecision(6);
    end = clock();
    double diff_t;
        diff_t = difftime(end, start) / (CLOCKS_PER_SEC);
    cout << diff_t << endl;

    // gcl123

    // bucket sort

    cout << "elements after bucket sort" << endl;

    start = clock();
   
    bucketSort(arr, n, largest, smallest);
    
     end = clock();
     diff_t = difftime(end, start) / (CLOCKS_PER_SEC);
   
    cout << diff_t << endl;
}