#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
int data;
struct Node* start=NULL;
struct Node* temp;
struct Node* pre;
struct Node* post;
struct Node* insBegin(struct Node* start, int data)
{
   struct Node* NN=(struct Node*)malloc(sizeof(struct Node));
   NN->data=data;
   if(start==NULL)
   {
       start=NN;
       NN->next=NULL;
   }
   else
   {
       NN->next=start;
       start=NN;
   }
   printf("\n");
   return start;
}
void insEnd(struct Node* start, int data)
{
   struct Node* NN=(struct Node*)malloc(sizeof(struct Node));
   NN->data=data;
   if(start==NULL)
   {
       start=NN;
       NN->next=NULL;
   }
   else
   {
       temp=start;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
       temp->next=NN;
       NN->next=NULL;
   }
   printf("\n");
}
void insBtw(struct Node*start, int data)
{
   int val;
   printf("Enter the value before which you want to insert: ");
   scanf("%d",&val);
   struct Node* NN=(struct Node*)malloc(sizeof(struct Node));
   NN->data=data;
   temp=start;
   pre=start;
   while(temp->data!=val)
   {
       pre=temp;
       temp=temp->next;
   }
   pre->next=NN;
   NN->next=temp;
   printf("\n");
}
struct Node* delBegin(struct Node*start)
{
    temp=start;
    start=start->next;
    free(temp);
    printf("\n");
    return start;
}
struct Node* delEnd(struct Node*start)
{
    pre=start;
    temp=start;
    if(temp->next==NULL)
    {
        start=NULL; 
    }

    while(temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    
    free(temp);
    pre->next=NULL;
    return start;
    printf("\n");
}
void delBtw(struct Node*start)
{
   int val;
   printf("Enter the value of the node you want to delete: ");
   scanf("%d",&val);
   temp=pre=post=start;
   while(temp->data!=val)
   {
       pre=temp;
       temp=temp->next;
       post=temp->next;
       /*if(post->next==NULL)
        {
            printf("Element not found\n");
            break;
        }*/
   }
   free(temp);
   pre->next=post;
   printf("\n");
}
void traverse(struct Node* start)
{
    temp=start;
    if(start==NULL)
    {
        printf("List is Empty\n");
    } 
        
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
int main()
{
    int ch1, ch2;
    do
    {
        printf("1.Insertion\t2.Deletion\t3.Traversal\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            printf("1.At Beginning\t2.At the End\t3.Before a specified element\n");
            printf("Enter your choice: ");
            scanf("%d",&ch2);
            switch(ch2)
            {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                start=insBegin(start,data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d",&data);
                insEnd(start,data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d",&data);
                insBtw(start,data);
                break;
            }
            break;
        case 2:
            printf("1.Beginning\t2.End\t3.Specified element\n");
            printf("Enter your choice: ");
            scanf("%d",&ch2);
            switch(ch2)
            {
            case 1:
                start=delBegin(start);
                break;
            case 2:
                start=delEnd(start);
                break;
            case 3:
                delBtw(start);
                break;
            }
            break;
        case 3:
            traverse(start);
            printf("\n");
            break;
        }
    }while(ch1!=4);
    return 0;
} 