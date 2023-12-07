#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <limits.h>


int swaps_b = 0, comparions_b = 0;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparions_b ++;
            if (arr[j] > arr[j + 1])
            {
                swaps_b ++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }

}

int swaps_s = 0, comparions_s = 0;

void selection_sort(int arr[], int n)
{
     for (int i = 0; i < n - 1; i++)
    {
        int max = INT_MIN;
        int max_index = -1;
        for (int j = 0; j < n - i; j++)
        {
            comparions_s ++;
            if (arr[j] > max)
            {
                max = arr[j];
                max_index = j;
            }
        }

        swaps_s ++;
        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[max_index];
        arr[max_index] = temp;
    }
}

int swaps_i = 0, comparions_i = 0;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int element = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            comparions_i ++;
            if (element < arr[j])
            {
                swaps_i ++;
                arr[j + 1] = arr[j]; 

                if (j == 0)
                {
                    arr[j] = element;
                }
            }
            
            else
            {
                arr[j + 1] = element;
                break;
            }
        }

       
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }


    bubble_sort(temp, n);


    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    selection_sort(temp, n);
    

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }

    insertion_sort(temp, n);

    
    printf("\n");
    printf("Sorting Used\t\t\t number of swaps used\t\t\t number of comparisions\n");

    printf("Bubble Sort\t\t\t %d\t\t\t\t\t %d\n", swaps_b, comparions_b);
    printf("Selection Sort\t\t\t %d\t\t\t\t\t %d\n", swaps_s, comparions_s);
    printf("Insertion Sort\t\t\t %d\t\t\t\t\t %d\n", swaps_i, comparions_i);


}

// 1st class
// output in table form
// number of swaps used
// number of comparisions

// bubble sort number of s


// sort a given set of elemetns using the quick sort method and determine, the time required to sort the elements .
// repeat the experiment for different values of n, number of elements in the list to be sorted. the elements can be read
// from a file or can be generated using the random number generator

