# include <stdio.h>

void search(int arr[], int ele, int lb, int ub)
{
    int mid = (lb + ub) / 2;

    if(arr[mid] == ele)
    {
        printf("Element found.");
    }

    else if(arr[mid] < ele)
    {
        search(arr, ele, mid + 1, ub);
    }

    else
    {
        search(arr, ele, lb, mid - 1);
    }
}

int main()
{
    int ele, temp;

    int arr[10] = {2, 5, 1, 6, 4, 10, 7, 3, 9, 8};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted Array is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n\n");

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted Array is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n\nEnter element to be searched: ");
    scanf("%d", &ele);
    search(arr, ele, 0, size);

    return 0;
}