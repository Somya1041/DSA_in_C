# include <stdio.h>

int main()
{
    int arr1[2][2], arr2[2][2], result[2][2];
    int r, c;

    for(r = 0; r < 2; r++)
    {
        for(c = 0; c < 2; c++)
        {
            printf("Enter values for arr1 and arr2: ");
            scanf("%d %d", &arr1[r][c], &arr2[r][c]);
            result[r][c] = arr1[r][c] * arr2[r][c];
        }
    }
    
    printf("\n");

    for(r = 0; r < 2; r++)
    {
        for(c = 0; c < 2; c++)
        {
            printf("%d", result[r][c]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");
    
    return 0;
} 