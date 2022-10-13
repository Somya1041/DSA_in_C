# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int data;
struct node* root;

struct node* createTree()
{
    int val;
    printf("Enter data: ");
    scanf("%d", &val);

    if(val == -1)
    {
        return NULL;
    }

    else
    {
        struct node* newtree = (struct node* )malloc(sizeof(struct node));
        newtree->data = val;

        printf("Left child.\n");
        newtree->left = createTree();

        printf("Right child.\n");
        newtree->right = createTree();

        return newtree;
    }
}

void Inorder(struct node* temp)
{
    if(temp != NULL)
    {
    Inorder(temp->left);
    printf("%d\t", temp->data);
    Inorder(temp->right);
    }

    else
    {
        return;
    }
}

void Preorder(struct node* temp)
{
    if(temp != NULL)
    {
    printf("%d\t", temp->data);
    Inorder(temp->left);
    Inorder(temp->right);
    }

    else
    {
        return;
    }
}

void Postorder(struct node* temp)
{
    if(temp != NULL)
    {
    Inorder(temp->left);
    Inorder(temp->right);
    printf("%d", temp->data);
    }

    else
    {
        return;
    }
}

int main()
{
    root = createTree();

    printf("Preorder Traversal is: \t");
    Inorder(root);
    printf("\n");

    printf("Inorder Traversal is: \t");
    Preorder(root);
    printf("\n");

    printf("Postorder Traversal is: ");
    Postorder(root);
    return 0;
} 