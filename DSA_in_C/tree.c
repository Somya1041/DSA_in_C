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

        printf("\nLeft child.\n");
        newtree->left = createTree();

        printf("\nRight child.\n");
        newtree->right = createTree();

        return newtree;
    }
}

struct node* createnode(int val)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    
    newnode->data = val;

    newnode->left = NULL;
    newnode->right = NULL;

    return(newnode);
}

void traversePre(struct node* root)
{
    if(root == NULL)
    return;

    printf("%d\t", root->data);
    traversePre(root->left);
    traversePre(root->right);
}

void traverseIn(struct node* root)
{
    if(root == NULL)
    return;

    traverseIn(root->left);
    printf("%d\t", root->data);
    traverseIn(root->right);
}

void traversePost(struct node* root)
{
    if(root == NULL)
    return;

    traversePost(root->left);
    traversePost(root->right);
    printf("%d\t", root->data);
}

int main()
{
    printf("Given Input Tree.\n");

    struct node* root = createnode(1);

    root->left = createnode(2);
    root->right = createnode(3);

    root->left->left = createnode(4);
    root->left->right = createnode(5);
    root->right->left = createnode(6);
    root->right->right = createnode(7);

    printf("\nPreorder Traversal of above tree is: \t");
    traversePre(root);

    printf("\nInorder Traversal of above tree is: \t");
    traverseIn(root);

    printf("\nPostorder traversal of above tree is: \t");
    traversePost(root);

    printf("\n");

    printf("\nUser Input Tree.\n");

    root = createTree();

    printf("\nPreorder Traversal is: \t");
    traversePre(root);
    printf("\n");

    printf("\nInorder Traversal is: \t");
    traverseIn(root);
    printf("\n");

    printf("\nPostorder Traversal is: ");
    traversePost(root);
    
    return 0;
} 