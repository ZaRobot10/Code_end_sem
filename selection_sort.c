#include <stdio.h>
#include <limits.h>


int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int max = INT_MIN;
        int max_index = -1;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
                max_index = j;
            }
        }

        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[max_index];
        arr[max_index] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}    