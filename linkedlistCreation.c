#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL, *newnode, *temp;
    int count = 0, choice;

    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return 1; // Exit with an error code
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Enter 1 for more entries and 0 for termination: ");
        scanf("%d", &choice);
        count++;
    } while (choice);

    temp = head; // Reset temp to the beginning of the list

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
