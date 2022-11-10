# include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int arr[], int lb, int ub)
{
    int pivot = arr[ub];
    int i = (lb - 1);

    for(int j = lb; j < ub; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[ub]);
    return(i + 1);
}

void quick(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int j = part(arr, lb, ub);
        quick(arr, lb, j - 1);
        quick(arr, j + 1, ub);
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[10] = {32, 5, 23, 14, 20, 98, 2, 85, 99, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("\nUnsorted Array: \n");
    print(arr, size);

    quick(arr, 0, size - 1);
    printf("\nSorted Array: \n");
    print(arr, size);

    return 0;
} 