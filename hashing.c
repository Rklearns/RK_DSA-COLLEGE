#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node
{
    int data;
    struct node *next;
};

// Global hash table
int hashTable[TABLE_SIZE];           // For linear probing
struct node *chain[TABLE_SIZE];      // For chaining

// Function prototypes
void initHashTableLinear();
void initHashTableChaining();
int hashFunction(int key);
void insertLinear(int key);
void deleteLinear(int key);
int searchLinear(int key);
void displayLinear();
void insertChaining(int key);
void deleteChaining(int key);
int searchChaining(int key);
void displayChaining();

int main()
{
    int choice, key, searchResult;
    int mode;

    printf("Choose Hashing Technique:\n");
    printf("1. Linear Probing\n");
    printf("2. Chaining\n");
    printf("Enter your choice: ");
    scanf("%d", &mode);

    if (mode == 1)
    {
        initHashTableLinear();
    }
    else if (mode == 2)
    {
        initHashTableChaining();
    }
    else
    {
        printf("Invalid choice!\n");
        getchar();  // Replace getch()
        return 1;
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            if (mode == 1)
            {
                insertLinear(key);
            }
            else
            {
                insertChaining(key);
            }
            break;

        case 2:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            if (mode == 1)
            {
                deleteLinear(key);
            }
            else
            {
                deleteChaining(key);
            }
            break;

        case 3:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (mode == 1)
            {
                searchResult = searchLinear(key);
            }
            else
            {
                searchResult = searchChaining(key);
            }
            if (searchResult)
                printf("Key found in the hash table.\n");
            else
                printf("Key not found in the hash table.\n");
            break;

        case 4:
            if (mode == 1)
            {
                displayLinear();
            }
            else
            {
                displayChaining();
            }
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initHashTableLinear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void initHashTableChaining()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        chain[i] = NULL;
    }
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertLinear(int key)
{
    int index = hashFunction(key);
    int ogIndex = index;
    while (hashTable[index] != -1 && hashTable[index] != -2)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == ogIndex)
        {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

void deleteLinear(int key)
{
    int index = hashFunction(key);
    int ogIndex = index;
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            hashTable[index] = -2;
            printf("Deleted item %d from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == ogIndex)
            break;
    }
    printf("Key %d not found!\n", key);
}

int searchLinear(int key)
{
    int index = hashFunction(key);
    int ogIndex = index;
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;
        index = (index + 1) % TABLE_SIZE;
        if (index == ogIndex)
            break;
    }
    return 0;
}

void displayLinear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("Index %d: Empty\n", i);
        else if (hashTable[i] == -2)
            printf("Index %d: Deleted\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

void insertChaining(int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key;

    int index = hashFunction(key);
    newNode->next = chain[index];
    chain[index] = newNode;
    printf("Key %d inserted at index %d\n", key, index);
}

void deleteChaining(int key)
{
    int index = hashFunction(key);
    struct node *temp = chain[index];
    struct node *prev = NULL;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key %d not found!\n", key);
        return;
    }

    if (prev == NULL)
        chain[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Key %d deleted from index %d\n", key, index);
}

int searchChaining(int key)
{
    int index = hashFunction(key);
    struct node *temp = chain[index];

    while (temp != NULL)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void displayChaining()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct node *temp = chain[i];
        printf("Index %d: ", i);
        if (temp == NULL)
        {
            printf("Empty\n");
        }
        else
        {
            while (temp != NULL)
            {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}
