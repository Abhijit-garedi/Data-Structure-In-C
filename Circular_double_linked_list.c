// source code for circular Double linked list:

 #include <stdio.h>
  #include <stdlib.h>
   
     
     struct cdlinklist
     {
        struct cdlinklist *left;
        int data;
        struct cdlinklist *right;
     };

     typedef struct cdlinklist node;
     node *start = NULL;
     int nodectr;

     node* getnode()
     {
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d", &newnode -> data);
        newnode -> left = NULL;
        newnode -> right = NULL;
        return newnode;
    }
    
    int menu()
    {
        int ch;
        printf("\n 1. Create ");
        printf("\n\n............");
        printf("\n 2. Insert a node at Beginning");
        printf("\n 3. Insert a node at End");
        printf("\n 4. Insert a node at Middle");
        printf("\n\n..............");
        printf("\n 5. Delete a node at Beginning");
        printf("\n 6. Delete a node at End");
        printf("\n 7. Delete a node at Middle");
        printf("\n\n ............");
        printf("\n 8. Display the list from Left to Right");
        printf("\n 9. Display the list from Right to Left");
        printf("\n 10.Exit");
        printf("\n\n Enter you choice: ");
        scanf("%d", &ch);
        return ch;
    }
 void cdll_createlist(int n)
 {
    int i;
    node *newnode, *temp;
    if(start == NULL)
    {
        nodectr = n;
        for(i = 0; i < n; i++)
        {
            newnode = getnode();
            if(start == NULL)
            {
                start = newnode;
                newnode -> left = start;
                newnode ->right = start;
            }
            else
            {
                newnode -> left = start -> left;
                newnode -> left->right = newnode;
                start -> left = newnode;
            }
        }
    }
    else 
    printf("\n List already exists..");
 }