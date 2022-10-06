# include <stdio.h>

int i, data, deleted, queue[50], front = -1, rear = -1, choice;

void insert(int data);
void delete();
void display();
void search(int data);

void insert(int data)
{
    if(rear == sizeof(queue[i]))
    {
        printf("Overflow.");
        return;
    }

    if(front == -1 && rear == -1)
    {
        front++;
        rear = front;
        queue[front] = data;
    }

    else
    {
        rear++;
        queue[rear] = data;
    }
}

void delete()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty.");
    }

    else
    {
        deleted = queue[front];
        printf("Deleted element: %d", queue[front]);
        front++;
    }
}

void display()
{
    if(rear == -1)
    {
        printf("\nQueue is full.");
    }
    else
    {
        printf("\nElements of the queue are: ");
        for(i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

void search(int data)
{
    int  c = 0;
    for(i = front; i <= rear; i++)
    {
        if(data == queue[i])
        {
            printf("%d found at %d.\n", data, i);
            c++;
            break;
        }
    }
    
    if(c == 0)
    {
        printf("%d not found.\n", data);
    }
}

int main()
{
     while(choice <= 4)
    {
        printf("\nSelect from below choices: \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Searching\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter the element: ");
            scanf("%d", &data);
            insert(data);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Element to be searched: ");
            scanf("%d", &data);
            search(data);
            break;
        }
    }
    return 0;
}