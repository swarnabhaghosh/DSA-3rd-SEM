#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int key;
    struct tree *left,*right;
};
typedef struct tree tree;

tree* addnode(int key)
{
    tree* root=(tree*)malloc(sizeof(tree));
    root->key=key;
    root->left=root->right=NULL;
    return root;
}

tree* insert(tree* root,int item)
{
    if(root==NULL)
        return addnode(item);
    if(root->key==item)
        return root;
    if(root->key<item)
        root->right=insert(root->right,item);
    if(root->key>item)
        root->left=insert(root->left,item);
    return root;
}
void preorder(tree* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(tree* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
void postorder(tree* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}
void main()
{
    tree* root=NULL;
    int a,c,y=1;
    while(y)
    {
        printf("\n1.Insert \n2.Preorder \n3.Inorder \n4.Postorder \n5.Exit \nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter value:");
            scanf("%d",&a);
            root=insert(root,a);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            y=0;
            printf("ending");
            break;
        default:
            printf("\nIncorrect input");
        }
    }
}
