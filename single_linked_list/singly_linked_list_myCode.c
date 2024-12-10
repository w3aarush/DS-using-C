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
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    new_node->next = NULL;
    if(start == NULL)
        start = new_node;
    else {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    printf("Enter data\n");
    scanf("%d",&num);
  }
  return start;
}

//display list
node *display(node *start) {
    node *ptr;
    ptr = start;
    if(ptr==NULL)
        printf("\nLIST is emptly.");
    else {
        while(ptr!=NULL) {
            printf("%d",ptr->data);
            ptr = ptr->next;
        }
    }
    return start;
}

//insert at the beginning
node *insert_beg(node *start) {
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    printf("Enter value\n");
    scanf("%d",&(new_node->data));
    new_node->next = start;
    start = new_node;
    return start;
}

//insert at the end
node *insert_end(node *start) {
    node *new_node,*ptr;
    new_node = (node *)malloc(sizeof(node));
    printf("Enter value\n");
    scanf("%d",&(new_node->data));
    new_node->next = NULL;
    if(start == NULL)
        start = new_node;
    else{
        ptr = start;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

//insert before a node
node *insert_before(node *start) {
    node *new_node, *preptr = NULL, *ptr;
    new_node = (node *)malloc(sizeof(node));

    //checking memory allocation
    if(new_node==NULL) {
        printf("Memory Allocation Failed.\n");
        return start;
    }
    //taking data input
    printf("Enter your data:\n");
    scanf("%d",&(new_node->data));

    //input the target value before node to be added
    printf("Enter value before which to add node:\n");
    int before;
    scanf("%d",&before);

    //traversing to find the value
    ptr = start;
    while(ptr!=NULL && ptr->data != before) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr==NULL) {
        printf("Value not found.");
        free(new_node);
        return start;
    }
    new_node->next = ptr;
    if(preptr==NULL)
        start = new_node;
    else{
        preptr=>next = new_node;
    }
    return start;
}

//insert after a node
node *insert_after(node *start) {
    node *new_node,*preptr = NULL, *ptr;
    new_node = (node *)malloc(sizeof(node));
    if(new_node==NULL) {
        printf("Memory allocation failed");
        return start;
    }
    else {
        printf("Enter your data:\n");
        scanf("%d",&(new_node->data));
    }

    //input target value
    printf("Enter value after which to add node:\n");
    int after;
    scanf("%d",&after);

    ptr = start;
    if(ptr==NULL) {
        printf("LIST is empty.");
        return start;
    } else {
        while(ptr!=NULL && ptr->data != after) {
            preptr = ptr;
            ptr = ptr->next;
        }
    }
    if(ptr==NULL) {
        printf("After value not found:");
        return start;
    }else if(ptr->data == after) {
        if(ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
            preptr->next = new_node;
            new_node->next = ptr;
            return start;
        } else if(ptr->next == NULL) {
            ptr->next = new_node;
            new_node->next = NULL;
            return start;
        }
    }
}
