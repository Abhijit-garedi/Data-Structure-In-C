// C program that implements in-order, pre-order, and post-order traversals of a binary tree using iterative functions


//program:

    #include <stdio.h>
    #include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void iterativeInOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void iterativePreOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    
    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);
        
        if (current->right != NULL) stack[++top] = current->right;
        if (current->left != NULL) stack[++top] = current->left;
    }
}

void iterativePostOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    
    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;
        
        if (current->left != NULL) stack1[++top1] = current->left;
        if (current->right != NULL) stack1[++top1] = current->right;
    }
    
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Iterative In-order traversal: ");
    iterativeInOrder(root);
    printf("\n");

    printf("Iterative Pre-order traversal: ");
    iterativePreOrder(root);
    printf("\n");

    printf("Iterative Post-order traversal: ");
    iterativePostOrder(root);
    printf("\n");

    return 0;
}
