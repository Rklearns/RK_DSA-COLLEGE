#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
} *root = NULL;

// Function prototypes
int countleafnode(struct node* root);
int counttotalnode(struct node* root);
int countinternalnode(struct node* root);
int height(struct node* root);
struct node* mirrorimage(struct node* root);
void inorder(struct node* root);
struct node* createnode(int value);

int main() {
    root = createnode(100);
    root->left = createnode(80);
    root->right = createnode(120);
    root->left->left = createnode(70);
    root->left->right = createnode(90);
    root->right->left = createnode(110);
    root->right->right = createnode(130);

    /*
        Tree Structure:
                 100
               /     \
             80       120
            /  \     /   \
          70    90  110   130
    */

    int n;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Height of tree\n");
        printf("2. Mirror image\n");
        printf("3. Count leaf nodes\n");
        printf("4. Count internal nodes\n");
        printf("5. Count total nodes\n");
        printf("6. In-order traversal\n");
        printf("7. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Height of the tree is %d\n", height(root));
                break;
            case 2:
                printf("Before mirror image (In-order): ");
                inorder(root);
                printf("\nAfter mirror image (In-order): ");
                mirrorimage(root);
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Number of leaf nodes: %d\n", countleafnode(root));
                break;
            case 4:
                printf("Number of internal nodes: %d\n", countinternalnode(root));
                break;
            case 5:
                printf("Total number of nodes: %d\n", counttotalnode(root));
                break;
            case 6:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting the code...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (n != 7);

    return 0;
}

// Function to create a new node
struct node* createnode(int value) {
    struct node* x = (struct node*)malloc(sizeof(struct node));
    x->right = NULL;
    x->left = NULL;
    x->data = value;
    return x;
}

// Function to calculate the height of the tree
int height(struct node* root) {
    if (root == NULL)
        return 0;

    int x = height(root->left);
    int y = height(root->right);

    return (x > y) ? x + 1 : y + 1;
}

// Function to count the number of leaf nodes
int countleafnode(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countleafnode(root->left) + countleafnode(root->right);
}

// Function to count the number of internal nodes
int countinternalnode(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countinternalnode(root->left) + countinternalnode(root->right);
}

// Function to count the total number of nodes
int counttotalnode(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + counttotalnode(root->left) + counttotalnode(root->right);
}

// Function to create a mirror image of the tree
struct node* mirrorimage(struct node* root) {
    if (root != NULL) {
        mirrorimage(root->left);
        mirrorimage(root->right);

        // Swap the left and right child nodes
        struct node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

// Function for in-order traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
