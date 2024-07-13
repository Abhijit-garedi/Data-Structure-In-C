

  // PROGRAM

    #include <stdio.h>
    #include <stdlib.h>

    // Definition of a binary tree node
  struct Node 
  {
    int data;
    struct Node* left;
    struct Node* right;
  };


  // Stack implementation for iterative traversal
   struct Stack {
    int top;
    int capacity;
    struct Node** array;
    };

  // Utility function to create a new node
   struct Node* newNode(int data) 
   {
     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
   }

   // Utility function to create a stack
   struct Stack* createStack(int capacity) 
   {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
    }

   // Stack operations
  int isFull(struct Stack* stack)
   {
    return stack->top == stack->capacity - 1;
  }

  int isEmpty(struct Stack* stack) 
   {
    return stack->top == -1;
   }



   void push(struct Stack* stack, struct Node* node) 
   {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
    } 

   struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
    }



    struct Node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
   }



   // Iterative Inorder Traversal
    void inorderTraversal(struct Node* root)
     {
    struct Stack* stack = createStack(100);
    struct Node* current = root;

    while (!isEmpty(stack) || current != NULL) {
        if (current != NULL) {
            push(stack, current);
            current = current->left;
        } else {
            current = pop(stack);
            printf("%d ", current->data);
            current = current->right;
        }
    }
    printf("\n");
   }

     // Iterative Preorder Traversal
     void preorderTraversal(struct Node* root) 
     {
      if (root == NULL)
        return;

      struct Stack* stack = createStack(100);
      push(stack, root);

       while (!isEmpty(stack)) 
       {
        struct Node* current = pop(stack);
        printf("%d ", current->data);

        if (current->right)
            push(stack, current->right);
        if (current->left)
            push(stack, current->left);
     }
     printf("\n");
    }

// Iterative Postorder Traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    struct Stack* output = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        push(output, current);

        if (current->left)
            push(stack, current->left);
        if (current->right)
            push(stack, current->right);
    }

    while (!isEmpty(output)) {
        struct Node* current = pop(output);
        printf("%d ", current->data);
    }
    printf("\n");
}

// Main function to test the traversal functions
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal: ");
    inorderTraversal(root);

    printf("Preorder traversal: ");
    preorderTraversal(root);

    printf("Postorder traversal: ");
    postorderTraversal(root);

    return 0;
}
