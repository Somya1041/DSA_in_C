#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
	// if (left < size && arr[left] < arr[largest]) //For Min Heap
		largest = left;
	
	if (right < size && arr[right] > arr[largest])
	// if (right < size && arr[right] < arr[largest]) // For Min Heap
		largest = right;

	if (largest != i) 
    {
    	swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size)
{
	for(int i = size / 2 - 1; i >= 0; i--)
    {
		heapify(arr, size, i);
    }

	for(int i = size - 1; i >= 0; i--) 
    {
		swap(&arr[0], &arr[i]);
		
		heapify(arr, i, 0);
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
	int arr[] = {12, 11, 13, 5, 6};
	int size = sizeof(arr) / sizeof(arr [0]);
    printf("Unsorted Array: \n");
    print(arr, size);

	heapSort(arr, size);
	printf("Sorted array is: \n");
	print(arr, size);
}