// source code for circular Double linked list:

 #include <stdio.h>
#include <stdlib.h>

struct cdlinklist {
    struct cdlinklist *left;
    int data;
    struct cdlinklist *right;
};

typedef struct cdlinklist node;
node *start = NULL;
int nodectr;

node* getnode() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int menu() {
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
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void cdll_createlist(int n) {
    int i;
    node *newnode, *temp;
    if (start == NULL) {
        nodectr = n;
        for (i = 0; i < n; i++) {
            newnode = getnode();
            if (start == NULL) {
                start = newnode;
                newnode->left = start;
                newnode->right = start;
            } else {
                newnode->left = start->left;
                start->left->right = newnode;
                start->left = newnode;
                newnode->right = start; // Added this line
            }
        }
    } else {
        printf("\n List already exists..");
    }
}

void cdll_display_left_right() {
    node *temp;
    if (start == NULL) {
        printf("\n Empty List:");
    } else {
        temp = start;
        printf("\n The contents of List: ");
        do {
            printf("\t%d", temp->data);
            temp = temp->right; // Corrected direction
        } while (temp != start);
    }
}

void cdll_insert_beg() {
    node *newnode;
    newnode = getnode();
    nodectr++;
    if (start == NULL) {
        start = newnode;
        newnode->left = start;
        newnode->right = start;
    } else {
        newnode->left = start->left; 
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode;
        start = newnode;
    }
}

void cdll_insert_end() {
    node *newnode, *temp;
    newnode = getnode();
    nodectr++;
    if (start == NULL) {
        start = newnode;
        newnode->left = start;
        newnode->right = start;
    } else {
        newnode->left = start->left;
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode; // Corrected
    }
    printf("\n Node Inserted at End");
}

void cdll_insert_mid() {
    node *newnode, *temp, *prev;
    int pos, ctr = 1;
    newnode = getnode();
    printf("\n Enter the position: ");
    scanf("%d", &pos);
    if (pos - nodectr >= 2) {
        printf("\n Position is out of range...");
        return;
    }
    if (pos > 1 && pos <= nodectr) {
        temp = start;
        while (ctr < pos - 1) {
            temp = temp->right;
            ctr++;
        }
        newnode->left = temp;
        newnode->right = temp->right;
        temp->right->left = newnode;
        temp->right = newnode;
        nodectr++;
        printf("\n Node Inserted at Middle...");
    } else {
        printf("Position %d of list is not a middle position", pos);
    }
}

void cdll_delete_beg() {
    node *temp;
    if (start == NULL) {
        printf("\n No nodes exist..");
        return;
    } else {
        nodectr--;
        if (nodectr == 0) { // Corrected
            free(start);
            start = NULL;
        } else {
            temp = start;
            start = start->right;
            temp->left->right = start;
            start->left = temp->left;
            free(temp);
        }
        printf("\n Node deleted at Beginning..");
    }
}

void cdll_delete_last() {
    node *temp;
    if (start == NULL) {
        printf("\n No nodes exist..");
        return;
    } else {
        temp = start->left; // Corrected
        if (temp == start) {
            free(start);
            start = NULL;
            nodectr--;
            return;
        }
        temp->left->right = start;
        start->left = temp->left;
        free(temp);
        nodectr--;
        printf("\n Node deleted at End..");
    }
}

int main() {
    int choice, n;
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("\n Enter the number of nodes: ");
                scanf("%d", &n);
                cdll_createlist(n);
                break;
            case 2:
                cdll_insert_beg();
                break;
            case 3:
                cdll_insert_end();
                break;
            case 4:
                cdll_insert_mid();
                break;
            case 5:
                cdll_delete_beg();
                break;
            case 6:
                cdll_delete_last();
                break;
            case 8:
                cdll_display_left_right();
                break;
            case 10:
                exit(0);
            default:
                printf("\n Invalid choice");
        }
    }
    return 0;
}
