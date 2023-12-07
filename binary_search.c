#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // binary search
    int element;
    scanf("%d", &element);

    int s = 0, e = n - 1;
    
    int index = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == element)
        {
            index = mid;
            break;
        }

        else if (element < arr[mid])
        {
            e = mid - 1;
        }

        else
        {   
            s = mid + 1;
        } 


    }


    if (index == -1)
    {
        printf("Not found\n");
    }

    else
    {
        printf("element found at index %d\n", index);
    }
}