# include <stdio.h>

void secsort(int arr[], int n)
{
    int i, j, min;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }

            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[10] = {30, 22, 15, 40, 2, 98, 2, 85, 99, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted Array: \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

    secsort(arr, 5);
    printf("Sorted Array by selection sorting technique: \n");

    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    printf("\n\n");

    return 0;
}