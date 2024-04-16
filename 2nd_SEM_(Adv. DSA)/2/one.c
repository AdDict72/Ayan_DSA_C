/*Write a C program to create a binary tree using recursive function and display that level wise.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct TreeNode
{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};

struct TreeNode *createNode(int data){
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int data){
    if(root==NULL){
        root = createNode(data);
    }
    else{
        if(data<=root->data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
    }
    return root;
}

void levelOrderTraversal(struct TreeNode *root){
    if(root == NULL){
        return;
    }
    struct TreeNode *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        struct TreeNode *temp =queue[++front];
        printf("%d ",temp->data);

        if(temp->left != NULL){
            queue[++rear] = temp->left;
        }
        if(temp->right!=NULL){
            queue[++rear]=temp->right;
        }
    }
}

int treeHeight(struct TreeNode*root){
    if (root==NULL)
    {
        return 0;
    }
    else{
        int leftH=treeHeight(root->left);
        int rightH=treeHeight(root->right);
        return (leftH>rightH) ? (leftH+1) : (rightH+1) ;
    }
}

int nodeDegree(struct TreeNode * root, int key){
    if (root ==NULL)
    {
        return -1;
    }
    if(root->data == key){
        int degree=0;
        if (root->left!=NULL)
        {
            degree++;
        }
        if (root->right!=NULL)
        {
            degree++;
        }
        return degree;
    }
    else {
        int leftD = nodeDegree(root->left,key);
        int rightD = nodeDegree(root->right,key);
        if (leftD!=-1){
            return leftD;
        }
        else{
            return rightD;
        }      
    }
}

int countLeaf(struct TreeNode * root){
    if (root==NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeaf(root->left)+countLeaf(root->right);   
}

void displayMenu(){
    printf("=====Menu=====");
    printf("\n 1. Create binary tree using recursive function : ");
    printf("\n 2. Identify the height of binary tree : ");
    printf("\n 3. Identify degree of a given node : ");
    printf("\n 4. No. of leaf node in binary tree : ");
    printf("\n 5. No. of internal node in binary tree : ");
    printf("\n 6. No. of node in a binary tree using linked-list : ");
    printf("\n 7. No. of node in a binary tree using array : ");
    printf("\n 8. No. of siblings in binary tree : ");\
}

int main(){
    int data, n, choice, key, noLeaf;
    struct TreeNode *root =NULL;

    do
    { 
        displayMenu();
        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data for bianry tree(-1 for stop): ");
            while (1)
            {
                scanf("%d",&data);
                if(data == -1){
                    break;
                }
                root=insert(root,data);
            }
            printf("Binary tree created successfully.\n");
            printf("Level Order Traversal of the binary tree: ");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 2:
            printf(" Height of binary tree: %d\n", treeHeight(root));
            break;
        case 3:
            printf(" Enter a key to find degree : ");
            scanf("%d",&key);
            int deg = nodeDegree(root,key);
            if(deg == -1){
                printf("Node not found in the tree.\n");
            }else{
                printf("Degree of node %d: %d\n", key, deg);
            }
            break;
        case 4:
            noLeaf = countLeaf(root);
            printf("Number of leaf Nodes : %d \n",noLeaf);
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;        
        default:  
            printf("You entered wrong choice....!!");        
            break;
        }
       

    
    } while (choice != 0);
    
    return 0;
}