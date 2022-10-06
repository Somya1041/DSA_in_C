# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* temp;
struct node* pre;
struct node* post;

int data;

struct node* insbeg(struct node* start, int data)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node));

    newnode->data = data;

    if(start == NULL)
    {
        start = newnode;
        newnode->next = NULL;
    }

    else
    {
        newnode->next = start;
        start = newnode;
    }
    return start;
}

void insend(struct node* start, int data)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    
    newnode->data = data;

    if(start == NULL)
    {
        start = newnode;
        newnode->next = NULL;
    }

    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
    }

    temp->next = newnode;
    newnode->next = NULL;
}

void insatpos(struct node* start, int data)
{
    int val;
    printf("\nEnter where to insert: ");
    scanf("%d", &val);

    struct node* newnode = (struct node* )malloc(sizeof(struct node));

    newnode->data = data;

    temp = pre = start;

    while(temp->data != val)
    {
        pre = temp;
        temp = temp->next;
    }

    pre->next = newnode;
    newnode->next = temp;
}

struct node* delbeg(struct node* start)
{
    temp = start;
    start = start->next;
    
    free(temp);

    return start;
}

struct node* delend(struct node* start)
{
    temp = pre = start;

    if(temp->next == NULL)
    {
        start = NULL;
    }

    while(temp->next != NULL)
    {
        pre = temp;
        temp = temp->next;
    }

    pre->next = NULL;
    free(temp);

    return start;
}

void delatpos(struct node* start)
{
    int val;
    printf("\nEnter where to delete: ");
    scanf("%d", &val);

    temp = pre = post = start;

    while(temp->next->data != val)
    {
        pre = temp;
        temp = temp->next;
        post = temp->next;
    }

    pre->next = post;
    free(temp);
}

void traverse(struct node* start)
{
    temp = start;

    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }

    else
    {
        printf("\nTraversing is: ");

        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }

    printf("\n");
}

int main()
{
    start = insbeg(start, 50);
    start = insbeg(start, 40);
    start = insbeg(start, 30);
    start = insbeg(start, 20);
    start = insbeg(start, 10);
    traverse(start);

    insend(start, 60);
    insend(start, 70);
    insend(start, 80);
    insend(start, 90);
    insend(start, 100);
    insend(start, 110);
    traverse(start);

    insatpos(start, 1041);
    traverse(start);

    start = delbeg(start);
    traverse(start);

    start = delend(start);
    traverse(start);

    delatpos(start);
    traverse(start);

    int ch1, ch2;

    while(ch1 != 4)
    {
        printf("\nSelect from below choices: ");
        printf("\n1. Insertion.");
        printf("\n2. Deletion.");
        printf("\n3. Traversal.");
        printf("\n4. Exit.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch1);

        switch(ch1)
        {
            case 1:
            printf("\n\t1. Insertion at beginning.\n");
            printf("\t2. Insertion at end.\n");
            printf("\t3. Insertion at position.\n");

            printf("\nEnter choice: ");
            scanf("%d", &ch2);

            switch(ch2)
            {
                case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                start = insbeg(start, data);
                break;

                case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insend(start, data);
                break;

                case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insatpos(start, data);
                break;

                default:
                printf("\nINVALID CHOICE.\n");
                break;
            }
            break;

            case 2:
            printf("\n\t1. Deletion at beginning.\n");
            printf("\t2. Deletion at end.\n");
            printf("\t3. Deletion at position.\n");

            printf("\nEnter choice: ");
            scanf("%d", &ch2);

            switch(ch2)
            {
                case 1:
                start = delbeg(start);
                break;

                case 2:
                start = delend(start);
                break;

                case 3:
                delatpos(start);
                break;

                default:
                printf("\nINVALID CHOICE.\n");
                break;
            }
            break;

            case 3:
            traverse(start);
            break;
        }
    }

    return 0;
} 