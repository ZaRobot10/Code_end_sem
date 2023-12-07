#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int swaps;
int make_partion(int arr[], int s, int e)
{
   
    // pivoting last element

    // j represents the first segment
    int j = s - 1;
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= arr[e])
        {
            swaps ++;

            int temp = arr[j + 1];
            arr[j + 1] = arr[i];
            arr[i] = temp;

            j++;
        }
    }
    int index = j + 1;

    // swapping the pivot element into the right place
    swaps ++;
    int temp = arr[index];
    arr[index] = arr[e];
    arr[e] = temp;
    
    return index;
}

void quicksort(int arr[], int s, int e)
{   
    if (s >= e)
    {
        return;
    }

    int index = make_partion(arr, s, e);

    quicksort(arr, s, index - 1);
    quicksort(arr, index + 1, e);

}   

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        swaps = 0;
        int n;
        scanf("%d", &n);

        int arr[n];
       

        for (int i = 0; i < n; i++)
        {   // Random Generator.
            arr[i] = (rand()) % 100;
        }

        printf("Before Sorting: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");

        clock_t start, end;
        

        start = clock();
        quicksort(arr, 0, n - 1);

        end = clock();
        // time time_used = difftime (start, end);
        double diff_t;
        diff_t = difftime(end, start) / (CLOCKS_PER_SEC);
        
         printf("After Sorting: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");

        printf("Number of swaps: %d\n", swaps);
        printf("time taken - %f\n\n", diff_t);


        
    }
}


