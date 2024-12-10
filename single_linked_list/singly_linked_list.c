// Single linked list with all the operations

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int data;
    struct node *next;
} node;

node *start = NULL;

// Function declarations for all the operations
node *create_ll(node *);
node *display(node *);
node *insert_beg(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
node *delete_beg(node *);
node *delete_end(node *);
node *delete_node(node *);
node *delete_after(node *);
node *delete_list(node *);
node *sort_list(node *);

int main() {
    int option;
    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1:  Create a list");
        printf("\n 2:  Display the list");
        printf("\n 3:  Add a node at the beginning");
        printf("\n 4:  Add a node at the end");
        printf("\n 5:  Add a node before a given node");
        printf("\n 6:  Add a node after a given node");
        printf("\n 7:  Delete a node from the beginning");
        printf("\n 8:  Delete a node from the end");
        printf("\n 9:  Delete a specific node");
        printf("\n10:  Delete after a given node");
        printf("\n11:  Delete the entire list");
        printf("\n12:  Sort the list");
        printf("\n13:  Exit");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option) {
            case 1: start = create_ll(start);
                    printf("\n LINKED LIST CREATED");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_beg(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = insert_before(start);
                    break;
            case 6: start = insert_after(start);
                    break;
            case 7: start = delete_beg(start);
                    break;
            case 8: start = delete_end(start);
                    break;
            case 9: start = delete_node(start);
                    break;
            case 10: start = delete_after(start);
                     break;
            case 11: start = delete_list(start);
                     printf("\n LINKED LIST DELETED");
                     break;
            case 12: start = sort_list(start);
                     break;
        }
    } while (option != 13);
    return 0;
}

//create a linked list
node *create_ll(node *start) {
  node *new_node,*ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data:\n");
  scanf("%d",&num);
  while(num != -1) {
    
