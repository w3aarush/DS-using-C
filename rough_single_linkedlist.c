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

// Create a linked list
node *create_ll(node *start) {
    node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1) {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

// Display the linked list
node *display(node *start) {
    node *ptr;
    ptr = start;
    if (ptr == NULL) {
        printf("\nList is empty.");
    } else {
        while (ptr != NULL) {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
    }
    return start;
}

// Insert at the beginning
node *insert_beg(node *start) {
    node *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

// Insert at the end
node *insert_end(node *start) {
    node *new_node, *ptr;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

// Insert before a given node
node *insert_before(node *start) {
    node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

// Insert after a given node
node *insert_after(node *start) {
    node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}

// Delete from the beginning
node *delete_beg(node *start) {
    node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

// Delete from the end
node *delete_end(node *start) {
    node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

// Delete a specific node
node *delete_node(node *start) {
    node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val) {
        start = delete_beg(start);
        return start;
    }
    while (ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

// Delete after a given node
node *delete_after(node *start) {
    node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    while (preptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

// Delete the entire list
node *delete_list(node *start) {
    node *ptr;
    if (start != NULL) {
        ptr = start;
        while (ptr != NULL) {
            printf("\n%d is to be deleted next", ptr->data);
            start = delete_beg(start);
            ptr = start;
        }
    }
    return start;
}

// Sort the linked list
node *sort_list(node *start) {
    node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}

node *insert_before(node *start) {
    node *new_node,*prev_ptr, *ptr;
    int before;
    new_node = NODE;
    printf("Enter your data:\n");
    scanf("%d",&(new_node->data));
    printf("Enter value before to be added:\n");
    scanf("%d",&before):
    ptr = start;
    while(ptr->data != data) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    new_node->next = ptr;
    prev_ptr->next = new_node;
    return start;
}

//chatgpt suggested improved version of insert_before
node *insert_before(node *start) {
    node *new_node, *prev_ptr = NULL, *ptr;
    int before;

    // Allocate memory for the new node
    new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }

    // Input data for the new node
    printf("Enter your data:\n");
    scanf("%d", &(new_node->data));

    // Input the target value
    printf("Enter value before which to add the new node:\n");
    scanf("%d", &before);

    // Traverse the list to find the target value
    ptr = start;
    while (ptr != NULL && ptr->data != before) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }

    // Handle case where the target value is not found
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", before);
        free(new_node); // Free the allocated memory since insertion failed
        return start;
    }

    // Insert the new node before the target node
    new_node->next = ptr;
    if (prev_ptr == NULL) {
        // Target is the first node, update start
        start = new_node;
    } else {
        prev_ptr->next = new_node;
    }

    return start;
}

//my updated code for "insert_before"
node insert_before(node *start) {
    node *new_node, *prev_ptr = NULL, *ptr;
    int before;
    new_node = NODE;
    if(new_node == NULL) {
        printf("Memory Allocation failed.");
        return start;
    } else {
        printf("Enter your data:\n");
        scanf("%d",&(new_node->data));
    }

    //input the target value
    printf("Enter value before which to add node\n");
    scanf("%d",&before);

    //traversing to find node
    ptr = start;
    while(ptr!=NULL && ptr->data != before) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Value not found.");
        free(new_node);
        return start;
    }

    new_node->next = ptr;
    if(prev_ptr==NULL) {
        start = new_node;
    } else {
        prev_ptr->next = new_node;
    }
    return start;
}

//my version of insert after
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
