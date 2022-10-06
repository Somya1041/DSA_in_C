# include <stdio.h>

int main()
{
    int arr[3][3];
    int r, c, count_zero = 0, count_nonzero = 0;

    for(r = 0; r < 3; r++)
    {
        for(c = 0; c < 3; c++)
        {
            printf("Enter elements for the matrix: ");
            scanf("%d", &arr[r][c]);

            if(arr[r][c] == 0)
            {
            count_zero++;
            }

            if(arr[r][c] != 0)
            {
            count_nonzero++;
            }
        }
    }

    printf("\nEntered matrix is:\n");

    printf("\n");

    for(r = 0; r < 3; r++)
    {
        for(c = 0; c < 3; c++)
        {
            printf("%d", arr[r][c]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    if(count_zero > count_nonzero)
    {
        printf("It is a Sparse Matrix.");        
    }

    else
    {
    printf("It is not a Sparse Matrix.");
    }
    
    return 0;
}  