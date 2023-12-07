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

    for (int i = 1; i < n; i++)
    {
        int element = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (element < arr[j])
            {
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

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}    