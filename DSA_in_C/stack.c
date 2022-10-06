# include <stdio.h>

int top = -1, data, deleted, choice, stack[10];

void push(int data);
void pop();
void peep();
void traverse();
void search(int data);

void push(int data)
{
    top++;
    stack[top] = data;
}

void pop()
{
    deleted = stack[top];
    top--;
}

void peep()
{
    printf("\n%d", stack[top]);
}

void traverse()
{
    for(int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
}

void search(int data)
{
    int c = 0;
    for(int i = 0; i <= top; i++)
    {
        if(data == stack[i])
        {
            printf("%d found at %d.\n", data, i + 1);
            c++;
            break;
        }
    }
    
    if (c == 0)
    {
        printf("%d not found!\n", data);
    }
}

int main()
{
    while(choice < 6)
    {
        printf("\nSelect from below choices: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            push(data);
            break;

            case 2:
            pop();
            break;

            case 3:
            peep();
            break;

            case 4:
            traverse();
            break;

            case 5:
            printf("Enter element to be searched: ");
            scanf("%d", &data);
            search(data);
            break;
        }
    }
    return 0;
}