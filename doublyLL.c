#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

struct node *createnode(int val) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void insertbefore();
void insertafter();
void display();
void delete();
void create();

int main() {
    int n;

    create();

    do {
        printf("Enter 1 for insertbefore\nEnter 2 for insertafter\nEnter 3 for delete\nEnter 4 for display\nEnter 5 for exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                insertbefore();
                break;
            case 2:
                insertafter();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the code....\n");
                break;
            default:
                printf("Enter appropriate value, please\n");
                break;
        }
    } while (n != 5);
    return 0;
}

void insertbefore() {
    int val, b;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node before which you have to insert: ");
    scanf("%d", &b);

    struct node *nn = createnode(val);
    struct node *temp = head;

    if (head == NULL) {
        // Empty list
        head = nn;
        return;
    }

    if (head->data == b) {
        // Insert before the head node
        nn->next = head;
        head->prev = nn;
        head = nn;
        return;
    }

    while (temp != NULL && temp->data != b) {
        temp = temp->next;
    }
     // Insert before the found node
    nn->next = temp;
    nn->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = nn;
    }
    temp->prev = nn;
}

void insertafter() {
    int val, a;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter node after which you have to insert: ");
    scanf("%d", &a);

    struct node *nn = createnode(val);
    struct node *temp = head;

    if (head == NULL) {
        // Empty list
        head = nn;
        return;
    }

    while (temp != NULL && temp->data != a) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", a);
        free(nn);
        return;
    }

    nn->next = temp->next;
    nn->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = nn;
    }
    temp->next = nn;
}

void delete() {
    int d;
    printf("Enter value to delete: ");
    scanf("%d", &d);

    struct node *temp = head;

    while (temp != NULL && temp->data != d) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", d);
        return;
    }

    if (temp == head) {
        // Deleting the head node
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void create() {
    struct node *temp = NULL;
    for (int i = 0; i < 5; i++) {
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &nn->data);

        nn->next = NULL;
        nn->prev = NULL;

        if (head == NULL) {
            head = nn;
            temp = nn;
        } else {
            temp->next = nn;
            nn->prev = temp;
            temp = nn;
        }
    }
}
