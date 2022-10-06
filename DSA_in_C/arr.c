# include <stdio.h>

int arr[10];
int i, n, data, indx, choice; 

void create(); 
void display(); 
void insert(); 
void delete();
void traverse();

int main() 
{
    while(choice <= 6) 
    { 
        printf("\nSelect from below choices.\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n"); 
        printf("3.INSERT\n"); 
        printf("4.DELETE\n");
        printf("5.TRAVERSE\n"); 
        printf("6.EXIT\n"); 

        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 

        switch(choice) 
        { 
            case 1: 
            create(); 
            break; 

            case 2: 
            display(); 
            break; 

            case 3: 
            insert(); 
            break; 

            case 4: 
            delete(); 
            break; 

            case 5: 
            traverse();
            break;
        } 
    } 

    return 0; 
}

void create() 
{ 
    printf("\nEnter the size of the array: "); 
    scanf("%d", &n); 

    printf("\nEnter the elements of the array: ");
    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &arr[i]); 
    } 
}

void display() 
{ 
    int i;
    printf("\nThe array elements are:\n");
    for(i = 0; i < n; i++) 
    { 
        printf("%d\t", arr[i]); 
    } 
}

void insert() 
{ 
    printf("\nEnter the position for the new element: ");
    scanf("%d", &indx); 

    printf("\nEnter the element to be inserted: "); 
    scanf("%d", &data);

    for(i = n - 1; i >= indx; i--) 
    { 
        arr[i + 1] = arr[i]; 
    } 
    arr[indx] = data; 
    n = n + 1; 
} 

void delete()
{ 
    printf("\nEnter the position of the element to be deleted: "); 
    scanf("%d", &indx); 
    
    data = arr[indx]; 
    for(i = indx; i < n - 1; i++) 
    { 
        arr[i] = arr[i + 1]; 
    } 
    n = n - 1; 
    printf("\nThe deleted element is: %d", data); 
} 

void traverse()
{
    printf("The traverse of the array is: ");
    
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 