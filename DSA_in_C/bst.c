# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

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

struct node* createNode(int val)
{
    struct node* newnode = (struct node* )malloc(sizeof(struct node));

    newnode->data = val;

    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
    {
        return createNode(val);
    }
    
    else if(val < root->data)
    {
        root->left = insert(root->left, val);
    }

    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(struct node* temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

// struct node* delete(struct node* root, int val)
// {
//     if(root == NULL)
//     {
//         return NULL;
//     }

//     else if(root->left == NULL && root->right == NULL)
//     {
//         free(root);
//     }

//     else
//     {
//         struct node* pred;
//         pred = inpred(root, val);
//         root->val = pred->val;
//         root->left = delete(root->left, pred->val);
//     }
// }

struct node* inpred(struct node* root, int val)
{
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = val;
    while(temp->right = NULL)
    {
        temp = temp->right;
    }
    return temp;
}

struct node* delete(struct node* root, int val)
{
    if(root == NULL)
    {
        return root;
    }

    if(val < root->data)
    {
        root->left = delete(root->left, val);
    }

    else if(val > root->data)
    {
        root->right = delete(root->right, val);
    }

    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            struct node* temp = inpred(root->left, val);
            root->data = temp->data;
            root->left  = delete(root->left, temp->data);
        }
    }
}

int main()
{
    root = createTree();

    root = insert(root, 100);
    root = insert(root, 150);
    root = insert(root, 200);
    root = insert(root, 250);
    root = insert(root, 300);

    printf("\nInorder Traversal is: \t");
    inorder(root);

    int val;
    printf("\nEnter which node to be deleted: ");
    scanf("%d", &val);

    root = delete(root, val);
    printf("Traversal after deletion is: \t");
    inorder(root);

    return 0;
} 