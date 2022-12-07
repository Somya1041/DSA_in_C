# include <stdio.h>

void linear(int arr[], int size)
{
    int ele;
    printf("Enter element to be searched: ");
    scanf("%d", &ele);

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == ele)
        {
            printf("Element found at index %d.", i);
        }
    }
}

void binary(int arr[], int size)
{
    int lb = 0, ub = 9, mid = (lb + ub) / 2, ele;

    printf("Enter element to be searched: ");
    scanf("%d", &ele);

    while(lb <= ub)
    {
        mid = (lb + ub) / 2;

        if(arr[mid] == ele)
        {
            printf("Element found.");
            break;
        }

        else if(arr[mid] < ele)
        {
            lb = mid + 1;
        }

        else
        {
            ub = mid - 1;
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Linear Search.\n");
    linear(arr, 10);

    printf("\nBinary Search.\n");
    binary(arr, 10);
    return 0;
} 